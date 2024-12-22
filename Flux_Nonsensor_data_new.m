%% Simplify_FOC_Input

Phase_CurrentA  =  mpt.Signal;      
Phase_CurrentA.DataType = 'single';

Phase_CurrentB  =  mpt.Signal;      
Phase_CurrentB.DataType = 'single';
     
Phase_CurrentC  =  mpt.Signal;      
Phase_CurrentC.DataType = 'single';

Bus_voltage  =  mpt.Signal;      
Bus_voltage.DataType = 'single';

Ref_Id  =  mpt.Signal;      
Ref_Id.DataType = 'single';

Ref_Iq  =  mpt.Signal;      
Ref_Iq.DataType = 'single';

ObserverTheta=mpt.Signal;      
ObserverTheta.DataType = 'single';

Theta  =  mpt.Signal;      
Theta.DataType = 'single';

speed  =  mpt.Signal;      
speed.DataType = 'single';

Ta  =  mpt.Signal;      
Ta.DataType = 'single';

Tb  =  mpt.Signal;      
Tb.DataType = 'single';

Tc  =  mpt.Signal;      
Tc.DataType = 'single';

Speed_target =  mpt.Signal;      
Speed_target.DataType = 'single';

%% Simplify_FOC_Out

%  

% obs_speed = mpt.Signal;                      
% obs_speed.DataType = 'single';



Vd_voltage =mpt.Signal;
Vd_voltage.DataType = 'single';

Vq_voltage =mpt.Signal;
Vq_voltage.DataType = 'single';



Id_measured= mpt.Signal;                      
Id_measured.DataType = 'single';

Iq_measured= mpt.Signal;                      
Iq_measured.DataType = 'single';

Iq_ref=mpt.Signal;      
Iq_ref.DataType = 'single';

weak_theta = mpt.Signal;                      
weak_theta.DataType = 'single';

IS_REF= mpt.Signal;                      
IS_REF.DataType = 'single';


err = mpt.Signal;     
err.DataType = 'single';


%% Motor_parameters

PolePairs = 3;
Rs = 0.02065;
Ls = 0.000195185;
Ld = 0.0001;
Lq = 0.0001040;

Flux = 0.01837;
Flux_MODEL=0.01837;
%pll_xi = 10;
%pll_omega = 1000;
TsFOC= 1e-4;
TsBSP=1e-4;
TsFOC_MODEL= 1e-4;
TsBSP_MODEL=2.5e-5;
% TsFOC_MODEL=0.0001;
% PWMHalfPeriod=4199;
Fixed_Step_Size=1e-6;






%% loop_Kp_Ki
BandwidthCurrentPI=1256*1.5;
BandwidthSpeedPI=50;

MaxVoltage=10;
Speed_PI_OutputMax=8;
Speed_PI_OutputMin=-8;

J=2.58e-4;


Speed_Kp = mpt.Parameter;     
Speed_Kp.DataType = 'single';
% Speed_Kp.Value = 20*J/(1.5*PolePairs*Flux);         
Speed_Kp.Value = 10*J/(1.5*PolePairs*Flux);      %参数整定的格式；
% Speed_Kp.Value = 0.0567;      
Speed_Kp.CoderInfo.CustomAttributes.DefinitionFile = 'FOC_Motor_Control_data.c';

Speed_Ki = mpt.Parameter;     
Speed_Ki.DataType = 'single';
Speed_Ki.Value = BandwidthSpeedPI*J/(1.5*PolePairs*Flux); 
% Speed_Ki.Value =0.0833;
Speed_Ki.CoderInfo.CustomAttributes.DefinitionFile = 'FOC_Motor_Control_data.c';



Gamma = mpt.Parameter;     
Gamma.DataType = 'single';
Gamma.Value = 100000; 
Gamma.CoderInfo.CustomAttributes.DefinitionFile = 'FOC_Motor_Control_data.c';





pll_omega = mpt.Parameter;     
pll_omega.DataType = 'single';
pll_omega.Value = 10000;             
pll_omega.CoderInfo.CustomAttributes.DefinitionFile = 'FOC_Motor_Control_data.c';


pll_xi = mpt.Parameter;     
pll_xi.DataType = 'single';
pll_xi.Value = 1000000;             
pll_xi.CoderInfo.CustomAttributes.DefinitionFile = 'FOC_Motor_Control_data.c';

