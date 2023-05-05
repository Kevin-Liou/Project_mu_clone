/** @file

  Platform Configuration C Struct Header File.

  Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent

  This file is automatically generated. Please do NOT modify !!!

**/

#ifndef __POLICY_DATA_STRUCT_GFX_H__
#define __POLICY_DATA_STRUCT_GFX_H__

#include <Library/VerifiedPolicy.h>

#pragma pack(1)

#define    PDATA_GFX_SIGNATURE            0x5846474154414450
#define    PDATA_GFX_MAJOR_VER            0x01
#define    PDATA_GFX_MINOR_VER            0x01


typedef struct {
  
  /* Power state of GFX port 0 */
  UINT16                      Power_State_Port_0;
  
  /* Power state of GFX port 1 */
  UINT16                      Power_State_Port_1;
  
  /* Flag to skip this controller or not */
  UINT16                      Skip_Check_0;
  
  /* Flag to skip this controller or not */
  UINT16                      Skip_Check_1;

} GFX_POLICY_DATA;

STATIC CONST VERIFIED_POLICY_HEADER POLICY_GFX_DESC = {
  .Signature     = PDATA_GFX_SIGNATURE,
  .MajorVersion  = PDATA_GFX_MAJOR_VER,
  .MinorVersion  = PDATA_GFX_MINOR_VER,
  .Size          = 0x08,
};

/* Get accessors for MIN_VER 0 */
inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Power_State_Port_0 (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  UINT16 Temp;
  if (((VERIFIED_POLICY_DESCRIPTOR*)_handle)->Size >= (OFFSET_OF(GFX_POLICY_DATA, Power_State_Port_0) + (sizeof (((GFX_POLICY_DATA*)0)->Power_State_Port_0)))) {
    Temp = ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Power_State_Port_0;
  } else {
    Temp = 0x1;
  }
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x20, FALSE);
  return Temp;
}


inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Power_State_Port_0_default (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x20, FALSE);
  return 0x1;
}

inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Power_State_Port_1 (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  UINT16 Temp;
  if (((VERIFIED_POLICY_DESCRIPTOR*)_handle)->Size >= (OFFSET_OF(GFX_POLICY_DATA, Power_State_Port_1) + (sizeof (((GFX_POLICY_DATA*)0)->Power_State_Port_1)))) {
    Temp = ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Power_State_Port_1;
  } else {
    Temp = 0x1;
  }
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x22, FALSE);
  return Temp;
}


inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Power_State_Port_1_default (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x22, FALSE);
  return 0x1;
}


/* Set accessors for MIN_VER 0 */
inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Power_State_Port_0 (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid,
  IN UINT16              val
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Power_State_Port_0 = val;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x20, TRUE);
}


inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Power_State_Port_0_default (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Power_State_Port_0 = 0x1;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x20, TRUE);
}

inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Power_State_Port_1 (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid,
  IN UINT16              val
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Power_State_Port_1 = val;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x22, TRUE);
}


inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Power_State_Port_1_default (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Power_State_Port_1 = 0x1;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x22, TRUE);
}


/* Get accessors for MIN_VER 1 */
inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Skip_Check_0 (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  UINT16 Temp;
  if (((VERIFIED_POLICY_DESCRIPTOR*)_handle)->Size >= (OFFSET_OF(GFX_POLICY_DATA, Skip_Check_0) + (sizeof (((GFX_POLICY_DATA*)0)->Skip_Check_0)))) {
    Temp = ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Skip_Check_0;
  } else {
    Temp = 0x0;
  }
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x24, FALSE);
  return Temp;
}


inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Skip_Check_0_default (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x24, FALSE);
  return 0x0;
}

inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Skip_Check_1 (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  UINT16 Temp;
  if (((VERIFIED_POLICY_DESCRIPTOR*)_handle)->Size >= (OFFSET_OF(GFX_POLICY_DATA, Skip_Check_1) + (sizeof (((GFX_POLICY_DATA*)0)->Skip_Check_1)))) {
    Temp = ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Skip_Check_1;
  } else {
    Temp = 0x0;
  }
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x26, FALSE);
  return Temp;
}


inline
STATIC
UINT16
EFIAPI
GET_GFX_POLICY_DATA_Skip_Check_1_default (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x26, FALSE);
  return 0x0;
}


/* Set accessors for MIN_VER 1 */
inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Skip_Check_0 (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid,
  IN UINT16              val
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Skip_Check_0 = val;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x24, TRUE);
}


inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Skip_Check_0_default (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Skip_Check_0 = 0x0;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x24, TRUE);
}

inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Skip_Check_1 (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid,
  IN UINT16              val
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Skip_Check_1 = val;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x26, TRUE);
}


inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_Skip_Check_1_default (
  IN EFI_HANDLE      _handle,
  IN EFI_GUID        *Guid
  ) {
  ((GFX_POLICY_DATA*)((UINTN)_handle + sizeof (VERIFIED_POLICY_DESCRIPTOR)))->Skip_Check_1 = 0x0;
  ReportVerifiedPolicyAccess (_handle, Guid, 0x2, 0x26, TRUE);
}


/* Set accessors for all fields of this structure */
inline
STATIC
VOID
EFIAPI
SET_GFX_POLICY_DATA_default (
  IN EFI_HANDLE  _handle,
  IN EFI_GUID    *Guid
  ) {
  if (((VERIFIED_POLICY_DESCRIPTOR*)_handle)->MinorVersion >= 0x0) {
    SET_GFX_POLICY_DATA_Power_State_Port_0_default (_handle, Guid);
    SET_GFX_POLICY_DATA_Power_State_Port_1_default (_handle, Guid);
  }
  if (((VERIFIED_POLICY_DESCRIPTOR*)_handle)->MinorVersion >= 0x1) {
    SET_GFX_POLICY_DATA_Skip_Check_0_default (_handle, Guid);
    SET_GFX_POLICY_DATA_Skip_Check_1_default (_handle, Guid);
  }
}

#pragma pack()

#endif
