/*
 * File: speed_control.c
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

#include "rtwtypes.h"
#include "speed_control.h"
#include "Flux_Nonsensor.h"
#include "global_mcu_adc_isr.h"

/* Output and update for atomic system: '<S2>/speed_control' */
real32_T speed_control(real32_T rtu_Obs_Speed)
{
  real32_T rty_Iq_ref_0;
  real32_T rtb_Switch;

  /* Sum: '<S11>/Sum' */
  rtb_Switch = Speed_target - rtu_Obs_Speed;

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  if (rtDW.DiscreteTimeIntegrator_PrevResetState != 0) {
    rtDW.DiscreteTimeIntegrator_DSTATE_k = 0.0F;
  }

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Kp'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Product: '<S11>/Product'
   */
  rty_Iq_ref_0 = Speed_Kp * rtb_Switch + rtDW.DiscreteTimeIntegrator_DSTATE_k;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Cons'
   *  UnitDelay: '<S11>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE) {
    rtb_Switch = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S11>/Ki'
   *  Product: '<S11>/Product1'
   *  Switch: '<S11>/Switch'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_k += Speed_Ki * rtb_Switch * 0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState = 0;

  /* Update for UnitDelay: '<S11>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S11>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE = (rty_Iq_ref_0 == rty_Iq_ref_0);
  return rty_Iq_ref_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
