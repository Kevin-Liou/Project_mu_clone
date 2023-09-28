/** @file
This GraphicsConsoleHelper is only intended to be used by BDS to configure
the console mode / graphic mode

Copyright (C) Microsoft Corporation. All rights reserved.
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Uefi.h>
#include <Protocol/GraphicsOutput.h>
#include <Protocol/SimpleTextOut.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/DebugLib.h>
#include <Library/GraphicsConsoleHelperLib.h>

//
// Platform defined native resolution.
//
static UINT32  mNativeHorizontalResolution;
static UINT32  mNativeVerticalResolution;
static UINT32  mNativeTextModeColumn;
static UINT32  mNativeTextModeRow;

//
// Mode for PXE booting and other places that VGA is necessary.
//
static UINT32  mVgaTextModeColumn;
static UINT32  mVgaTextModeRow;
static UINT32  mVgaHorizontalResolution;
static UINT32  mVgaVerticalResolution;

static BOOLEAN  mModeTableInitialized = FALSE;

/**
 * InitializeModeTable -
 * @param
 *
 * @return VOID
 */
static VOID
InitializeModeTable (
  IN EFI_GRAPHICS_OUTPUT_PROTOCOL  *Gop
  )
{
  EFI_STATUS                            Status = EFI_SUCCESS;
  EFI_GRAPHICS_OUTPUT_MODE_INFORMATION  *Info  = NULL;
  UINT32                                Indx;
  UINT32                                MaxHRes = 800;
  UINTN                                 Size    = 0;

  DEBUG ((DEBUG_ERROR, "%a 111\n", __FUNCTION__));
  if (Gop == NULL) {
    DEBUG ((DEBUG_ERROR, "%a 222\n", __FUNCTION__));
    return;
  }

  if (!mModeTableInitialized) {
    DEBUG ((DEBUG_ERROR, "%a 333\n", __FUNCTION__));
    mVgaTextModeColumn       = 100; // Standard VGA resolution with
    mVgaTextModeRow          = 31;  // EFI standard glyphs
    mVgaHorizontalResolution = 800;
    mVgaVerticalResolution   = 600;

    mNativeTextModeColumn       = 100; // Default to VGA resolution
    mNativeTextModeRow          = 31;  // but set to highest native resolution.
    mNativeHorizontalResolution = 800;
    mNativeVerticalResolution   = 600;

    if (Gop != NULL) {
      DEBUG ((DEBUG_ERROR, "%a 444\n", __FUNCTION__));
      for (Indx = 0; Indx < Gop->Mode->MaxMode; Indx++) {
        Status = Gop->QueryMode (Gop, Indx, &Size, &Info);
        if (!EFI_ERROR (Status)) {
          if (MaxHRes < Info->HorizontalResolution) {
            DEBUG ((DEBUG_ERROR, "%a 555\n", __FUNCTION__));
            mNativeHorizontalResolution = Info->HorizontalResolution;
            mNativeVerticalResolution   = Info->VerticalResolution;
            MaxHRes                     = Info->HorizontalResolution;
          }

          DEBUG ((DEBUG_INFO, "Mode Info for Mode %d\n", Indx));
          DEBUG ((DEBUG_INFO, "HRes: %d VRes: %d PPScanLine: %d \n", Info->HorizontalResolution, Info->VerticalResolution, Info->PixelsPerScanLine));
          FreePool (Info);

          mModeTableInitialized = TRUE;
        }
      }

      mNativeTextModeColumn = mNativeHorizontalResolution / EFI_GLYPH_WIDTH;
      DEBUG ((DEBUG_ERROR, "%a mNativeTextModeColumn = %d\n", __FUNCTION__, mNativeTextModeColumn));
      mNativeTextModeRow    = mNativeVerticalResolution / EFI_GLYPH_HEIGHT;
      DEBUG ((DEBUG_ERROR, "%a mNativeTextModeRow = %d\n", __FUNCTION__, mNativeTextModeRow));
    }
  }
}

EFI_STATUS
EFIAPI
SetGraphicsConsoleMode (
  GRAPHICS_CONSOLE_MODE  Mode
  )
{
  EFI_GRAPHICS_OUTPUT_PROTOCOL          *GraphicsOutput;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL       *SimpleTextOut;
  UINTN                                 SizeOfInfo;
  EFI_GRAPHICS_OUTPUT_MODE_INFORMATION  *Info;
  UINT32                                MaxGopMode;
  UINT32                                MaxTextMode;
  UINT32                                ModeNumber;
  UINT32                                NewHorizontalResolution;
  UINT32                                NewVerticalResolution;
  UINT32                                NewColumns;
  UINT32                                NewRows;
  UINTN                                 HandleCount;
  EFI_HANDLE                            *HandleBuffer;
  EFI_STATUS                            Status;
  UINTN                                 Index;
  UINTN                                 CurrentColumn;
  UINTN                                 CurrentRow;

  //
  // Get current video resolution and text mode
  //
  DEBUG ((DEBUG_ERROR, "%a 111\n", __FUNCTION__));
  Status = gBS->HandleProtocol (
                  gST->ConsoleOutHandle,
                  &gEfiGraphicsOutputProtocolGuid,
                  (VOID **)&GraphicsOutput
                  );
  DEBUG ((DEBUG_ERROR, "%a gBS->HandleProtocol:&gEfiGraphicsOutputProtocolGuid status:%r\n", __FUNCTION__, Status));
  if (EFI_ERROR (Status)) {
    GraphicsOutput = NULL;
    Status         = gBS->LocateProtocol (&gEfiGraphicsOutputProtocolGuid, NULL, (VOID **)&GraphicsOutput);
  }

  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->Version = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->Version));
  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->HorizontalResolution = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->HorizontalResolution));
  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->VerticalResolution = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->VerticalResolution));
  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->PixelInformation = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->PixelInformation));
  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->PixelsPerScanLine = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->PixelsPerScanLine));
  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->MaxMode = %d\n", __FUNCTION__, GraphicsOutput->Mode->MaxMode));
  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Mode = %d\n", __FUNCTION__, GraphicsOutput->Mode->Mode));
  DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->SizeOfInfo = %d\n", __FUNCTION__, GraphicsOutput->Mode->SizeOfInfo));

  if (EFI_ERROR (Status) || (GraphicsOutput == NULL)) {
    return EFI_UNSUPPORTED;
  }
  DEBUG ((DEBUG_ERROR, "%a 222\n", __FUNCTION__));
  Status = gBS->HandleProtocol (
                  gST->ConsoleOutHandle,
                  &gEfiSimpleTextOutProtocolGuid,
                  (VOID **)&SimpleTextOut
                  );
  DEBUG ((DEBUG_ERROR, "%a gBS->HandleProtocol:&gEfiSimpleTextOutProtocolGuid status:%r\n", __FUNCTION__, Status));
  if (EFI_ERROR (Status)) {
    return EFI_UNSUPPORTED;
  }

  DEBUG ((DEBUG_ERROR, "%a 333\n", __FUNCTION__));
  InitializeModeTable (GraphicsOutput);
  MaxGopMode  = 0;
  MaxTextMode = 0;

  DEBUG ((DEBUG_ERROR, "%a 444\n", __FUNCTION__));
  DEBUG ((DEBUG_ERROR, "%a Mode = %x\n", __FUNCTION__, Mode));
  if (Mode == GCM_LOW_RES) {
    //
    // The required resolution and text mode is setup mode.
    //
    DEBUG ((DEBUG_ERROR, "%a Mode = GCM_LOW_RES\n", __FUNCTION__));
    NewHorizontalResolution = mVgaHorizontalResolution;
    NewVerticalResolution   = mVgaVerticalResolution;
    NewColumns              = mVgaTextModeColumn;
    NewRows                 = mVgaTextModeRow;
  } else if (Mode == GCM_NATIVE_RES) {
    //
    // The required resolution and text mode is boot mode.
    //
    DEBUG ((DEBUG_ERROR, "%a Mode = GCM_NATIVE_RES\n", __FUNCTION__));
    NewHorizontalResolution = mNativeHorizontalResolution;
    NewVerticalResolution   = mNativeVerticalResolution;
    NewColumns              = mNativeTextModeColumn;
    NewRows                 = mNativeTextModeRow;
  } else {
    DEBUG ((DEBUG_ERROR, "%a - Unsupported Graphics Console Request Mode 0x%X\n", __FUNCTION__, Mode));
    Status = EFI_UNSUPPORTED;
    goto Exit;
  }

  DEBUG ((DEBUG_ERROR, "%a NewHorizontalResolution = %d\n", __FUNCTION__, NewHorizontalResolution));
  DEBUG ((DEBUG_ERROR, "%a NewVerticalResolution = %d\n", __FUNCTION__, NewVerticalResolution));
  DEBUG ((DEBUG_ERROR, "%a NewColumns = %d\n", __FUNCTION__, NewColumns));
  DEBUG ((DEBUG_ERROR, "%a NewRows = %d\n", __FUNCTION__, NewRows));

  DEBUG ((DEBUG_ERROR, "%a 555\n", __FUNCTION__));
  MaxGopMode  = GraphicsOutput->Mode->MaxMode;
  MaxTextMode = SimpleTextOut->Mode->MaxMode;

  DEBUG ((DEBUG_ERROR, "%a MaxGopMode = %d\n", __FUNCTION__, MaxGopMode));
  DEBUG ((DEBUG_ERROR, "%a MaxTextMode = %d\n", __FUNCTION__, MaxTextMode));

  //
  // 1. If current video resolution is same with required video resolution,
  //    video resolution need not be changed.
  //    1.1. If current text mode is same with required text mode, text mode need not be changed.
  //    1.2. If current text mode is different from required text mode, text mode need be changed.
  // 2. If current video resolution is different from required video resolution, we need restart whole console drivers.
  //
  DEBUG ((DEBUG_ERROR, "%a aaa\n", __FUNCTION__));
  for (ModeNumber = 0; ModeNumber < MaxGopMode; ModeNumber++) {
    Status = GraphicsOutput->QueryMode (
                               GraphicsOutput,
                               ModeNumber,
                               &SizeOfInfo,
                               &Info
                               );
    DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->QueryMode:GraphicsOutput status:%r\n", __FUNCTION__, Status));

    DEBUG ((DEBUG_ERROR, "%a Info->HorizontalResolution = %d\n", __FUNCTION__, Info->HorizontalResolution));
    DEBUG ((DEBUG_ERROR, "%a Info->VerticalResolution = %d\n", __FUNCTION__, Info->VerticalResolution));

    DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->HorizontalResolution = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->HorizontalResolution));
    DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->VerticalResolution = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->VerticalResolution));

    if (!EFI_ERROR (Status)) {
      if ((Info->HorizontalResolution == NewHorizontalResolution) &&
          (Info->VerticalResolution == NewVerticalResolution))
      {
        if ((GraphicsOutput->Mode->Info->HorizontalResolution == NewHorizontalResolution) &&
            (GraphicsOutput->Mode->Info->VerticalResolution == NewVerticalResolution))
        {
          //
          // Current resolution is same with required resolution, check if text mode need be set
          //
          DEBUG ((DEBUG_ERROR, "%a a001\n", __FUNCTION__));
          Status = SimpleTextOut->QueryMode (SimpleTextOut, SimpleTextOut->Mode->Mode, &CurrentColumn, &CurrentRow);
          ASSERT_EFI_ERROR (Status);
          if ((CurrentColumn == NewColumns) && (CurrentRow == NewRows)) {
            //
            // If current text mode is same with required text mode. Do nothing
            //
            DEBUG ((DEBUG_ERROR, "%a a002\n", __FUNCTION__));
            FreePool (Info);
            Status = EFI_SUCCESS;
            goto Exit;
          } else {
            //
            // If current text mode is different from required text mode.  Set new video mode
            //
            DEBUG ((DEBUG_ERROR, "%a a003\n", __FUNCTION__));
            for (Index = 0; Index < MaxTextMode; Index++) {
              Status = SimpleTextOut->QueryMode (SimpleTextOut, Index, &CurrentColumn, &CurrentRow);
              if (!EFI_ERROR (Status)) {
                if ((CurrentColumn == NewColumns) && (CurrentRow == NewRows)) {
                  //
                  // Required text mode is supported, set it.
                  //
                  DEBUG ((DEBUG_ERROR, "%a a004\n", __FUNCTION__));
                  Status = SimpleTextOut->SetMode (SimpleTextOut, Index);
                  ASSERT_EFI_ERROR (Status);
                  //
                  // Update text mode PCD.
                  //
                  Status = PcdSet32S (PcdConOutColumn, mVgaTextModeColumn);
                  ASSERT_EFI_ERROR (Status);
                  Status = PcdSet32S (PcdConOutRow, mVgaTextModeRow);
                  ASSERT_EFI_ERROR (Status);

                  FreePool (Info);
                  goto Exit;
                }
              }
            }

            if (Index == MaxTextMode) {
              //
              // If requrired text mode is not supported, return error.
              //
              DEBUG ((DEBUG_ERROR, "%a a005\n", __FUNCTION__));
              FreePool (Info);
              Status = EFI_UNSUPPORTED;
              goto Exit;
            }
          }
        } else {
          //
          // If current video resolution is not same with the new one, set new video resolution.
          // In this case, the driver which produces simple text out need be restarted.
          //
          DEBUG ((DEBUG_ERROR, "%a a006\n", __FUNCTION__));
          Status = GraphicsOutput->SetMode (GraphicsOutput, ModeNumber);
          DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->SetMode status:%r\n", __FUNCTION__, Status));
          DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->HorizontalResolution = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->HorizontalResolution));
          DEBUG ((DEBUG_ERROR, "%a GraphicsOutput->Mode->Info->VerticalResolution = %d\n", __FUNCTION__, GraphicsOutput->Mode->Info->VerticalResolution));
          if (!EFI_ERROR (Status)) {
            FreePool (Info);
            break;
          }
        }
      }
      DEBUG ((DEBUG_ERROR, "%a a007\n", __FUNCTION__));
      FreePool (Info);
    }
  }
  DEBUG ((DEBUG_ERROR, "%a 777\n", __FUNCTION__));

  if (ModeNumber == MaxGopMode) {
    //
    // If the resolution is not supported, return error.
    //
    Status = EFI_UNSUPPORTED;
    goto Exit;
  }
  DEBUG ((DEBUG_ERROR, "%a 888\n", __FUNCTION__));
  //
  // Set PCD to Inform GraphicsConsole to change video resolution.
  // Set PCD to Inform Consplitter to change text mode.
  //
  Status = PcdSet32S (PcdVideoHorizontalResolution, NewHorizontalResolution);
  ASSERT_EFI_ERROR (Status);
  Status = PcdSet32S (PcdVideoVerticalResolution, NewVerticalResolution);
  ASSERT_EFI_ERROR (Status);
  Status = PcdSet32S (PcdConOutColumn, NewColumns);
  ASSERT_EFI_ERROR (Status);
  Status = PcdSet32S (PcdConOutRow, NewRows);
  ASSERT_EFI_ERROR (Status);
  DEBUG ((DEBUG_ERROR, "%a 999\n", __FUNCTION__));
  //
  // Video mode is changed, so restart graphics console driver and higher level driver.
  // Reconnect graphics console driver and higher level driver.
  // Locate all the handles with GOP protocol and reconnect it.
  //
  Status = gBS->LocateHandleBuffer (
                  ByProtocol,
                  &gEfiSimpleTextOutProtocolGuid,
                  NULL,
                  &HandleCount,
                  &HandleBuffer
                  );
  DEBUG ((DEBUG_ERROR, "%a gBS->LocateHandleBuffer:&gEfiSimpleTextOutProtocolGuid status:%r\n", __FUNCTION__, Status));
  if (HandleBuffer != NULL) {
    DEBUG ((DEBUG_ERROR, "%a HandleBuffer != NULL\n", __FUNCTION__));
    DEBUG ((DEBUG_ERROR, "%a HandleCount = %d\n", __FUNCTION__, HandleCount));
  }
  if (!EFI_ERROR (Status)) {
    for (Index = 0; Index < HandleCount; Index++) {
      gBS->DisconnectController (HandleBuffer[Index], NULL, NULL);
    }

    for (Index = 0; Index < HandleCount; Index++) {
      gBS->ConnectController (HandleBuffer[Index], NULL, NULL, TRUE);
    }
    DEBUG ((DEBUG_ERROR, "%a ddd\n", __FUNCTION__));
    if (HandleBuffer != NULL) {
      FreePool (HandleBuffer);
    }
  }

  Status = EFI_SUCCESS;
  DEBUG ((DEBUG_ERROR, "%a 000\n", __FUNCTION__));

Exit:
  return Status;
}
