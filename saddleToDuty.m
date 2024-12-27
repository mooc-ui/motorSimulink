% 参数设置
fs = 10e3; % PWM频率，10 kHz
Ts = 1 / fs; % PWM周期，100 us
PWM_max = 2400; % PWM计数最大值
PWM_center = PWM_max / 2; % PWM中心值
PWM_min = 0; % PWM计数最小值

t = 0:Ts:1-Ts; % 离散时间轴，1秒持续时间
f_signal = 50; % 信号频率，50 Hz
omega = 2 * pi * f_signal; % 角频率

% 生成归一化马鞍波信号
A = 1; % 信号幅度（归一化）
saddle_wave_A = A * sin(omega * t); % Phase A
saddle_wave_B = A * sin(omega * t - 2*pi/3); % Phase B，相位差120度
saddle_wave_C = A * sin(omega * t + 2*pi/3); % Phase C，相位差120度

% 映射到PWM计数范围
pwm_signal_A = round((saddle_wave_A + 1) / 2 * PWM_max); % Phase A
pwm_signal_B = round((saddle_wave_B + 1) / 2 * PWM_max); % Phase B
pwm_signal_C = round((saddle_wave_C + 1) / 2 * PWM_max); % Phase C

% 确保PWM信号在范围内
pwm_signal_A = max(min(pwm_signal_A, PWM_max), PWM_min);
pwm_signal_B = max(min(pwm_signal_B, PWM_max), PWM_min);
pwm_signal_C = max(min(pwm_signal_C, PWM_max), PWM_min);

% 生成互补PWM信号
pwm_high_A = pwm_signal_A; % 正向PWM
pwm_low_A = PWM_max - pwm_signal_A; % 反向PWM

pwm_high_B = pwm_signal_B; % 正向PWM
pwm_low_B = PWM_max - pwm_signal_B; % 反向PWM

pwm_high_C = pwm_signal_C; % 正向PWM
pwm_low_C = PWM_max - pwm_signal_C; % 反向PWM

% 可视化PWM信号
figure;
subplot(3,1,1);
plot(t, pwm_high_A, 'r', t, pwm_low_A, 'b');
title('Phase A PWM');
xlabel('Time (s)');
ylabel('PWM Count');
legend('High', 'Low');

subplot(3,1,2);
plot(t, pwm_high_B, 'r', t, pwm_low_B, 'b');
title('Phase B PWM');
xlabel('Time (s)');
ylabel('PWM Count');
legend('High', 'Low');

subplot(3,1,3);
plot(t, pwm_high_C, 'r', t, pwm_low_C, 'b');
title('Phase C PWM');
xlabel('Time (s)');
ylabel('PWM Count');
legend('High', 'Low');