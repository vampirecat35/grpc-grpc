/*
 *
 * Copyright 2016, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "src/core/lib/iomgr/unix_sockets_posix.h"

#ifdef GPR_HAVE_UNIX_SOCKET

#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>

#include <grpc/support/alloc.h>
#include <grpc/support/log.h>

void grpc_create_socketpair_if_unix(int sv[2]) {
  GPR_ASSERT(socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == 0);
}

grpc_resolved_addresses *grpc_resolve_unix_domain_address(const char *name) {
  struct sockaddr_un *un;

  grpc_resolved_addresses *addrs = gpr_malloc(sizeof(grpc_resolved_addresses));
  addrs->naddrs = 1;
  addrs->addrs = gpr_malloc(sizeof(grpc_resolved_address));
  un = (struct sockaddr_un *)addrs->addrs->addr;
  un->sun_family = AF_UNIX;
  strcpy(un->sun_path, name);
  addrs->addrs->len = strlen(un->sun_path) + sizeof(un->sun_family) + 1;

  // Special handling for Android Studio Profilers.
  // Supports Unix abstract domain socket if the input address is a
  // unix socket name and the socket name starts with '@'. For example,
  // "unix:@AbstractSocketName". The name of the abstract socket doesn't
  // include the '@' in "unix:@".
  //
  // Note the input |addr_len| will be reduce by 1. When GRPC handles a Unix
  // socket, it assumes it is a pathname socket that "can be bound to a
  // null-terminated filesystem pathname using bind(2)". Therefore, the
  // length includes the null byte at the end of the sun_path. But for
  // abstract sockets null bytes "have no special significance". We choose
  // not to include the terminating null byte to make the socket name easy to
  // see and type in shell (e.g., adb forward). See more details about lengths
  // at http://man7.org/linux/man-pages/man7/unix.7.html .
  if (un->sun_path[0] == '@') {
    un->sun_path[0] = '\0';
    addrs->addrs->len--;
  }
  return addrs;
}

int grpc_is_unix_socket(const struct sockaddr *addr) {
  return addr->sa_family == AF_UNIX;
}

void grpc_unlink_if_unix_domain_socket(const struct sockaddr *addr) {
  if (addr->sa_family != AF_UNIX) {
    return;
  }
  struct sockaddr_un *un = (struct sockaddr_un *)addr;
  struct stat st;

  if (stat(un->sun_path, &st) == 0 && (st.st_mode & S_IFMT) == S_IFSOCK) {
    unlink(un->sun_path);
  }
}

char *grpc_sockaddr_to_uri_unix_if_possible(const struct sockaddr *addr) {
  if (addr->sa_family != AF_UNIX) {
    return NULL;
  }

  char *result;
  gpr_asprintf(&result, "unix:%s", ((struct sockaddr_un *)addr)->sun_path);
  return result;
}

#endif
