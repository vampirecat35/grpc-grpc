/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/api/v2/auth/cert.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg.h"
#include "envoy/api/v2/auth/cert.upb.h"
#include "envoy/api/v2/core/base.upb.h"
#include "envoy/api/v2/core/config_source.upb.h"
#include "google/protobuf/any.upb.h"
#include "google/protobuf/struct.upb.h"
#include "google/protobuf/wrappers.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_msglayout_field envoy_api_v2_auth_TlsParameters__fields[4] = {
  {1, UPB_SIZE(0, 0), 0, 0, 14, 1},
  {2, UPB_SIZE(8, 8), 0, 0, 14, 1},
  {3, UPB_SIZE(16, 16), 0, 0, 9, 3},
  {4, UPB_SIZE(20, 24), 0, 0, 9, 3},
};

const upb_msglayout envoy_api_v2_auth_TlsParameters_msginit = {
  NULL,
  &envoy_api_v2_auth_TlsParameters__fields[0],
  UPB_SIZE(24, 32), 4, false,
};

static const upb_msglayout *const envoy_api_v2_auth_PrivateKeyProvider_submsgs[2] = {
  &google_protobuf_Any_msginit,
  &google_protobuf_Struct_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_PrivateKeyProvider__fields[3] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1},
  {2, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 1, 11, 1},
  {3, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 0, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_PrivateKeyProvider_msginit = {
  &envoy_api_v2_auth_PrivateKeyProvider_submsgs[0],
  &envoy_api_v2_auth_PrivateKeyProvider__fields[0],
  UPB_SIZE(16, 32), 3, false,
};

static const upb_msglayout *const envoy_api_v2_auth_TlsCertificate_submsgs[6] = {
  &envoy_api_v2_auth_PrivateKeyProvider_msginit,
  &envoy_api_v2_core_DataSource_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_TlsCertificate__fields[6] = {
  {1, UPB_SIZE(0, 0), 0, 1, 11, 1},
  {2, UPB_SIZE(4, 8), 0, 1, 11, 1},
  {3, UPB_SIZE(8, 16), 0, 1, 11, 1},
  {4, UPB_SIZE(12, 24), 0, 1, 11, 1},
  {5, UPB_SIZE(20, 40), 0, 1, 11, 3},
  {6, UPB_SIZE(16, 32), 0, 0, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_TlsCertificate_msginit = {
  &envoy_api_v2_auth_TlsCertificate_submsgs[0],
  &envoy_api_v2_auth_TlsCertificate__fields[0],
  UPB_SIZE(24, 48), 6, false,
};

static const upb_msglayout *const envoy_api_v2_auth_TlsSessionTicketKeys_submsgs[1] = {
  &envoy_api_v2_core_DataSource_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_TlsSessionTicketKeys__fields[1] = {
  {1, UPB_SIZE(0, 0), 0, 0, 11, 3},
};

const upb_msglayout envoy_api_v2_auth_TlsSessionTicketKeys_msginit = {
  &envoy_api_v2_auth_TlsSessionTicketKeys_submsgs[0],
  &envoy_api_v2_auth_TlsSessionTicketKeys__fields[0],
  UPB_SIZE(4, 8), 1, false,
};

static const upb_msglayout *const envoy_api_v2_auth_CertificateValidationContext_submsgs[4] = {
  &envoy_api_v2_core_DataSource_msginit,
  &google_protobuf_BoolValue_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_CertificateValidationContext__fields[8] = {
  {1, UPB_SIZE(4, 8), 0, 0, 11, 1},
  {2, UPB_SIZE(20, 40), 0, 0, 9, 3},
  {3, UPB_SIZE(24, 48), 0, 0, 9, 3},
  {4, UPB_SIZE(28, 56), 0, 0, 9, 3},
  {5, UPB_SIZE(8, 16), 0, 1, 11, 1},
  {6, UPB_SIZE(12, 24), 0, 1, 11, 1},
  {7, UPB_SIZE(16, 32), 0, 0, 11, 1},
  {8, UPB_SIZE(0, 0), 0, 0, 8, 1},
};

const upb_msglayout envoy_api_v2_auth_CertificateValidationContext_msginit = {
  &envoy_api_v2_auth_CertificateValidationContext_submsgs[0],
  &envoy_api_v2_auth_CertificateValidationContext__fields[0],
  UPB_SIZE(32, 64), 8, false,
};

static const upb_msglayout *const envoy_api_v2_auth_CommonTlsContext_submsgs[6] = {
  &envoy_api_v2_auth_CertificateValidationContext_msginit,
  &envoy_api_v2_auth_CommonTlsContext_CombinedCertificateValidationContext_msginit,
  &envoy_api_v2_auth_SdsSecretConfig_msginit,
  &envoy_api_v2_auth_TlsCertificate_msginit,
  &envoy_api_v2_auth_TlsParameters_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_CommonTlsContext__fields[7] = {
  {1, UPB_SIZE(0, 0), 0, 4, 11, 1},
  {2, UPB_SIZE(4, 8), 0, 3, 11, 3},
  {3, UPB_SIZE(16, 32), UPB_SIZE(-21, -41), 0, 11, 1},
  {4, UPB_SIZE(8, 16), 0, 0, 9, 3},
  {6, UPB_SIZE(12, 24), 0, 2, 11, 3},
  {7, UPB_SIZE(16, 32), UPB_SIZE(-21, -41), 2, 11, 1},
  {8, UPB_SIZE(16, 32), UPB_SIZE(-21, -41), 1, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_CommonTlsContext_msginit = {
  &envoy_api_v2_auth_CommonTlsContext_submsgs[0],
  &envoy_api_v2_auth_CommonTlsContext__fields[0],
  UPB_SIZE(24, 48), 7, false,
};

static const upb_msglayout *const envoy_api_v2_auth_CommonTlsContext_CombinedCertificateValidationContext_submsgs[2] = {
  &envoy_api_v2_auth_CertificateValidationContext_msginit,
  &envoy_api_v2_auth_SdsSecretConfig_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_CommonTlsContext_CombinedCertificateValidationContext__fields[2] = {
  {1, UPB_SIZE(0, 0), 0, 0, 11, 1},
  {2, UPB_SIZE(4, 8), 0, 1, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_CommonTlsContext_CombinedCertificateValidationContext_msginit = {
  &envoy_api_v2_auth_CommonTlsContext_CombinedCertificateValidationContext_submsgs[0],
  &envoy_api_v2_auth_CommonTlsContext_CombinedCertificateValidationContext__fields[0],
  UPB_SIZE(8, 16), 2, false,
};

static const upb_msglayout *const envoy_api_v2_auth_UpstreamTlsContext_submsgs[2] = {
  &envoy_api_v2_auth_CommonTlsContext_msginit,
  &google_protobuf_UInt32Value_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_UpstreamTlsContext__fields[4] = {
  {1, UPB_SIZE(12, 24), 0, 0, 11, 1},
  {2, UPB_SIZE(4, 8), 0, 0, 9, 1},
  {3, UPB_SIZE(0, 0), 0, 0, 8, 1},
  {4, UPB_SIZE(16, 32), 0, 1, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_UpstreamTlsContext_msginit = {
  &envoy_api_v2_auth_UpstreamTlsContext_submsgs[0],
  &envoy_api_v2_auth_UpstreamTlsContext__fields[0],
  UPB_SIZE(24, 48), 4, false,
};

static const upb_msglayout *const envoy_api_v2_auth_DownstreamTlsContext_submsgs[5] = {
  &envoy_api_v2_auth_CommonTlsContext_msginit,
  &envoy_api_v2_auth_SdsSecretConfig_msginit,
  &envoy_api_v2_auth_TlsSessionTicketKeys_msginit,
  &google_protobuf_BoolValue_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_DownstreamTlsContext__fields[5] = {
  {1, UPB_SIZE(0, 0), 0, 0, 11, 1},
  {2, UPB_SIZE(4, 8), 0, 3, 11, 1},
  {3, UPB_SIZE(8, 16), 0, 3, 11, 1},
  {4, UPB_SIZE(12, 24), UPB_SIZE(-17, -33), 2, 11, 1},
  {5, UPB_SIZE(12, 24), UPB_SIZE(-17, -33), 1, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_DownstreamTlsContext_msginit = {
  &envoy_api_v2_auth_DownstreamTlsContext_submsgs[0],
  &envoy_api_v2_auth_DownstreamTlsContext__fields[0],
  UPB_SIZE(20, 40), 5, false,
};

static const upb_msglayout *const envoy_api_v2_auth_SdsSecretConfig_submsgs[1] = {
  &envoy_api_v2_core_ConfigSource_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_SdsSecretConfig__fields[2] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1},
  {2, UPB_SIZE(8, 16), 0, 0, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_SdsSecretConfig_msginit = {
  &envoy_api_v2_auth_SdsSecretConfig_submsgs[0],
  &envoy_api_v2_auth_SdsSecretConfig__fields[0],
  UPB_SIZE(16, 32), 2, false,
};

static const upb_msglayout *const envoy_api_v2_auth_Secret_submsgs[3] = {
  &envoy_api_v2_auth_CertificateValidationContext_msginit,
  &envoy_api_v2_auth_TlsCertificate_msginit,
  &envoy_api_v2_auth_TlsSessionTicketKeys_msginit,
};

static const upb_msglayout_field envoy_api_v2_auth_Secret__fields[4] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, 1},
  {2, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 1, 11, 1},
  {3, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 2, 11, 1},
  {4, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 0, 11, 1},
};

const upb_msglayout envoy_api_v2_auth_Secret_msginit = {
  &envoy_api_v2_auth_Secret_submsgs[0],
  &envoy_api_v2_auth_Secret__fields[0],
  UPB_SIZE(16, 32), 4, false,
};

#include "upb/port_undef.inc"

