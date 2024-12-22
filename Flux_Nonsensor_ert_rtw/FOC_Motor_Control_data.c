/*
 * File: FOC_Motor_Control_data.c
 *
 * Code generated for Simulink model 'Flux_Nonsensor'.
 *
 * Model version                  : 8.14
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Dec 21 22:28:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "global_mcu_adc_isr.h"
#include "rtwtypes.h"
#include "Flux_Nonsensor_types.h"

/* Exported data definition */

/* Definition for custom storage class: Global */
real32_T Gamma = 100000.0F;            /* Referenced by: '<S14>/Constant3' */
real32_T Speed_Ki = 0.156051531F;      /* Referenced by: '<S11>/Ki' */
real32_T Speed_Kp = 0.031210307F;      /* Referenced by: '<S11>/Kp' */
real32_T pll_omega = 10000.0F;         /* Referenced by: '<S15>/Constant2' */
real32_T pll_xi = 1.0E+6F;             /* Referenced by: '<S15>/Constant3' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
