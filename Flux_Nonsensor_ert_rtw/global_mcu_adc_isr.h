/*
 * File: global_mcu_adc_isr.h
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

#ifndef global_mcu_adc_isr_h_
#define global_mcu_adc_isr_h_
#include "rtwtypes.h"
#include "Flux_Nonsensor_types.h"

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern real32_T Bus_voltage;           /* '<Root>/Data Type Conversion4' */
extern real32_T Id_measured;           /* '<S2>/Park' */
extern real32_T Iq_measured;           /* '<S2>/Park' */
extern real32_T ObserverTheta;         /* '<S18>/Unit Delay' */
extern real32_T Phase_CurrentA;        /* '<Root>/Data Type Conversion' */
extern real32_T Phase_CurrentB;        /* '<Root>/Data Type Conversion1' */
extern real32_T Phase_CurrentC;        /* '<Root>/Data Type Conversion2' */
extern real32_T Speed_target;          /* '<Root>/Data Type Conversion6' */
extern real32_T Theta;                 /* '<Root>/Data Type Conversion3' */
extern real32_T Vd_voltage;            /* '<S2>/电流环' */
extern real32_T Vq_voltage;            /* '<S2>/电流环' */
extern real32_T err;                   /* '<S14>/Add2' */
extern real32_T speed;                 /* '<Root>/Data Type Conversion5' */

/* Declaration for custom storage class: Global */
extern real32_T Gamma;                 /* Referenced by: '<S14>/Constant3' */
extern real32_T Speed_Ki;              /* Referenced by: '<S11>/Ki' */
extern real32_T Speed_Kp;              /* Referenced by: '<S11>/Kp' */
extern real32_T pll_omega;             /* Referenced by: '<S15>/Constant2' */
extern real32_T pll_xi;                /* Referenced by: '<S15>/Constant3' */

#endif                                 /* global_mcu_adc_isr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
