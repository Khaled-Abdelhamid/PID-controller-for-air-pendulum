clear 
clc
close all
subplot(2,1,1)
t=0:0.01:pi/2;
plot(t*180/pi,sin(t));
title('sine along with linear function')
hold on
plot(t*180/pi,t);
hold on
subplot(2,1,2)
plot(t*180/pi,(t-sin(t))*100)
title('error rate in % Vs the angle')