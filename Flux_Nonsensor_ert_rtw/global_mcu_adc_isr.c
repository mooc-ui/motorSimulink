/*
 * File: global_mcu_adc_isr.c
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
real32_T Bus_voltage;                  /* '<Root>/Data Type Conversion4' */
real32_T Id_measured;                  /* '<S2>/Park' */
real32_T Iq_measured;                  /* '<S2>/Park' */
real32_T ObserverTheta;                /* '<S18>/Unit Delay' */
real32_T Phase_CurrentA;               /* '<Root>/Data Type Conversion' */
real32_T Phase_CurrentB;               /* '<Root>/Data Type Conversion1' */
real32_T Phase_CurrentC;               /* '<Root>/Data Type Conversion2' */
real32_T Speed_target;                 /* '<Root>/Data Type Conversion6' */
real32_T Theta;                        /* '<Root>/Data Type Conversion3' */
real32_T Vd_voltage;                   /* '<S2>/电流环' */
real32_T Vq_voltage;                   /* '<S2>/电流环' */
real32_T err;                          /* '<S14>/Add2' */
real32_T speed;                        /* '<Root>/Data Type Conversion5' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
