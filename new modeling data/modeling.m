clear
clc
close all

a=csvread('6.csv');

ts = .01;  % this is the sampling time it is computed from the array t
input=a(:,1);%input
output=a(:,2); %output
plot(output)
title('real output');
figure
plot(input) 
title('real step input');

data1 = iddata(output,input,ts);  % this is processing the data to make it compatible with the transfer-function estimation funciton
g = tfest(data1,2,0);   % getting the transfer function and storing it in g
  
% We found that the best approximation to the system is a system of the
% fifth order
transfer_fn = tf([g.Numerator],[g.Denominator]);

opt = stepDataOptions;
opt.InputOffset = 1000;
opt.StepAmplitude = max(a(:,1))-1000;
opt.set
[x,t] = step(transfer_fn,20,opt);

figure 
plot(t,x)
title('the expected transfer function');
 


%%
tfz = c2d(transfer_fn,0.01,'tustin');
 

