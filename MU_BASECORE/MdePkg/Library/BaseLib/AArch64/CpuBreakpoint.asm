;------------------------------------------------------------------------------
;
; CpuBreakpoint() for AArch64
;
; Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>
; Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
; Portions copyright (c) 2011 - 2013, ARM Ltd. All rights reserved.<BR>
; SPDX-License-Identifier: BSD-2-Clause-Patent
;
;------------------------------------------------------------------------------


  EXPORT CpuBreakpoint
; MS_CHANGE: change area name to |.text| and add an ALIGN directive
  AREA |.text|, ALIGN=2, CODE, READONLY

;/**
;  Generates a breakpoint on the CPU.
;
;  Generates a breakpoint on the CPU. The breakpoint must be implemented such
;  that code can resume normal execution after the breakpoint.
;
;**/
;VOID
;EFIAPI
;CpuBreakpoint (
;  VOID
;  );
;
CpuBreakpoint
    brk   0xf000    ; MS_CHANGE: Change svc to brk for KdDxe support
    ret

  END
