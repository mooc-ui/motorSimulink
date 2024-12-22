/*
 * File: Flux_Nonsensor_private.h
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

#ifndef Flux_Nonsensor_private_h_
#define Flux_Nonsensor_private_h_
#include "rtwtypes.h"
#include "Flux_Nonsensor.h"
#include "Flux_Nonsensor_types.h"

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern void InvPark(real32_T rtu_d, real32_T rtu_q, const real32_T rtu_SinCos[2],
                    real32_T *rty_alpha, real32_T *rty_beta);
extern void Park(real32_T rtu_Alpha, real32_T rtu_Beta, const real32_T
                 rtu_SinCos[2], real32_T *rty_D, real32_T *rty_Q);
extern void SVPWM1(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                   real32_T rty_tABC[3]);
extern void u(real32_T rtu_IRefD, real32_T rtu_ISensD, real32_T rtu_IRefQ,
              real32_T rtu_ISensQ, real32_T *rty_PIOutputVd, real32_T
              *rty_PIOutputVq, DW_u *localDW);
extern void Sine_Cosine(void);

#endif                                 /* Flux_Nonsensor_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
