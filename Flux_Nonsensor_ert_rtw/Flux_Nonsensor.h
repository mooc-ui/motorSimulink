/*
 * File: Flux_Nonsensor.h
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

#ifndef Flux_Nonsensor_h_
#define Flux_Nonsensor_h_
#ifndef Flux_Nonsensor_COMMON_INCLUDES_
#define Flux_Nonsensor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Flux_Nonsensor_COMMON_INCLUDES_ */

#include "Flux_Nonsensor_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

/* Includes for objects with custom storage classes */
#include "global_mcu_adc_isr.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
/* System '<Root>/FOC电机控制' */
#include "main.h"

/* Block signals and states (default storage) for system '<S2>/电流环' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S114>/Integrator' */
  real32_T Integrator_DSTATE_c;        /* '<S166>/Integrator' */
} DW_u;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_u u_j;                            /* '<S2>/电流环' */
  real_T Product[3];                   /* '<S1>/Product' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S203>/Discrete-Time Integrator3' */
  real_T UnitDelay_DSTATE;             /* '<S188>/Unit Delay' */
  real_T DiscreteTimeIntegrator3_DSTATE_j;/* '<S204>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S185>/Discrete-Time Integrator' */
  real_T RateTransition_Buffer;        /* '<Root>/Rate Transition' */
  real_T RateTransition1_Buffer;       /* '<Root>/Rate Transition1' */
  real_T RateTransition2_Buffer;       /* '<Root>/Rate Transition2' */
  real_T RateTransition8_Buffer;       /* '<Root>/Rate Transition8' */
  real_T RateTransition3_Buffer;       /* '<Root>/Rate Transition3' */
  real32_T Cos1;                       /* '<S17>/Cos1' */
  real32_T Sin1;                       /* '<S17>/Sin1' */
  real32_T UnitDelay_DSTATE_b;         /* '<S18>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S14>/Integrator' */
  real32_T Integrator1_DSTATE;         /* '<S14>/Integrator1' */
  real32_T Integrator_DSTATE_a;        /* '<S54>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_k;/* '<S11>/Discrete-Time Integrator' */
  real32_T Memory_PreviousInput;       /* '<S2>/Memory' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S11>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator3_IC_LOADING;/* '<S203>/Discrete-Time Integrator3' */
  uint8_T DiscreteTimeIntegrator3_IC_LOADING_m;/* '<S204>/Discrete-Time Integrator3' */
  boolean_T UnitDelay3_DSTATE;         /* '<S11>/Unit Delay3' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void Flux_Nonsensor_initialize(void);
extern void Flux_Nonsensor_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<S2>/Constant3' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S14>/Scope1' : Unused code path elimination
 * Block '<S14>/Scope2' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S15>/Scope1' : Unused code path elimination
 * Block '<S17>/Scope' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S7>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S11>/Saturation2' : Unused code path elimination
 * Block '<S185>/Abs' : Unused code path elimination
 * Block '<S185>/Add' : Unused code path elimination
 * Block '<S185>/Product3' : Unused code path elimination
 * Block '<S185>/Product4' : Unused code path elimination
 * Block '<S186>/Add' : Unused code path elimination
 * Block '<S186>/Add2' : Unused code path elimination
 * Block '<S186>/Add4' : Unused code path elimination
 * Block '<S186>/Constant' : Unused code path elimination
 * Block '<S186>/Gain' : Unused code path elimination
 * Block '<S186>/Gain1' : Unused code path elimination
 * Block '<S186>/Gain2' : Unused code path elimination
 * Block '<S191>/Constant' : Unused code path elimination
 * Block '<S191>/Mod' : Unused code path elimination
 * Block '<S191>/polepair' : Unused code path elimination
 * Block '<S186>/Product' : Unused code path elimination
 * Block '<S186>/Product1' : Unused code path elimination
 * Block '<S186>/Product11' : Unused code path elimination
 * Block '<S186>/Product12' : Unused code path elimination
 * Block '<S186>/Product2' : Unused code path elimination
 * Block '<S186>/Product3' : Unused code path elimination
 * Block '<S186>/Product4' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope14' : Unused code path elimination
 * Block '<Root>/Scope15' : Unused code path elimination
 * Block '<Root>/Scope16' : Unused code path elimination
 * Block '<Root>/Scope17' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<S7>/Gain' : Eliminated nontunable gain of 1
 * Block '<S7>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S7>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S7>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S2>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S2>/Signal Conversion3' : Eliminate redundant signal conversion block
 * Block '<S2>/Signal Conversion4' : Eliminate redundant signal conversion block
 * Block '<S2>/Signal Conversion5' : Eliminate redundant signal conversion block
 * Block '<Root>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<S1>/Constant' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Flux_Nonsensor'
 * '<S1>'   : 'Flux_Nonsensor/Average-Value Inverter'
 * '<S2>'   : 'Flux_Nonsensor/FOC电机控制'
 * '<S3>'   : 'Flux_Nonsensor/Interior PMSM'
 * '<S4>'   : 'Flux_Nonsensor/RangeLimit'
 * '<S5>'   : 'Flux_Nonsensor/Subsystem'
 * '<S6>'   : 'Flux_Nonsensor/FOC电机控制/Clark'
 * '<S7>'   : 'Flux_Nonsensor/FOC电机控制/Flux_Observer'
 * '<S8>'   : 'Flux_Nonsensor/FOC电机控制/InvPark'
 * '<S9>'   : 'Flux_Nonsensor/FOC电机控制/Park'
 * '<S10>'  : 'Flux_Nonsensor/FOC电机控制/SVPWM1'
 * '<S11>'  : 'Flux_Nonsensor/FOC电机控制/speed_control'
 * '<S12>'  : 'Flux_Nonsensor/FOC电机控制/电流环'
 * '<S13>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER'
 * '<S14>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/Cacl_Flux'
 * '<S15>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL'
 * '<S16>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller'
 * '<S17>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Sine_Cosine'
 * '<S18>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/integrator'
 * '<S19>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Anti-windup'
 * '<S20>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/D Gain'
 * '<S21>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/External Derivative'
 * '<S22>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Filter'
 * '<S23>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Filter ICs'
 * '<S24>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/I Gain'
 * '<S25>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Ideal P Gain'
 * '<S26>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S27>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Integrator'
 * '<S28>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Integrator ICs'
 * '<S29>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/N Copy'
 * '<S30>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/N Gain'
 * '<S31>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/P Copy'
 * '<S32>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Parallel P Gain'
 * '<S33>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Reset Signal'
 * '<S34>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Saturation'
 * '<S35>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Saturation Fdbk'
 * '<S36>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Sum'
 * '<S37>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Sum Fdbk'
 * '<S38>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tracking Mode'
 * '<S39>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tracking Mode Sum'
 * '<S40>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tsamp - Integral'
 * '<S41>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tsamp - Ngain'
 * '<S42>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/postSat Signal'
 * '<S43>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/preSat Signal'
 * '<S44>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S45>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S46>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S47>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/D Gain/Disabled'
 * '<S48>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/External Derivative/Disabled'
 * '<S49>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Filter/Disabled'
 * '<S50>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Filter ICs/Disabled'
 * '<S51>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/I Gain/External Parameters'
 * '<S52>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S53>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S54>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Integrator/Discrete'
 * '<S55>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S56>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S57>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/N Gain/Disabled'
 * '<S58>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/P Copy/Disabled'
 * '<S59>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S60>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Reset Signal/Disabled'
 * '<S61>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Saturation/Enabled'
 * '<S62>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S63>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Sum/Sum_PI'
 * '<S64>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S65>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S66>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S67>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S68>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S69>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S70>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S71>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/integrator/Angle_Limit'
 * '<S72>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/integrator/Angle_Limit/If Action Subsystem1'
 * '<S73>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/integrator/Angle_Limit/If Action Subsystem2'
 * '<S74>'  : 'Flux_Nonsensor/FOC电机控制/Flux_Observer/Flux_OBSERVER/PLL/integrator/Angle_Limit/If Action Subsystem3'
 * '<S75>'  : 'Flux_Nonsensor/FOC电机控制/SVPWM1/InvClark'
 * '<S76>'  : 'Flux_Nonsensor/FOC电机控制/SVPWM1/ei_t'
 * '<S77>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller'
 * '<S78>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1'
 * '<S79>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Anti-windup'
 * '<S80>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/D Gain'
 * '<S81>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/External Derivative'
 * '<S82>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Filter'
 * '<S83>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Filter ICs'
 * '<S84>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/I Gain'
 * '<S85>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Ideal P Gain'
 * '<S86>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S87>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Integrator'
 * '<S88>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Integrator ICs'
 * '<S89>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/N Copy'
 * '<S90>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/N Gain'
 * '<S91>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/P Copy'
 * '<S92>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Parallel P Gain'
 * '<S93>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Reset Signal'
 * '<S94>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Saturation'
 * '<S95>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Saturation Fdbk'
 * '<S96>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Sum'
 * '<S97>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Sum Fdbk'
 * '<S98>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tracking Mode'
 * '<S99>'  : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tracking Mode Sum'
 * '<S100>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tsamp - Integral'
 * '<S101>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tsamp - Ngain'
 * '<S102>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/postSat Signal'
 * '<S103>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/preSat Signal'
 * '<S104>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S105>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S106>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S107>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/D Gain/Disabled'
 * '<S108>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/External Derivative/Disabled'
 * '<S109>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Filter/Disabled'
 * '<S110>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Filter ICs/Disabled'
 * '<S111>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/I Gain/External Parameters'
 * '<S112>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S113>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S114>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Integrator/Discrete'
 * '<S115>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S116>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S117>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/N Gain/Disabled'
 * '<S118>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/P Copy/Disabled'
 * '<S119>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S120>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Reset Signal/Disabled'
 * '<S121>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Saturation/Enabled'
 * '<S122>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S123>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Sum/Sum_PI'
 * '<S124>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S125>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S126>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S127>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S128>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S129>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S130>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S131>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Anti-windup'
 * '<S132>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/D Gain'
 * '<S133>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/External Derivative'
 * '<S134>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Filter'
 * '<S135>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Filter ICs'
 * '<S136>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/I Gain'
 * '<S137>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Ideal P Gain'
 * '<S138>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S139>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Integrator'
 * '<S140>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Integrator ICs'
 * '<S141>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/N Copy'
 * '<S142>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/N Gain'
 * '<S143>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/P Copy'
 * '<S144>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Parallel P Gain'
 * '<S145>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Reset Signal'
 * '<S146>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Saturation'
 * '<S147>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Saturation Fdbk'
 * '<S148>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Sum'
 * '<S149>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Sum Fdbk'
 * '<S150>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tracking Mode'
 * '<S151>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tracking Mode Sum'
 * '<S152>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tsamp - Integral'
 * '<S153>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tsamp - Ngain'
 * '<S154>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/postSat Signal'
 * '<S155>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/preSat Signal'
 * '<S156>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S157>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S158>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S159>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/D Gain/Disabled'
 * '<S160>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/External Derivative/Disabled'
 * '<S161>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Filter/Disabled'
 * '<S162>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S163>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/I Gain/External Parameters'
 * '<S164>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S165>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S166>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Integrator/Discrete'
 * '<S167>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S168>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S169>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/N Gain/Disabled'
 * '<S170>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/P Copy/Disabled'
 * '<S171>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S172>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S173>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Saturation/Enabled'
 * '<S174>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S175>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Sum/Sum_PI'
 * '<S176>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S177>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S178>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S179>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S180>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S181>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S182>' : 'Flux_Nonsensor/FOC电机控制/电流环/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S183>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete'
 * '<S184>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete'
 * '<S185>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle'
 * '<S186>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Motor Units1'
 * '<S187>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic'
 * '<S188>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1'
 * '<S189>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant'
 * '<S190>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant1'
 * '<S191>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Motor Units1/MechToElect'
 * '<S192>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator'
 * '<S193>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S194>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S195>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S196>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform'
 * '<S197>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S198>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Park Transform'
 * '<S199>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque'
 * '<S200>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S201>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Park Transform'
 * '<S202>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S203>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S204>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S205>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S206>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S207>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S208>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S209>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S210>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S211>' : 'Flux_Nonsensor/Interior PMSM/PMSM Torque Input Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S212>' : 'Flux_Nonsensor/RangeLimit/If Action Subsystem'
 * '<S213>' : 'Flux_Nonsensor/RangeLimit/If Action Subsystem1'
 * '<S214>' : 'Flux_Nonsensor/RangeLimit/If Action Subsystem2'
 */
#endif                                 /* Flux_Nonsensor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
