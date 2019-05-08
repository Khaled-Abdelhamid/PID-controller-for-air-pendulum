
%% PID 1

clear
clc
close all

a=csvread('PID1.txt');

ts = .01;  % this is the sampling time it is computed from the array t
angle=a(:,1);
signal=a(:,2); %output

subplot(2,1,1)
plot((0:length(signal)-1)*ts,signal)
title('controller signal');

subplot(2,1,2)
plot((0:length(angle)-1)*ts,angle) 
title('angle read');

sgtitle('PID1 Kp= 4 Ki=10 Kd=0.03')
%% PID 2 

clear
clc
close all

a=csvread('PID 2.txt');

ts = .01;  % this is the sampling time it is computed from the array t
angle=a(:,1);%input
signal=a(:,2); %output

subplot(2,1,1)
plot((0:length(signal)-1)*ts,signal)
title('controller signal');

subplot(2,1,2)
plot((0:length(angle)-1)*ts,angle) 
title('angle read');

sgtitle('PID2 Kp=5 Ki=10 Kd=0.03')
%% PID 3

clear
clc
close all

a=csvread('PID 3.txt');

ts = .01;  % this is the sampling time it is computed from the array t
angle=a(:,1);
signal=a(:,2); %output

subplot(2,1,1)
plot((0:length(signal)-1)*ts,signal)
title('controller signal');

subplot(2,1,2)
plot((0:length(angle)-1)*ts,angle) 
title('angle read');

sgtitle('PID3 Kp= 6 Ki=10 Kd=0.03')
%% PID with disturbance (we found that PID 3 best fits our needs)
clear
clc
close all

a=csvread('PID with disturbance.txt');

ts = .01;  % this is the sampling time it is computed from the array t
angle=a(:,1);
signal=a(:,2); %output

subplot(2,1,1)
plot((0:length(signal)-1)*ts,signal)
title('controller signal');

subplot(2,1,2)
plot((0:length(angle)-1)*ts,angle) 
title('angle read');

sgtitle('PID with disturbance Kp= 6 Ki=10 Kd=0.03')
%% PID with disturbance 2 (we found that PID 3 best fits our needs)
clear
clc
close all

a=csvread('PID with disturbance - Copy.txt');

ts = .01;  % this is the sampling time it is computed from the array t
angle=a(:,1);
signal=a(:,2); %output

subplot(2,1,1)
plot((0:length(signal)-1)*ts,signal)
title('controller signal');

subplot(2,1,2)
plot((0:length(angle)-1)*ts,angle) 
title('angle read');

sgtitle('PID with disturbance Kp= 5 Ki=10 Kd=0.03')