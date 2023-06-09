/** Header file for Button Services

  Copyright (C) Microsoft Corporation. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __MS_BUTTON_SERVICES_PROTOCOL_H__
#define __MS_BUTTON_SERVICES_PROTOCOL_H__

typedef struct _MS_BUTTON_SERVICES_PROTOCOL MS_BUTTON_SERVICES_PROTOCOL;

/**
Checks for the PreBoot key sequence of volume down button pressed then power button pressed

@param  This                  A pointer to the MS_BUTTON_SERVICES_PROTOCOL
                              instance.

@param  PreBootVolumeDownButtonThenPowerButton       TRUE if the button combo set else FALSE

@retval EFI_SUCCESS           The PreBoot key sequence could be checked and
                              PreBootVolumeDownButtonThenPowerButton is valid.

@retval EFI_INVALID_PARAMETER This error or any other error indicates something went wrong and
                              the value PreBootVolumeDownButtonThenPowerButton is invalid.

**/
typedef
EFI_STATUS
(EFIAPI *PRE_BOOT_VOLUME_DOWN_BUTTON_THEN_POWER_BUTTON_CHECK)(
  IN  MS_BUTTON_SERVICES_PROTOCOL *This,
  OUT BOOLEAN *PreBootVolumeDownButtonThenPowerButton
  );

/**
Checks for the PreBoot key sequence of volume up button pressed then power button pressed

@param  This                  A pointer to the MS_BUTTON_SERVICES_PROTOCOL
                              instance.

@param  PreBootVolumeUpButtonThenPowerButton       TRUE if the button combo set else FALSE

@retval EFI_SUCCESS           The PreBoot key sequence could be checked and
                              PreBootVolumeUpButtonThenPowerButton is valid.

@retval EFI_INVALID_PARAMETER This error or any other error indicates something went wrong
                              and the value PreBootVolumeUpButtonThenPowerButton is invalid.

**/
typedef
EFI_STATUS
(EFIAPI *PRE_BOOT_VOLUME_UP_BUTTON_THEN_POWER_BUTTON_CHECK)(
  IN  MS_BUTTON_SERVICES_PROTOCOL *This,
  OUT BOOLEAN *PreBootVolumeUpButtonThenPowerButton
  );

/**
Clears the PreBoot key sequence

@param  This                  A pointer to the MS_BUTTON_SERVICES_PROTOCOL
                              instance.

@retval EFI_SUCCESS           The PreBoot key sequence could be cleared

@retval EFI_INVALID_PARAMETER This error or any other error indicates something went wrong and
                              the button state may not be cleared

**/
typedef
EFI_STATUS
(EFIAPI *PRE_BOOT_CLEAR_VOLUME_BUTTON_STATE)(
  IN  MS_BUTTON_SERVICES_PROTOCOL *This
  );

///
/// Button services protocol that drivers can use and publish
///
struct _MS_BUTTON_SERVICES_PROTOCOL {
  PRE_BOOT_VOLUME_DOWN_BUTTON_THEN_POWER_BUTTON_CHECK    PreBootVolumeDownButtonThenPowerButtonCheck;
  PRE_BOOT_VOLUME_UP_BUTTON_THEN_POWER_BUTTON_CHECK      PreBootVolumeUpButtonThenPowerButtonCheck;
  PRE_BOOT_CLEAR_VOLUME_BUTTON_STATE                     PreBootClearVolumeButtonState;
};

extern EFI_GUID  gMsButtonServicesProtocolGuid;

#endif
