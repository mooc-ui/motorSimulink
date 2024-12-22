/*
 * File: Flux_Nonsensor.c
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

#include "Flux_Nonsensor.h"
#include "rtwtypes.h"
#include "Flux_Nonsensor_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "speed_control.h"
#include "global_mcu_adc_isr.h"
#include <float.h>

/* user code (top of source file) */
/* System '<Root>/FOC电机控制' */
extern float Bus_volt_V,Ia_A,Ib_A,Ic_A,motor_angle;
extern int16_T motor_rotate_speed_rpm_resolver;
extern uint16_T motor_angle_elec_uint_resolver;
extern int16_T vcu_send_speed;
extern real32_T motor_rpm_ref;
extern TIM_HandleTypeDef htim1;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 24) {/* Sample time: [2.5E-5s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.0001s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Output and update for atomic system: '<S15>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;

  /* Saturate: '<S17>/Saturation' */
  if (ObserverTheta > 6.28218508F) {
    rtb_Saturation = 6.28218508F;
  } else if (ObserverTheta < 0.001F) {
    rtb_Saturation = 0.001F;
  } else {
    rtb_Saturation = ObserverTheta;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Trigonometry: '<S17>/Cos1' */
  rtDW.Cos1 = cosf(rtb_Saturation);

  /* Trigonometry: '<S17>/Sin1' */
  rtDW.Sin1 = sinf(rtb_Saturation);
}

/* Output and update for atomic system: '<S2>/InvPark' */
void InvPark(real32_T rtu_d, real32_T rtu_q, const real32_T rtu_SinCos[2],
             real32_T *rty_alpha, real32_T *rty_beta)
{
  /* Product: '<S8>/Product' */
  *rty_alpha = rtu_d * rtu_SinCos[1];

  /* Product: '<S8>/Product1' */
  *rty_beta = rtu_q * rtu_SinCos[0];

  /* Sum: '<S8>/Sum' */
  *rty_alpha -= *rty_beta;

  /* Product: '<S8>/Product2' */
  *rty_beta = rtu_d * rtu_SinCos[0];

  /* Sum: '<S8>/Sum1' incorporates:
   *  Product: '<S8>/Product3'
   */
  *rty_beta += rtu_q * rtu_SinCos[1];
}

/* Output and update for atomic system: '<S2>/Park' */
void Park(real32_T rtu_Alpha, real32_T rtu_Beta, const real32_T rtu_SinCos[2],
          real32_T *rty_D, real32_T *rty_Q)
{
  /* Product: '<S9>/Product' */
  *rty_D = rtu_Alpha * rtu_SinCos[1];

  /* Product: '<S9>/Product1' */
  *rty_Q = rtu_Beta * rtu_SinCos[0];

  /* Sum: '<S9>/Sum' */
  *rty_D += *rty_Q;

  /* Product: '<S9>/Product2' */
  *rty_Q = rtu_Alpha * rtu_SinCos[0];

  /* Sum: '<S9>/Sum1' incorporates:
   *  Product: '<S9>/Product3'
   */
  *rty_Q = rtu_Beta * rtu_SinCos[1] - *rty_Q;
}

/* Output and update for atomic system: '<S2>/SVPWM1' */
void SVPWM1(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
            real32_T rty_tABC[3])
{
  real32_T rtb_Min;
  real32_T rtb_Sum1_b;
  real32_T rtb_Sum_i;

  /* Gain: '<S75>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S75>/Gain1' */
  rtb_Sum1_b = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S75>/Sum' */
  rtb_Sum_i = rtb_Min + rtb_Sum1_b;

  /* Sum: '<S75>/Sum1' */
  rtb_Sum1_b = rtb_Min - rtb_Sum1_b;

  /* Gain: '<S76>/Gain' incorporates:
   *  MinMax: '<S76>/Min'
   *  MinMax: '<S76>/Min1'
   *  Sum: '<S76>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_i), rtb_Sum1_b) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_i), rtb_Sum1_b)) * -0.5F;

  /* Sum: '<S10>/Sum' */
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_i;
  rty_tABC[2] = rtb_Min + rtb_Sum1_b;

  /* Sum: '<S10>/Sum1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Gain: '<S10>/Gain'
   *  Product: '<S10>/Divide'
   */
  rty_tABC[0] = -rty_tABC[0] / rtu_v_bus + 0.5F;
  rty_tABC[1] = -rty_tABC[1] / rtu_v_bus + 0.5F;
  rty_tABC[2] = -rty_tABC[2] / rtu_v_bus + 0.5F;
}

/* Output and update for atomic system: '<S2>/电流环' */
void u(real32_T rtu_IRefD, real32_T rtu_ISensD, real32_T rtu_IRefQ, real32_T
       rtu_ISensQ, real32_T *rty_PIOutputVd, real32_T *rty_PIOutputVq, DW_u
       *localDW)
{
  real32_T rtb_DeadZone_h;
  real32_T rtb_IProdOut_d;
  real32_T rtb_Integrator_m;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_RelationalOperator_f;

  /* Sum: '<S12>/Sum' */
  rtb_Integrator_m = rtu_IRefD - rtu_ISensD;

  /* Sum: '<S123>/Sum' incorporates:
   *  Constant: '<S12>/Constant4'
   *  DiscreteIntegrator: '<S114>/Integrator'
   *  Gain: '<S12>/Gain1'
   *  Product: '<S119>/PProd Out'
   */
  rtb_IProdOut_d = rtb_Integrator_m * 0.367728531F + localDW->Integrator_DSTATE;

  /* Saturate: '<S121>/Saturation' incorporates:
   *  DeadZone: '<S106>/DeadZone'
   */
  if (rtb_IProdOut_d > 20.0F) {
    *rty_PIOutputVd = 20.0F;
    rtb_IProdOut_d -= 20.0F;
  } else {
    if (rtb_IProdOut_d < -20.0F) {
      *rty_PIOutputVd = -20.0F;
    } else {
      *rty_PIOutputVd = rtb_IProdOut_d;
    }

    if (rtb_IProdOut_d >= -20.0F) {
      rtb_IProdOut_d = 0.0F;
    } else {
      rtb_IProdOut_d -= -20.0F;
    }
  }

  /* End of Saturate: '<S121>/Saturation' */

  /* RelationalOperator: '<S104>/Relational Operator' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   */
  rtb_RelationalOperator_f = (rtb_IProdOut_d != 0.0F);

  /* Product: '<S111>/IProd Out' incorporates:
   *  Constant: '<S12>/Constant3'
   *  Gain: '<S12>/Gain'
   */
  rtb_Integrator_m *= 38.9046F;

  /* Switch: '<S104>/Switch1' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   *  Constant: '<S104>/Constant'
   *  Constant: '<S104>/Constant2'
   *  RelationalOperator: '<S104>/fix for DT propagation issue'
   */
  if (rtb_IProdOut_d > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S104>/Switch2' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   *  Constant: '<S104>/Constant3'
   *  Constant: '<S104>/Constant4'
   *  RelationalOperator: '<S104>/fix for DT propagation issue1'
   */
  if (rtb_Integrator_m > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Sum: '<S12>/Sum1' */
  rtb_IProdOut_d = rtu_IRefQ - rtu_ISensQ;

  /* Sum: '<S175>/Sum' incorporates:
   *  Constant: '<S12>/Constant2'
   *  DiscreteIntegrator: '<S166>/Integrator'
   *  Gain: '<S12>/Gain2'
   *  Product: '<S171>/PProd Out'
   */
  rtb_DeadZone_h = rtb_IProdOut_d * 0.367728531F + localDW->Integrator_DSTATE_c;

  /* Saturate: '<S173>/Saturation' incorporates:
   *  DeadZone: '<S158>/DeadZone'
   */
  if (rtb_DeadZone_h > 20.0F) {
    *rty_PIOutputVq = 20.0F;
    rtb_DeadZone_h -= 20.0F;
  } else {
    if (rtb_DeadZone_h < -20.0F) {
      *rty_PIOutputVq = -20.0F;
    } else {
      *rty_PIOutputVq = rtb_DeadZone_h;
    }

    if (rtb_DeadZone_h >= -20.0F) {
      rtb_DeadZone_h = 0.0F;
    } else {
      rtb_DeadZone_h -= -20.0F;
    }
  }

  /* End of Saturate: '<S173>/Saturation' */

  /* Product: '<S163>/IProd Out' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Gain: '<S12>/Gain3'
   */
  rtb_IProdOut_d *= 38.9046F;

  /* Switch: '<S104>/Switch' incorporates:
   *  Constant: '<S104>/Constant1'
   *  Logic: '<S104>/AND3'
   *  RelationalOperator: '<S104>/Equal1'
   *  Switch: '<S104>/Switch1'
   *  Switch: '<S104>/Switch2'
   */
  if (rtb_RelationalOperator_f && (tmp == tmp_0)) {
    rtb_Integrator_m = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S114>/Integrator' incorporates:
   *  Switch: '<S104>/Switch'
   */
  localDW->Integrator_DSTATE += 0.0001F * rtb_Integrator_m;

  /* Switch: '<S156>/Switch1' incorporates:
   *  Constant: '<S156>/Clamping_zero'
   *  Constant: '<S156>/Constant'
   *  Constant: '<S156>/Constant2'
   *  RelationalOperator: '<S156>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_h > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S156>/Switch2' incorporates:
   *  Constant: '<S156>/Clamping_zero'
   *  Constant: '<S156>/Constant3'
   *  Constant: '<S156>/Constant4'
   *  RelationalOperator: '<S156>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_d > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S156>/Switch' incorporates:
   *  Constant: '<S156>/Clamping_zero'
   *  Constant: '<S156>/Constant1'
   *  Logic: '<S156>/AND3'
   *  RelationalOperator: '<S156>/Equal1'
   *  RelationalOperator: '<S156>/Relational Operator'
   *  Switch: '<S156>/Switch1'
   *  Switch: '<S156>/Switch2'
   */
  if ((rtb_DeadZone_h != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut_d = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S166>/Integrator' incorporates:
   *  Switch: '<S156>/Switch'
   */
  localDW->Integrator_DSTATE_c += 0.0001F * rtb_IProdOut_d;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void Flux_Nonsensor_step(void)
{
  real_T rtb_Add_i;
  real_T rtb_Add_l;
  real_T rtb_Add_lj;
  real_T rtb_DiscreteTimeIntegrator3;
  real_T rtb_DiscreteTimeIntegrator3_c;
  real_T rtb_DiscreteTimeIntegrator_h;
  real_T rtb_Divide;
  real_T rtb_Gain4;
  real_T rtb_Merge;
  real_T rtb_PolePairs;
  real_T rtb_VectorConcatenate_idx_1;
  real_T rtb_sine_cosine_o1;
  real_T u0;
  real32_T rtb_Gain5[3];
  real32_T rtb_TmpSignalConversionAtInvParkInport3_tmp[2];
  real32_T rtb_DeadZone;
  real32_T rtb_Gain2_o;
  real32_T rtb_Gain_p;
  real32_T rtb_IProdOut;
  real32_T rtb_Integrator;
  real32_T rtb_Saturation;
  int8_T tmp;
  int8_T tmp_0;

  /* RateTransition: '<Root>/Rate Transition1' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteIntegrator: '<S203>/Discrete-Time Integrator3' */
    if (rtDW.DiscreteTimeIntegrator3_IC_LOADING != 0) {
      rtDW.DiscreteTimeIntegrator3_DSTATE = 0.0;
    }

    rtb_DiscreteTimeIntegrator3 = rtDW.DiscreteTimeIntegrator3_DSTATE;

    /* Switch: '<S188>/Switch1' incorporates:
     *  Constant: '<S188>/Constant1'
     *  Constant: '<S190>/Constant'
     *  RelationalOperator: '<S190>/Compare'
     *  Sum: '<S188>/Add1'
     *  UnitDelay: '<S188>/Unit Delay'
     */
    if (rtDW.UnitDelay_DSTATE >= -3.1415926535897931) {
      /* Switch: '<S188>/Switch' incorporates:
       *  Constant: '<S188>/Constant3'
       *  Constant: '<S189>/Constant'
       *  RelationalOperator: '<S189>/Compare'
       *  Sum: '<S188>/Subtract'
       */
      if (rtDW.UnitDelay_DSTATE <= 3.1415926535897931) {
        rtb_PolePairs = rtDW.UnitDelay_DSTATE;
      } else {
        rtb_PolePairs = rtDW.UnitDelay_DSTATE - 6.2831854820251465;
      }

      /* End of Switch: '<S188>/Switch' */
    } else {
      rtb_PolePairs = rtDW.UnitDelay_DSTATE + 6.2831854820251465;
    }

    /* End of Switch: '<S188>/Switch1' */

    /* Gain: '<S185>/Gain4' */
    rtb_Gain4 = 3.0 * rtb_PolePairs;

    /* Trigonometry: '<S187>/sine_cosine' */
    rtb_sine_cosine_o1 = sin(rtb_Gain4);
    rtb_Gain4 = cos(rtb_Gain4);

    /* DiscreteIntegrator: '<S204>/Discrete-Time Integrator3' */
    if (rtDW.DiscreteTimeIntegrator3_IC_LOADING_m != 0) {
      rtDW.DiscreteTimeIntegrator3_DSTATE_j = 0.0;
    }

    rtb_DiscreteTimeIntegrator3_c = rtDW.DiscreteTimeIntegrator3_DSTATE_j;

    /* Sum: '<S198>/Add1' incorporates:
     *  DiscreteIntegrator: '<S203>/Discrete-Time Integrator3'
     *  DiscreteIntegrator: '<S204>/Discrete-Time Integrator3'
     *  Product: '<S198>/Product2'
     *  Product: '<S198>/Product3'
     */
    rtb_DiscreteTimeIntegrator_h = rtDW.DiscreteTimeIntegrator3_DSTATE *
      rtb_Gain4 - rtDW.DiscreteTimeIntegrator3_DSTATE_j * rtb_sine_cosine_o1;

    /* Sum: '<S198>/Add' incorporates:
     *  DiscreteIntegrator: '<S203>/Discrete-Time Integrator3'
     *  DiscreteIntegrator: '<S204>/Discrete-Time Integrator3'
     *  Product: '<S198>/Product'
     *  Product: '<S198>/Product1'
     */
    rtb_Add_i = rtDW.DiscreteTimeIntegrator3_DSTATE * rtb_sine_cosine_o1 +
      rtDW.DiscreteTimeIntegrator3_DSTATE_j * rtb_Gain4;

    /* Sum: '<S197>/Subtract1' incorporates:
     *  Gain: '<S197>/Gain2'
     *  Gain: '<S197>/Gain3'
     */
    rtb_VectorConcatenate_idx_1 = -0.5 * rtb_DiscreteTimeIntegrator_h +
      0.8660254037844386 * rtb_Add_i;

    /* Sum: '<S197>/Subtract2' incorporates:
     *  Gain: '<S197>/Gain1'
     *  Gain: '<S197>/Gain4'
     */
    rtb_Add_i = -0.5 * rtb_DiscreteTimeIntegrator_h + -0.8660254037844386 *
      rtb_Add_i;

    /* RateTransition: '<Root>/Rate Transition' incorporates:
     *  SignalConversion generated from: '<S184>/Vector Concatenate'
     */
    if (rtM->Timing.TaskCounters.TID[2] == 0) {
      rtDW.RateTransition_Buffer = rtb_DiscreteTimeIntegrator_h;
    }

    if (rtM->Timing.TaskCounters.TID[2] == 0) {
      rtDW.RateTransition1_Buffer = rtb_VectorConcatenate_idx_1;
    }
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    Phase_CurrentA = (real32_T)rtDW.RateTransition_Buffer;
  }

  /* RateTransition: '<Root>/Rate Transition2' */
  if ((rtM->Timing.TaskCounters.TID[1] == 0) && (rtM->Timing.TaskCounters.TID[2]
       == 0)) {
    rtDW.RateTransition2_Buffer = rtb_Add_i;
  }

  /* RateTransition: '<Root>/Rate Transition1' */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Phase_CurrentB = (real32_T)rtDW.RateTransition1_Buffer;
  }

  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
     *  Constant: '<Root>/speed-target'
     */
    Speed_target = 1000.0F;
  }

  /* RateTransition: '<Root>/Rate Transition2' incorporates:
   *  Memory: '<S2>/Memory'
   *  SignalConversion generated from: '<S2>/InvPark'
   */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    Phase_CurrentC = (real32_T)rtDW.RateTransition2_Buffer;

    /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Bus_voltage = 30.0F;

    /* Outputs for Atomic SubSystem: '<Root>/FOC电机控制' */

    /* user code (Output function Body) */

    /* System '<Root>/FOC电机控制' */
    Phase_CurrentA= Ia_A;
    Phase_CurrentB= Ib_A;
    Phase_CurrentC = Ic_A;
    Bus_voltage = Bus_volt_V;
    speed= motor_rotate_speed_rpm_resolver;
    Speed_target = motor_rpm_ref;

    /* UnitDelay: '<S18>/Unit Delay' */
    ObserverTheta = rtDW.UnitDelay_DSTATE_b;

    /* SignalConversion generated from: '<S2>/InvPark' incorporates:
     *  SignalConversion generated from: '<S2>/Park'
     *  Trigonometry: '<S2>/Sin'
     *  Trigonometry: '<S2>/Sin1'
     */
    rtb_TmpSignalConversionAtInvParkInport3_tmp[0] = sinf(ObserverTheta);
    rtb_TmpSignalConversionAtInvParkInport3_tmp[1] = cosf(ObserverTheta);

    /* Outputs for Atomic SubSystem: '<S2>/Clark' */
    /* Gain: '<S6>/Gain' incorporates:
     *  Gain: '<S6>/Gain1'
     *  Sum: '<S6>/Sum'
     *  Sum: '<S6>/Sum1'
     */
    rtb_Gain_p = (Phase_CurrentA - (Phase_CurrentB + Phase_CurrentC) * 0.5F) *
      0.666666687F;

    /* Gain: '<S6>/Gain2' incorporates:
     *  Sum: '<S6>/Sum2'
     */
    rtb_Gain2_o = (Phase_CurrentB - Phase_CurrentC) * 0.577350259F;

    /* End of Outputs for SubSystem: '<S2>/Clark' */

    /* Outputs for Atomic SubSystem: '<S2>/Park' */
    /* SignalConversion generated from: '<S2>/Park' */
    Park(rtb_Gain_p, rtb_Gain2_o, rtb_TmpSignalConversionAtInvParkInport3_tmp,
         &Id_measured, &Iq_measured);

    /* End of Outputs for SubSystem: '<S2>/Park' */

    /* Outputs for Atomic SubSystem: '<S2>/speed_control' */
    rtb_DeadZone = speed_control(rtDW.Memory_PreviousInput);

    /* End of Outputs for SubSystem: '<S2>/speed_control' */

    /* Outputs for Atomic SubSystem: '<S2>/电流环' */
    /* SignalConversion generated from: '<S2>/电流环' incorporates:
     *  Constant: '<S2>/Constant'
     *  Memory: '<S2>/Memory'
     */
    u(0.0F, Id_measured, rtb_DeadZone, Iq_measured, &Vd_voltage, &Vq_voltage,
      &rtDW.u_j);

    /* End of Outputs for SubSystem: '<S2>/电流环' */

    /* Outputs for Atomic SubSystem: '<S2>/InvPark' */
    InvPark(Vd_voltage, Vq_voltage, rtb_TmpSignalConversionAtInvParkInport3_tmp,
            &rtb_DeadZone, &rtb_Saturation);

    /* End of Outputs for SubSystem: '<S2>/InvPark' */

    /* Outputs for Atomic SubSystem: '<S2>/SVPWM1' */
    SVPWM1(rtb_DeadZone, rtb_Saturation, Bus_voltage, rtb_Gain5);

    /* End of Outputs for SubSystem: '<S2>/SVPWM1' */

    /* Saturate: '<S2>/Saturation4' incorporates:
     *  Gain: '<S2>/Gain5'
     *  SignalConversion generated from: '<S2>/InvPark'
     */
    rtb_IProdOut = 12500.0F * rtb_Gain5[0];
    if (rtb_IProdOut > 12500.0F) {
      rtb_Gain5[0] = 12500.0F;
    } else if (rtb_IProdOut < 0.0F) {
      rtb_Gain5[0] = 0.0F;
    } else {
      rtb_Gain5[0] = rtb_IProdOut;
    }

    rtb_IProdOut = 12500.0F * rtb_Gain5[1];
    if (rtb_IProdOut > 12500.0F) {
      rtb_Gain5[1] = 12500.0F;
    } else if (rtb_IProdOut < 0.0F) {
      rtb_Gain5[1] = 0.0F;
    } else {
      rtb_Gain5[1] = rtb_IProdOut;
    }

    rtb_IProdOut = 12500.0F * rtb_Gain5[2];
    if (rtb_IProdOut > 12500.0F) {
      rtb_Gain5[2] = 12500.0F;
    } else if (rtb_IProdOut < 0.0F) {
      rtb_Gain5[2] = 0.0F;
    } else {
      rtb_Gain5[2] = rtb_IProdOut;
    }

    /* End of Saturate: '<S2>/Saturation4' */

    /* Sum: '<S14>/Sum' incorporates:
     *  DiscreteIntegrator: '<S14>/Integrator'
     *  Gain: '<S14>/Gain2'
     */
    rtb_IProdOut = rtDW.Integrator_DSTATE - 0.0001F * rtb_Gain_p;

    /* Sum: '<S14>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S14>/Integrator1'
     *  Gain: '<S14>/Gain3'
     */
    rtb_Integrator = rtDW.Integrator1_DSTATE - 0.000104F * rtb_Gain2_o;

    /* Sum: '<S14>/Add2' incorporates:
     *  Constant: '<S14>/Constant'
     *  Math: '<S14>/Math Function'
     *  Math: '<S14>/Math Function1'
     *  Math: '<S14>/Math Function2'
     *
     * About '<S14>/Math Function':
     *  Operator: magnitude^2
     *
     * About '<S14>/Math Function1':
     *  Operator: magnitude^2
     *
     * About '<S14>/Math Function2':
     *  Operator: magnitude^2
     */
    err = (0.000337456935F - rtb_IProdOut * rtb_IProdOut) - rtb_Integrator *
      rtb_Integrator;

    /* Sum: '<S14>/Add' incorporates:
     *  Constant: '<S14>/Constant3'
     *  Gain: '<S14>/Gain'
     *  Product: '<S14>/Product'
     *  Product: '<S14>/Product2'
     *  Sum: '<S14>/Add4'
     */
    rtb_Gain_p = (rtb_DeadZone - 0.02065F * rtb_Gain_p) + rtb_IProdOut * err *
      Gamma;

    /* Sum: '<S14>/Add1' incorporates:
     *  Constant: '<S14>/Constant3'
     *  Gain: '<S14>/Gain1'
     *  Product: '<S14>/Product1'
     *  Product: '<S14>/Product3'
     *  Sum: '<S14>/Add5'
     */
    rtb_Gain2_o = err * rtb_Integrator * Gamma + (rtb_Saturation - 0.02065F *
      rtb_Gain2_o);

    /* Outputs for Atomic SubSystem: '<S15>/Sine_Cosine' */
    Sine_Cosine();

    /* End of Outputs for SubSystem: '<S15>/Sine_Cosine' */

    /* Sum: '<S15>/Sum' incorporates:
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     */
    rtb_IProdOut = rtb_Integrator * rtDW.Cos1 - rtDW.Sin1 * rtb_IProdOut;

    /* Sum: '<S63>/Sum' incorporates:
     *  Constant: '<S15>/Constant2'
     *  DiscreteIntegrator: '<S54>/Integrator'
     *  Product: '<S59>/PProd Out'
     */
    rtb_Saturation = rtb_IProdOut * pll_omega + rtDW.Integrator_DSTATE_a;

    /* DeadZone: '<S46>/DeadZone' */
    if (rtb_Saturation > 942.477783F) {
      rtb_DeadZone = rtb_Saturation - 942.477783F;
    } else if (rtb_Saturation >= -942.477783F) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = rtb_Saturation - -942.477783F;
    }

    /* End of DeadZone: '<S46>/DeadZone' */

    /* Product: '<S51>/IProd Out' incorporates:
     *  Constant: '<S15>/Constant3'
     */
    rtb_IProdOut *= pll_xi;

    /* Switch: '<S44>/Switch1' incorporates:
     *  Constant: '<S44>/Clamping_zero'
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant2'
     *  RelationalOperator: '<S44>/fix for DT propagation issue'
     */
    if (rtb_DeadZone > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    /* Switch: '<S44>/Switch2' incorporates:
     *  Constant: '<S44>/Clamping_zero'
     *  Constant: '<S44>/Constant3'
     *  Constant: '<S44>/Constant4'
     *  RelationalOperator: '<S44>/fix for DT propagation issue1'
     */
    if (rtb_IProdOut > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/Clamping_zero'
     *  Constant: '<S44>/Constant1'
     *  Logic: '<S44>/AND3'
     *  RelationalOperator: '<S44>/Equal1'
     *  RelationalOperator: '<S44>/Relational Operator'
     *  Switch: '<S44>/Switch1'
     *  Switch: '<S44>/Switch2'
     */
    if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = rtb_IProdOut;
    }

    /* End of Switch: '<S44>/Switch' */

    /* Saturate: '<S61>/Saturation' */
    if (rtb_Saturation > 942.477783F) {
      rtb_Saturation = 942.477783F;
    } else if (rtb_Saturation < -942.477783F) {
      rtb_Saturation = -942.477783F;
    }

    /* End of Saturate: '<S61>/Saturation' */

    /* Sum: '<S18>/Sum1' incorporates:
     *  Gain: '<S18>/Ts'
     */
    rtb_IProdOut = 0.0001F * rtb_Saturation + ObserverTheta;

    /* If: '<S71>/If1' */
    if (rtb_IProdOut > 6.28318548F) {
      /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      /* Sum: '<S73>/Subtract1' incorporates:
       *  Constant: '<S73>/2pi'
       */
      rtb_IProdOut -= 6.28318548F;

      /* End of Outputs for SubSystem: '<S71>/If Action Subsystem2' */
    } else if (rtb_IProdOut < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      /* Sum: '<S74>/Subtract1' incorporates:
       *  Constant: '<S74>/Angle_offset'
       */
      rtb_IProdOut += 6.28318548F;

      /* End of Outputs for SubSystem: '<S71>/If Action Subsystem3' */
    }

    /* End of If: '<S71>/If1' */

    /* Gain: '<S2>/Gain' */
    rtb_Saturation *= 3.18309879F;

    /* user code (Update function Body) */

    /* System '<Root>/FOC电机控制' */
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,12500-Ta);
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,12500-Tb);
    __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,12500-Tc);

    /* Update for UnitDelay: '<S18>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_b = rtb_IProdOut;

    /* Update for Memory: '<S2>/Memory' */
    rtDW.Memory_PreviousInput = rtb_Saturation;

    /* Update for DiscreteIntegrator: '<S14>/Integrator' */
    rtDW.Integrator_DSTATE += 0.0001F * rtb_Gain_p;

    /* Update for DiscreteIntegrator: '<S14>/Integrator1' */
    rtDW.Integrator1_DSTATE += 0.0001F * rtb_Gain2_o;

    /* Update for DiscreteIntegrator: '<S54>/Integrator' */
    rtDW.Integrator_DSTATE_a += 0.0001F * rtb_DeadZone;

    /* End of Outputs for SubSystem: '<Root>/FOC电机控制' */

    /* Sum: '<S5>/Sum1' incorporates:
     *  Constant: '<S5>/Constant'
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  Sum: '<S5>/Sum'
     */
    rtb_VectorConcatenate_idx_1 = -(8.0E-5F * rtb_Gain5[0] - 0.5) + 0.5;
    rtb_DiscreteTimeIntegrator_h = -(8.0E-5F * rtb_Gain5[1] - 0.5) + 0.5;
    u0 = -(8.0E-5F * rtb_Gain5[2] - 0.5) + 0.5;

    /* Gain: '<S1>/Gain' incorporates:
     *  Saturate: '<S1>/Saturation2'
     *  Sum: '<S1>/Sum'
     */
    rtb_Add_i = ((rtb_DiscreteTimeIntegrator_h + u0) +
                 rtb_VectorConcatenate_idx_1) * 0.33333333333333331;

    /* Product: '<S1>/Product' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Saturate: '<S1>/Saturation2'
     *  Sum: '<S1>/Sum1'
     *  Sum: '<S1>/Sum2'
     *  Sum: '<S1>/Sum3'
     *  Switch: '<S1>/Switch'
     */
    rtDW.Product[0] = (rtb_VectorConcatenate_idx_1 - rtb_Add_i) * 30.0;
    rtDW.Product[1] = (rtb_DiscreteTimeIntegrator_h - rtb_Add_i) * 30.0;
    rtDW.Product[2] = (u0 - rtb_Add_i) * 30.0;
  }

  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S196>/Add' incorporates:
     *  Gain: '<S196>/Gain'
     *  Gain: '<S196>/Gain1'
     *  Gain: '<S196>/Gain4'
     */
    rtb_Add_i = (0.66666666666666663 * rtDW.Product[0] + -0.33333333333333331 *
                 rtDW.Product[1]) + -0.33333333333333331 * rtDW.Product[2];

    /* Sum: '<S196>/Add1' incorporates:
     *  Gain: '<S196>/Gain2'
     *  Gain: '<S196>/Gain3'
     */
    rtb_Merge = 0.57735026918962573 * rtDW.Product[1] + -0.57735026918962573 *
      rtDW.Product[2];

    /* Gain: '<S185>/Gain' incorporates:
     *  DiscreteIntegrator: '<S185>/Discrete-Time Integrator'
     */
    rtb_VectorConcatenate_idx_1 = 3.0 * rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Sum: '<S204>/Add' incorporates:
     *  Constant: '<S210>/Constant'
     *  Constant: '<S211>/Constant'
     *  Product: '<S201>/Product'
     *  Product: '<S201>/Product1'
     *  Product: '<S204>/Product'
     *  Product: '<S208>/Product'
     *  Product: '<S209>/Product'
     *  Product: '<S210>/Product'
     *  Product: '<S211>/Product'
     *  Sum: '<S201>/Add'
     */
    rtb_Add_lj = (((rtb_Merge * rtb_Gain4 - rtb_Add_i * rtb_sine_cosine_o1) /
                   0.000104 - rtb_DiscreteTimeIntegrator3 *
                   rtb_VectorConcatenate_idx_1 * 0.0001 / 0.000104) -
                  rtb_VectorConcatenate_idx_1 * 0.01837 / 0.000104) -
      rtb_DiscreteTimeIntegrator3_c * 0.02065 / 0.000104;

    /* Sum: '<S203>/Add' incorporates:
     *  Constant: '<S207>/Constant'
     *  Product: '<S201>/Product2'
     *  Product: '<S201>/Product3'
     *  Product: '<S203>/Product'
     *  Product: '<S205>/Product'
     *  Product: '<S206>/Product'
     *  Product: '<S207>/Product'
     *  Sum: '<S201>/Add1'
     */
    rtb_Merge = ((rtb_Add_i * rtb_Gain4 + rtb_Merge * rtb_sine_cosine_o1) /
                 0.0001 + rtb_VectorConcatenate_idx_1 *
                 rtb_DiscreteTimeIntegrator3_c * 0.000104 / 0.0001) -
      rtb_DiscreteTimeIntegrator3 * 0.02065 / 0.0001;

    /* RateTransition: '<Root>/Rate Transition8' incorporates:
     *  DiscreteIntegrator: '<S185>/Discrete-Time Integrator'
     *  Gain: '<Root>/Gain'
     */
    if (rtM->Timing.TaskCounters.TID[2] == 0) {
      rtDW.RateTransition8_Buffer = 9.5492965855137211 *
        rtDW.DiscreteTimeIntegrator_DSTATE;
    }

    /* Signum: '<S185>/Sign' incorporates:
     *  DiscreteIntegrator: '<S185>/Discrete-Time Integrator'
     */
    if (rtIsNaN(rtDW.DiscreteTimeIntegrator_DSTATE)) {
      rtb_Gain4 = (rtNaN);
    } else if (rtDW.DiscreteTimeIntegrator_DSTATE < 0.0) {
      rtb_Gain4 = -1.0;
    } else {
      rtb_Gain4 = (rtDW.DiscreteTimeIntegrator_DSTATE > 0.0);
    }

    /* Product: '<S185>/Divide' incorporates:
     *  DiscreteIntegrator: '<S185>/Discrete-Time Integrator'
     *  Gain: '<Root>/Gain1'
     *  Gain: '<S199>/Gain1'
     *  Gain: '<S199>/Gain2'
     *  Product: '<S185>/Divide1'
     *  Product: '<S185>/Divide2'
     *  Product: '<S199>/Product'
     *  Product: '<S202>/Product'
     *  Signum: '<S185>/Sign'
     *  Sum: '<S185>/Sum1'
     *  Sum: '<S199>/Add'
     */
    rtb_Divide = ((((rtb_DiscreteTimeIntegrator3 * rtb_DiscreteTimeIntegrator3_c
                     * -3.9999999999999888E-6 + 0.01837 *
                     rtb_DiscreteTimeIntegrator3_c) * 4.5 - 0.002 *
                    rtDW.DiscreteTimeIntegrator_DSTATE) -
                   rtDW.DiscreteTimeIntegrator_DSTATE * 8.0E-5) - 0.0 *
                  rtb_Gain4) / 0.000258;

    /* Sum: '<S188>/Add' incorporates:
     *  DiscreteIntegrator: '<S185>/Discrete-Time Integrator'
     *  Gain: '<S188>/Gain1'
     */
    rtb_Add_l = 2.5E-5 * rtDW.DiscreteTimeIntegrator_DSTATE + rtb_PolePairs;

    /* RateTransition: '<Root>/Rate Transition3' incorporates:
     *  Constant: '<Root>/Constant3  '
     *  Gain: '<Root>/PolePairs'
     *  Math: '<Root>/Mod'
     */
    if (rtM->Timing.TaskCounters.TID[2] == 0) {
      rtDW.RateTransition3_Buffer = rt_modd_snf(3.0 * rtb_PolePairs,
        6.2831853071795862);
    }
  }

  /* RateTransition: '<Root>/Rate Transition8' incorporates:
   *  RateTransition: '<Root>/Rate Transition3'
   */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion5' */
    speed = (real32_T)rtDW.RateTransition8_Buffer;

    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    Theta = (real32_T)rtDW.RateTransition3_Buffer;
  }

  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteIntegrator: '<S203>/Discrete-Time Integrator3' */
    rtDW.DiscreteTimeIntegrator3_IC_LOADING = 0U;
    rtDW.DiscreteTimeIntegrator3_DSTATE += 2.5E-5 * rtb_Merge;
    if (rtDW.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
      rtDW.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator3_DSTATE < -1.0E+7) {
      rtDW.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
    }

    /* End of Update for DiscreteIntegrator: '<S203>/Discrete-Time Integrator3' */

    /* Update for UnitDelay: '<S188>/Unit Delay' */
    rtDW.UnitDelay_DSTATE = rtb_Add_l;

    /* Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator3' */
    rtDW.DiscreteTimeIntegrator3_IC_LOADING_m = 0U;
    rtDW.DiscreteTimeIntegrator3_DSTATE_j += 2.5E-5 * rtb_Add_lj;
    if (rtDW.DiscreteTimeIntegrator3_DSTATE_j > 1.0E+7) {
      rtDW.DiscreteTimeIntegrator3_DSTATE_j = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator3_DSTATE_j < -1.0E+7) {
      rtDW.DiscreteTimeIntegrator3_DSTATE_j = -1.0E+7;
    }

    /* End of Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator3' */

    /* Update for DiscreteIntegrator: '<S185>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE += 2.5E-5 * rtb_Divide;
    if (rtDW.DiscreteTimeIntegrator_DSTATE > 1.0E+7) {
      rtDW.DiscreteTimeIntegrator_DSTATE = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator_DSTATE < -1.0E+7) {
      rtDW.DiscreteTimeIntegrator_DSTATE = -1.0E+7;
    }

    /* End of Update for DiscreteIntegrator: '<S185>/Discrete-Time Integrator' */
  }

  rate_scheduler();
}

/* Model initialize function */
void Flux_Nonsensor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<S203>/Discrete-Time Integrator3' */
  rtDW.DiscreteTimeIntegrator3_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S204>/Discrete-Time Integrator3' */
  rtDW.DiscreteTimeIntegrator3_IC_LOADING_m = 1U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
