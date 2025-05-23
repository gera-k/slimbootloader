/** @file
  Register names for CPU registers

  <b>Conventions</b>
  - Definitions beginning with "MSR_" are MSRs
  - Definitions beginning with "R_" are registers
  - Definitions beginning with "B_" are bits within registers
  - Definitions beginning with "V_" are meaningful values of bits within the registers
  - Definitions beginning with "S_" are register sizes
  - Definitions beginning with "N_" are the bit position

  Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#ifndef _CPU_REGS_H_
#define _CPU_REGS_H_


/**
  Package. Maximum Ratio Limit of Turbo Mode by Core Groups (RW) Specifies
  Maximum Ratio Limit for each Core Group. Max ratio for groups with more
  cores must decrease monotonically. For groups with less than 4 cores, the
  max ratio must be 32 or less. For groups with 4-5 cores, the max ratio must
  be 22 or less. For groups with more than 5 cores, the max ratio must be 16
  or less..

  @param  ECX  MSR_TURBO_RATIO_LIMIT (0x000001AD)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_TURBO_RATIO_LIMIT_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_TURBO_RATIO_LIMIT_REGISTER.

  <b>Example usage</b>
  @code
  MSR_TURBO_RATIO_LIMIT_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_TURBO_RATIO_LIMIT);
  AsmWriteMsr64 (MSR_TURBO_RATIO_LIMIT, Msr.Uint64);
  @endcode
**/
#define MSR_TURBO_RATIO_LIMIT           0x000001AD

/**
  MSR information returned for MSR index #MSR_TURBO_RATIO_LIMIT
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    ///
    /// [Bits 7:0] Package. Maximum Ratio Limit for Active cores in MaxTurbo 1Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to MaxTurbo 1Core threshold.
    ///
    UINT32  MaxTurbo1Core:8;
    ///
    /// [Bits 15:8] Package. Maximum Ratio Limit for Active cores in MaxTurbo 2Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to MaxTurbo 2Core threshold and greater than MaxTurbo 1Core threshold.
    ///
    UINT32  MaxTurbo2Core:8;
    ///
    /// [Bits 23:16] Package. Maximum Ratio Limit for Active cores in MaxTurbo 3Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to MaxTurbo 3Core threshold and greater than MaxTurbo 2Core threshold.
    ///
    UINT32  MaxTurbo3Core:8;
    ///
    /// [Bits 31:24] Package. Maximum Ratio Limit for Active cores in MaxTurbo 4Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to MaxTurbo 4Core threshold and greater than MaxTurbo 3Core threshold.
    ///
    UINT32  MaxTurbo4Core:8;
    ///
    /// [Bits 39:32] Package. Maximum Ratio Limit for Active cores in MaxTurbo 5Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to MaxTurbo 5Core and greater than MaxTurbo 4Core threshold.
    ///
    UINT32  MaxTurbo5Core:8;
    ///
    /// [Bits 47:40] Package. Maximum Ratio Limit for Active cores in MaxTurbo 6Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to MaxTurbo 6Core threshold and greater than MaxTurbo 5Core threshold.
    ///
    UINT32  MaxTurbo6Core:8;
    ///
    /// [Bits 55:48] Package. Maximum Ratio Limit for Active cores in MaxTurbo 7Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to Group 7 threshold and greater than MaxTurbo 6Core threshold.
    ///
    UINT32  MaxTurbo7Core:8;
    ///
    /// [Bits 63:56] Package. Maximum Ratio Limit for Active cores in MaxTurbo 8Core
    /// Maximum turbo ratio limit when number of active cores is less or equal
    /// to MaxTurbo 8Core threshold and greater than MaxTurbo 7Core threshold.
    ///
    UINT32  MaxTurbo8Core:8;
  } Bits;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_TURBO_RATIO_LIMIT_REGISTER;

/**
Special Chipset Usage MSR
**/


#ifndef CPU_FEATURE_DISABLE
#define CPU_FEATURE_DISABLE  0
#endif
#ifndef CPU_FEATURE_ENABLE
#define CPU_FEATURE_ENABLE   1
#endif

//
// Processor Definitions
//
#define CPUID_FULL_STEPPING                        0x0000000F
#define CPUID_FULL_FAMILY_MODEL                    0x0FFF0FF0

typedef UINT32       CPU_FAMILY;

///
/// Enums for CPU Stepping IDs
///
typedef enum {
  ///
  /// MeteorLake DT Steppings
  ///
  EnumMtlSA0 = 0,

  ///
  /// MeteorLake Debug Steppings
  ///
  EnumMtlNA0 = 0,

  ///
  /// MeteorLake Mobile Steppings
  ///
  EnumMtlPMA0 = 0,
  ///
  /// Max Stepping
  ///
  EnumCpuSteppingMax  = CPUID_FULL_STEPPING
} CPU_STEPPING;

///
/// Enums for CPU SKU IDs
///
typedef enum {
  EnumCpuUlt        = 0,
  EnumCpuTrad,
  EnumCpuUlx,
  EnumCpuHalo,
  EnumCpuUnknown
} CPU_SKU;

//ADL CPU REGS
#define MSR_PLATFORM_INFO                                             0x000000CE
#define MSR_FLEX_RATIO                                                0x00000194
#define MSR_TEMPERATURE_TARGET                                        0x000001A2
#define MSR_TURBO_RATIO_LIMIT                                         0x000001AD
#define MSR_PACKAGE_POWER_SKU_UNIT                                    0x606
#define MSR_PACKAGE_POWER_LIMIT                                       0x610
#define MSR_PACKAGE_POWER_SKU                                         0x614


///
/// Local APIC definitions
///
//
// Processor Definitions
//
#define CPUID_FULL_STEPPING                         0x0000000F
#define CPUID_FULL_FAMILY_MODEL                     0x0FFF0FF0
#define CPUID_FULL_FAMILY_MODEL_ALDERLAKE_DT_HALO   0x00090670
#define CPUID_FULL_FAMILY_MODEL_METEORLAKE_MOBILE   0x000A06A0
#define CPUID_FULL_FAMILY_MODEL_METEORLAKE_DT_HALO  0x000A06C0

/**
  This 'flexible boot' register is written by BIOS in order to modify the maximum non-turbo ratio on the next reset.
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 OcExtraVoltage : 8;

                            /* Bits[7:0], Access Type=RWS, default=0x00000000*/

                            /*
                               Depracated. Extra voltage to be used for
                               Overclocking.The voltage is defined in units of
                               1/256 Volts.
                            */
    UINT32 FlexRatio : 8;

                            /* Bits[15:8], Access Type=RWS, default=0x00000000*/

                            /*
                               When enabled by the ENABLE bit, the value in
                               this field sets the maximum non-turbo ratio. If
                               this value is greater than the maximum ratio set
                               by hardware, this field is silently ignored. The
                               override value applies on the next reset and not
                               immediately.
                            */
    UINT32 Enable : 1;

                            /* Bits[16:16], Access Type=RWS, default=0x00000000*/

                            /*
                               When set to 1, indicates that the value
                               programmed in FLEX_RATIO field will be used to
                               override the maximum non-turbo ratio on next
                               reboot. When this bit is set to zero, all writes
                               to FLEX_RATIO field are silently ignored.
                            */
    UINT32 OcBins : 3;

                            /* Bits[19:17], Access Type=RW_L, default=0x00000000*/

                            /*
                               [p]If overclocking is enabled, this field
                               contains how many bins of Core ratio
                               overclocking are supported.[/p] [p]The encoding
                               is:[/p] [list] [*]0: No Core overclocking is
                               supported [*]1-6: Max 1-6 bins of Core ratio
                               overclocking is supported. [*]7: Unlimited
                               [/list] [p]If overclocking is disabled then this
                               field should be ignored.[/p] [p]Overclocking
                               bins imply programming the TURBO_RATIO_LIMIT MSR
                               above its hardware default value.[/p]
                               Overclocking enabled/disabled can be checked in
                               CAPID0_B_0_0_0_PCI.OC_ENABLED.
                            */
    UINT32 OcLock : 1;

                            /* Bits[20:20], Access Type=RW1S, default=0x00000000*/

                            /*
                               If set, all writes to overclocking limits are
                               disabled. Anyway modifications to overclocking
                               limits prior to setting this lock bit are
                               maintained. This field may only be set by
                               software and it is cleared by hardware only on
                               reset.
                            */
    UINT32 Rsvd21 : 11;

                            /* Bits[31:21], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 Rsvd32 : 32;

                            /* Bits[63:32], Access Type=RO, default=None*/

                            /* Reserved */

  } Bits;

  UINT32 Uint32;
  UINT64 Uint64;

} MSR_FLEX_RATIO_REGISTER;

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 TccOffsetTimeWindow : 7;

                            /* Bits[6:0], Access Type=RO_V, default=0x00000000*/

                            /* Describes the RATL averaging time window */
    UINT32 TccOffsetClampingBit : 1;

                            /* Bits[7:7], Access Type=RO_V, default=0x00000000*/

                            /* When enabled will allow RATL throttling below P1 */
    UINT32 FanTempTargetOfst : 8;

                            /* Bits[15:8], Access Type=RW_L, default=0x00000000*/

                            /*
                               Fan Temperature Target Offset (a.k.a. T-Control)
                               indicates the relative offset from the Thermal
                               Monitor Trip Temperature at which fans should be
                               engaged.
                            */
    UINT32 RefTemp : 8;

                            /* Bits[23:16], Access Type=RW_L, default=0x00000000*/

                            /*
                               This field indicates the maximum junction
                               temperature, also referred to as the Throttle
                               Temperature, TCC Activation Temperature or
                               Prochot Temperature. This is the temperature at
                               which the Adaptive Thermal Monitor is activated.
                            */
    UINT32 TjMaxTccOffset : 6;

                            /* Bits[29:24], Access Type=RO_V, default=0x00000000*/

                            /*
                               Temperature offset in degrees (C) from the TJ
                               Max. Used for throttling temperature. Will not
                               impact temperature reading. If offset is allowed
                               and set - the throttle will occur and reported
                               at lower then Tj_max.
                            */
    UINT32 Rsvd30 : 1;

                            /* Bits[30:30], Access Type=RO, default=None*/

                            /* Reserved */
    UINT32 Locked : 1;

                            /* Bits[31:31], Access Type=RW_KL, default=0x00000000*/

                            /*
                               When set, this entire register becomes read-
                               only.
                            */

  } Bits;

  UINT32 Uint32;
  UINT64 Uint64;

} MSR_TEMPERATURE_TARGET_REGISTER;

/**
  This MSR indicates the factory configured values for active core ranges (1-8) and not active cores. Each field in MSR_TURBO_RATIO_LIMIT_CORES (MSR 1AEh) denotes
  the active core count.
  Software can configure these limits when PLATFORM_INFO MSR 0CEh[28]==1.
  Instead of specifying a ratio for each active core count (legacy behavior), active core counts with an identical turbo ratio limit belong to a single active core range that act as a turbo limit for that entire range of active cores.
  Example: configure turbo ratio limits for a 10-Core model:
  [list]
  [*]Active Cores 1,2,3 to turbo ratio 40
  [*]Active Cores 4,5,6,7 to turbo ratio 39
  [*]Active Cores 8 to turbo ratio 38
  [*]Active Cores 9,10 to turbo ratio 36
  [/list]
  The ranges are programmed as follows:
  [list]
  [*]1ADh[7:0] = 40, 1AEh[7:0] = 3
  [*]1ADh[15:8] = 39, 1AEh[15:8] = 7
  [*]1ADh[23:16] = 38, 1AEh[23:16] = 8
  [*]1ADh[31:24] = 36, 1AEh[31:24] = 10
  [*]Recommended: pad both registers with zero. 1ADh[63:32] = 0, 1AEh[63:32] = 0
  [/list]
**/
#define ADL_MSR_BIGCORE_TURBO_RATIO_LIMIT 0x000001AD

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 MaxTurboGroup0 : 8;

                            /* Bits[7:0], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 1 core active. */
    UINT32 MaxTurboGroup1 : 8;

                            /* Bits[15:8], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 2 cores active. */
    UINT32 MaxTurboGroup2 : 8;

                            /* Bits[23:16], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 3 cores active. */
    UINT32 MaxTurboGroup3 : 8;

                            /* Bits[31:24], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup4 : 8;

                            /* Bits[39:32], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup5 : 8;

                            /* Bits[47:40], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup6 : 8;

                            /* Bits[55:48], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup7 : 8;

                            /* Bits[63:56], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */

  } Bits;

  UINT8  MaxTurboGroup[8];
  UINT32 Uint32;
  UINT64 Uint64;

} ADL_MSR_BIGCORE_TURBO_RATIO_LIMIT_REGISTER;

/**
  This register defines the active core ranges for each frequency point
  NUMCORE[0:7] must be populated in ascending order.
  NUMCORE[i+1] must be greater than NUMCORE[i]
  Entries with NUMCORE[i] == 0 will be ignored
  The last valid entry must have NUMCORE >= the number of cores in the SKU
  If any of the rules above are broken, we will silently reject the configuration.
**/
#define ADL_MSR_BIGCORE_TURBO_RATIO_LIMIT_CORES 0x000001AE

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 Numcore0 : 8;

                            /* Bits[7:0], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore1 : 8;

                            /* Bits[15:8], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore2 : 8;

                            /* Bits[23:16], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore3 : 8;

                            /* Bits[31:24], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore4 : 8;

                            /* Bits[39:32], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore5 : 8;

                            /* Bits[47:40], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore6 : 8;

                            /* Bits[55:48], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore7 : 8;

                            /* Bits[63:56], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */

  } Bits;

  UINT8  Numcore[8];
  UINT32 Uint32;
  UINT64 Uint64;

} ADL_MSR_BIGCORE_TURBO_RATIO_LIMIT_CORES_REGISTER;

/**
  This MSR indicates the factory configured values for active core ranges (1-8) and not active cores. Each field in MSR_TURBO_RATIO_LIMIT_CORES (MSR 1AEh) denotes
  the active core count.
  Software can configure these limits when PLATFORM_INFO MSR 0CEh[28]==1.
  Instead of specifying a ratio for each active core count (legacy behavior), active core counts with an identical turbo ratio limit belong to a single active core range that act as a turbo limit for that entire range of active cores.
  Example: configure turbo ratio limits for a 10-Core model:
  [list]
  [*]Active Cores 1,2,3 to turbo ratio 40
  [*]Active Cores 4,5,6,7 to turbo ratio 39
  [*]Active Cores 8 to turbo ratio 38
  [*]Active Cores 9,10 to turbo ratio 36
  [/list]
  The ranges are programmed as follows:
  [list]
  [*]1ADh[7:0] = 40, 1AEh[7:0] = 3
  [*]1ADh[15:8] = 39, 1AEh[15:8] = 7
  [*]1ADh[23:16] = 38, 1AEh[23:16] = 8
  [*]1ADh[31:24] = 36, 1AEh[31:24] = 10
  [*]Recommended: pad both registers with zero. 1ADh[63:32] = 0, 1AEh[63:32] = 0
  [/list]
**/
#define ADL_MSR_ATOM_TURBO_RATIO_LIMIT 0x00000650

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 MaxTurboGroup0 : 8;

                            /* Bits[7:0], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 1 core active. */
    UINT32 MaxTurboGroup1 : 8;

                            /* Bits[15:8], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 2 cores active. */
    UINT32 MaxTurboGroup2 : 8;

                            /* Bits[23:16], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 3 cores active. */
    UINT32 MaxTurboGroup3 : 8;

                            /* Bits[31:24], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup4 : 8;

                            /* Bits[39:32], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup5 : 8;

                            /* Bits[47:40], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup6 : 8;

                            /* Bits[55:48], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */
    UINT32 MaxTurboGroup7 : 8;

                            /* Bits[63:56], Access Type=RW_L, default=0x00000000*/

                            /* Maximum turbo ratio limit with 4 cores active. */

  } Bits;

  UINT8  MaxTurboGroup[8];
  UINT32 Uint32;
  UINT64 Uint64;

} ADL_MSR_ATOM_TURBO_RATIO_LIMIT_REGISTER;

/**
  This register defines the active core ranges for each frequency point
  NUMCORE[0:7] must be populated in ascending order.
  NUMCORE[i+1] must be greater than NUMCORE[i]
  Entries with NUMCORE[i] == 0 will be ignored
  The last valid entry must have NUMCORE >= the number of cores in the SKU
  If any of the rules above are broken, we will silently reject the configuration.
**/
#define ADL_MSR_ATOM_TURBO_RATIO_LIMIT_CORES 0x00000651

typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32 Numcore0 : 8;

                            /* Bits[7:0], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore1 : 8;

                            /* Bits[15:8], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore2 : 8;

                            /* Bits[23:16], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore3 : 8;

                            /* Bits[31:24], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore4 : 8;

                            /* Bits[39:32], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore5 : 8;

                            /* Bits[47:40], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore6 : 8;

                            /* Bits[55:48], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */
    UINT32 Numcore7 : 8;

                            /* Bits[63:56], Access Type=RW, default=0x00000000*/

                            /*
                               defines the active core ranges for each
                               frequency point.
                            */

  } Bits;

  UINT8  Numcore[8];
  UINT32 Uint32;
  UINT64 Uint64;

} ADL_MSR_ATOM_TURBO_RATIO_LIMIT_CORES_REGISTER;

/**
  This MSR indicates the factory configured values for active core ranges (1-8) and not active cores. Each field in MSR_TURBO_RATIO_LIMIT_CORES (MSR 1AEh) denotes
  the active core count.
  Software can configure these limits when PLATFORM_INFO MSR 0CEh[28]==1.
  Instead of specifying a ratio for each active core count (legacy behavior), active core counts with an identical turbo ratio limit belong to a single active core range that act as a turbo limit for that entire range of active cores.
  Example: configure turbo ratio limits for a 10-Core model:
  [list]
  [*]Active Cores 1,2,3 to turbo ratio 40
  [*]Active Cores 4,5,6,7 to turbo ratio 39
  [*]Active Cores 8 to turbo ratio 38
  [*]Active Cores 9,10 to turbo ratio 36
  [/list]
  The ranges are programmed as follows:
  [list]
  [*]1ADh[7:0] = 40, 1AEh[7:0] = 3
  [*]1ADh[15:8] = 39, 1AEh[15:8] = 7
  [*]1ADh[23:16] = 38, 1AEh[23:16] = 8
  [*]1ADh[31:24] = 36, 1AEh[31:24] = 10
  [*]Recommended: pad both registers with zero. 1ADh[63:32] = 0, 1AEh[63:32] = 0
  [/list]
**/
#define ADL_MSR_ATOM_TURBO_RATIO_LIMIT 0x00000650
typedef union
{
   ///
   /// Individual bit fields
   ///
   struct
   {
      UINT64 Rsvd70 : 8; /**< Reserved */

      /* Bits[7:0], Access Type=NA, default=0x00000000*/

      /* Reserved */

      UINT64 MaxNonTurboLimRatio : 8; /**< Maximum Non Turbo Limit Ratio */

      /* Bits[15:8], Access Type=NA, default=0x00000000*/

      /* The Maximum Non-Turbo Ratio */

      UINT64 SmmSaveCap : 1; /**< SMM Save Capability */

      /* Bits[16:16], Access Type=NA, default=0x00000001*/

      /*
         When set to '1' indicates this feature exists
         and is configured by SMM_SAVE_CONTROL
      */

      UINT64 RarEn : 1; /**< RAR Enable */

      /* Bits[17:17], Access Type=NA, default=0x00000000*/

      /* When set to '1' indicates RAR feature exists */

      UINT64 Rsvd2218 : 5; /**< Reserved */

      /* Bits[22:18], Access Type=NA, default=0x00000000*/

      /* Reserved */

      UINT64 PpinCap : 1; /**< PPIN Capable */

      /* Bits[23:23], Access Type=NA, default=0x00000000*/

      /*
         When set to 1, indicates that this part supports
         the Protected Processor Inventory Number (PPIN)
         feature.
      */

      UINT64 OcvoltOvrdAvail : 1; /**< Overclocking - Voltage Override Support */

      /* Bits[24:24], Access Type=NA, default=0x00000000*/

      /*
         0b  Indicates that the part does not support
         Voltage override overclocking.
         1b  Indicates that the part supports Voltage
         override overclocking.
      */

      UINT64 FivrRfiTuningAvail : 1; /**< FIVR RFI Tuning Support */

      /* Bits[25:25], Access Type=NA, default=0x00000000*/

      /* FIVR RFI Tuning Support */

      UINT64 Dcu16kModeAvail : 1; /**< DCU 16K Mode Support */

      /* Bits[26:26], Access Type=NA, default=0x00000000*/

      /*
         0b  Indicates that the part does not support
         the 16K DCU mode. 1b  Indicates that the part
         supports 16K DCU mode.
      */

      UINT64 SamplePart : 1; /**< Sample Part */

      /* Bits[27:27], Access Type=NA, default=0x00000000*/

      /*
         A value of 1 indicates the processor is a
         preproduction sample and a property of Intel,
         a value of 0 indicates the part is intended
         for production.
      */

      UINT64 PrgTurboRatioEn : 1; /**< Programmable Ratio Limits for Turbo Mode */

      /* Bits[28:28], Access Type=NA, default=0x00000001*/

      /*
         Programmable Turbo Ratios per number of Active
         Cores 0 = Programming Not Allowed 1 = Programming
         Allowed
      */

      UINT64 PrgTdpLimEn : 1; /**< Programmable TDP Limits Enable */

      /* Bits[29:29], Access Type=NA, default=0x00000001*/

      /*
         Programmable TDP Limits for Turbo Mode. 0
         = Programming Not Allowed 1 = Programming
         Allowed
      */

      UINT64 PrgTjOffsetEn : 1; /**< Programmable TJ Offset Enable */

      /* Bits[30:30], Access Type=NA, default=0x00000001*/

      /*
         Programmable TJ Offset Enable. 0 = Programming
         Not Allowed 1 = Programming Allowed
      */

      UINT64 CpuidFaultingEn : 1; /**< CPUID Faulting Enabled */

      /* Bits[31:31], Access Type=NA, default=0x00000001*/

      /*
         When set to 1 indicates that the processor
         supports raising a #GP if CPUID is executed
         when not in SMM and the CPL > 0. When this
         bit is set, it indicates that MISC_FEATURE_ENABLES[0]
         can be written by a VMM.
      */

      UINT64 LpmSupport : 1; /**< LPM supported */

      /* Bits[32:32], Access Type=NA, default=0x00000000*/

      /*
         0 - Low Power Mode not Supported 1 - Low Power
         Mode Supported
      */

      UINT64 ConfigTdpLevels : 2; /**< Configurable TDP Levels */

      /* Bits[34:33], Access Type=NA, default=0x00000000*/

      /*
         Configurable TDP Levels 00 Config TDP not
         supported 01 One additional TDP level supported
         10 Two additional TDP levels supported 11
         Reserved
      */

      UINT64 PfatEnable : 1; /**< PFAT Enable */

      /* Bits[35:35], Access Type=NA, default=0x00000000*/

      /*
         BIOS GUARD (PFAT) Enable. 0 = PFAT is disabled
         1 = PFAT is enabled
      */

      UINT64 Peg2dmidisEn : 1; /**< PEG2DMIDIS Enable */

      /* Bits[36:36], Access Type=NA, default=0x00000001*/

      /*
         0 = PEG2DMIDIS is disabled 1 = PEG2DMIDIS
         is enabled
      */

      UINT64 TimedMwaitEnable : 1; /**< Timed MWAIT Enable */

      /* Bits[37:37], Access Type=NA, default=0x00000000*/

      /*
         Timed MWAIT Enable.           0 = Timed MWAIT
         is disabled           1 = Timed MWAIT is enabled
      */

      UINT64 AsaEn : 1; /**< ASA Enable */

      /* Bits[38:38], Access Type=NA, default=0x00000001*/

      /*
         ASA Enable. 0 = ASA is disabled 1 = ASA is
         enabled
      */

      UINT64 Rsvd39 : 1; /**< Reserved */

      /* Bits[39:39], Access Type=NA, default=0x00000000*/

      /* Reserved */

      UINT64 MaxEfficiencyRatio : 8; /**< Maximum Efficiency Ratio */

      /* Bits[47:40], Access Type=NA, default=0x00000000*/

      /*
         Maximum Efficiency Ratio. This is given in
         units of 100 MHz.
      */

      UINT64 MinOperatingRatio : 8; /**< Minimum Operating Ratio Supported */

      /* Bits[55:48], Access Type=NA, default=0x00000008*/

      /* Minimum Supported Ratio in units of 100MHz */

      UINT64 Rsvd56 : 1; /**< Reserved */

      /* Bits[56:56], Access Type=NA, default=0x00000000*/

      /* Reserved */

      UINT64 EdramEnable : 1; /**< EDRAM Enabled */

      /* Bits[57:57], Access Type=NA, default=0x00000000*/

      /*
         Indicates to BIOS that memory-side ACPI tables
         can be used
      */

      UINT64 Sxp2lmEnable : 1; /**< SXP_2LM Enabled */

      /* Bits[58:58], Access Type=NA, default=0x00000000*/

      /*
         Indicates to BIOS that the FME_ACTIVATE MSR
         can be setup                      Indicates
         to BIOS that the FZM functionality can be
         enabled
      */

      UINT64 SmmSupovrStateLockEnable : 1; /**< SMM_SUPOVR_STATE_LOCK Enabled */

      /* Bits[59:59], Access Type=NA, default=0x00000001*/

      /*
         Indicates to BIOS that the SMM_SUPOVR_STATE_LOCK
         MSR can be setup. This bit is unconditionally
         set. [IntelRsvd]This bit is unconditionally
         set for SoCs that support SNC[/IntelRsvd]
      */

      UINT64 TioEnable : 1; /**< TIO enable fuse */

      /* Bits[60:60], Access Type=NA, default=0x00000000*/

      /*
         Indicates to BIOS that the Trusted IO (TIO)
         MSRs can be accessed                     Indicates
         to BIOS that the Trusted IO (TIO) functionality
         can be enabled                      The value
         of this bit is the same as FUSE_TIO
      */

      UINT64 Rsvd61 : 3; /**< Undefined - auto filled rsvd_[63:61] */

      /* Bits[63:61], Access Type=RO, default=None*/

      /* Reserved */

   } Bits;
   UINT32 Uint32;
   UINT64 Uint64;
} MSR_PLATFORM_INFO_REGISTER;
#endif
