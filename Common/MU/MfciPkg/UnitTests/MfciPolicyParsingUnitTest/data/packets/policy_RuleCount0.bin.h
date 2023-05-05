/**
  Unit test data supporting the MfciPolicyParsingLib unit tests

  Copyright (c) Microsoft Corporation
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

CONST  UINT8  mBin_policy_RuleCount0[] = {
  0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x08, 0xf8, 0xe6, 0x5a, 0x84, 0x83, 0xb9, 0x4e, 0xa2, 0x3a,
  0x0c, 0xcc, 0x10, 0x93, 0xe3, 0xdd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0xef, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0xef, 0x58, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0xef, 0x8e, 0x00, 0x00, 0x00, 0x9c, 0x00, 0x00, 0x00, 0xb6, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0xef, 0xe0, 0x00, 0x00, 0x00, 0xee, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x10, 0xef, 0x0e, 0x01, 0x00, 0x00, 0x1c, 0x01, 0x00, 0x00, 0x2a, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x10, 0xef, 0x2e, 0x01, 0x00, 0x00, 0x3c, 0x01, 0x00, 0x00, 0x48, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x10, 0xef, 0x52, 0x01, 0x00, 0x00, 0x5c, 0x01, 0x00, 0x00, 0x6a, 0x01, 0x00, 0x00,
  0x0c, 0x00, 0x54, 0x00, 0x61, 0x00, 0x72, 0x00, 0x67, 0x00, 0x65, 0x00, 0x74, 0x00, 0x18, 0x00,
  0x4d, 0x00, 0x61, 0x00, 0x6e, 0x00, 0x75, 0x00, 0x66, 0x00, 0x61, 0x00, 0x63, 0x00, 0x74, 0x00,
  0x75, 0x00, 0x72, 0x00, 0x65, 0x00, 0x72, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x43, 0x00, 0x6f, 0x00,
  0x6e, 0x00, 0x74, 0x00, 0x6f, 0x00, 0x73, 0x00, 0x6f, 0x00, 0x20, 0x00, 0x43, 0x00, 0x6f, 0x00,
  0x6d, 0x00, 0x70, 0x00, 0x75, 0x00, 0x74, 0x00, 0x65, 0x00, 0x72, 0x00, 0x73, 0x00, 0x2c, 0x00,
  0x20, 0x00, 0x4c, 0x00, 0x4c, 0x00, 0x43, 0x00, 0x0c, 0x00, 0x54, 0x00, 0x61, 0x00, 0x72, 0x00,
  0x67, 0x00, 0x65, 0x00, 0x74, 0x00, 0x0e, 0x00, 0x50, 0x00, 0x72, 0x00, 0x6f, 0x00, 0x64, 0x00,
  0x75, 0x00, 0x63, 0x00, 0x74, 0x00, 0x00, 0x00, 0x14, 0x00, 0x4c, 0x00, 0x61, 0x00, 0x70, 0x00,
  0x74, 0x00, 0x6f, 0x00, 0x70, 0x00, 0x20, 0x00, 0x46, 0x00, 0x6f, 0x00, 0x6f, 0x00, 0x0c, 0x00,
  0x54, 0x00, 0x61, 0x00, 0x72, 0x00, 0x67, 0x00, 0x65, 0x00, 0x74, 0x00, 0x18, 0x00, 0x53, 0x00,
  0x65, 0x00, 0x72, 0x00, 0x69, 0x00, 0x61, 0x00, 0x6c, 0x00, 0x4e, 0x00, 0x75, 0x00, 0x6d, 0x00,
  0x62, 0x00, 0x65, 0x00, 0x72, 0x00, 0x00, 0x00, 0x26, 0x00, 0x46, 0x00, 0x30, 0x00, 0x30, 0x00,
  0x31, 0x00, 0x33, 0x00, 0x2d, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x32, 0x00, 0x34, 0x00,
  0x33, 0x00, 0x35, 0x00, 0x34, 0x00, 0x36, 0x00, 0x2d, 0x00, 0x58, 0x00, 0x30, 0x00, 0x32, 0x00,
  0x0c, 0x00, 0x54, 0x00, 0x61, 0x00, 0x72, 0x00, 0x67, 0x00, 0x65, 0x00, 0x74, 0x00, 0x0c, 0x00,
  0x4f, 0x00, 0x45, 0x00, 0x4d, 0x00, 0x5f, 0x00, 0x30, 0x00, 0x31, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x4f, 0x00, 0x44, 0x00, 0x4d, 0x00, 0x20, 0x00, 0x46, 0x00, 0x6f, 0x00, 0x6f, 0x00, 0x0c, 0x00,
  0x54, 0x00, 0x61, 0x00, 0x72, 0x00, 0x67, 0x00, 0x65, 0x00, 0x74, 0x00, 0x0c, 0x00, 0x4f, 0x00,
  0x45, 0x00, 0x4d, 0x00, 0x5f, 0x00, 0x30, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00,
  0x54, 0x00, 0x61, 0x00, 0x72, 0x00, 0x67, 0x00, 0x65, 0x00, 0x74, 0x00, 0x0a, 0x00, 0x4e, 0x00,
  0x6f, 0x00, 0x6e, 0x00, 0x63, 0x00, 0x65, 0x00, 0x05, 0x00, 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45,
  0x23, 0x01, 0x08, 0x00, 0x55, 0x00, 0x45, 0x00, 0x46, 0x00, 0x49, 0x00, 0x0c, 0x00, 0x50, 0x00,
  0x6f, 0x00, 0x6c, 0x00, 0x69, 0x00, 0x63, 0x00, 0x79, 0x00, 0x05, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00 };
