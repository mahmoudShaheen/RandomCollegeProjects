function SSB_USB()

%Clear Screen
clc
clear all
close all

%Message parameters "Triangle"
fm = 1e3;
Am = 2;
Tm = 1/fm;

%Carrier parameters "Cosine"
fc = 1e6;
Ac = 5;
Tc = 1/fc;

%Sampling & Periods
fs = 100*fc;
Ts = 1/fs ;
tm = 0:Ts:Tm ;
tc = 0:Ts:Tc ;
Nm = length(tm)-1;
Nc = length(tc)-1;
t = (0:Ts:Nm*Ts)';
ffm = -fs/2:fs/Nm:fs/2 ;
ffc = -fs/2:fs/Nc:fs/2 ;

%Equations
msg=(2*Am/pi)*asin(sin(2*pi*fm*tm));
msgsh=(2*Am/pi)*asin(sin((2*pi*fm*tm)-(pi/2)));
Fmsg=fftshift(fft(msg));
carrier=Ac*cos(2*pi*fc*tc);
Fcarrier=fftshift(fft(carrier));

%Before Modulation
%Information
figure('name','information','numbertitle','off');
subplot(2,1,1);
plot(tm,msg);
title('information T-domain');
grid on;
subplot(2,1,2);
plot(ffm,abs(Fmsg));
axis([-20*fm 20*fm 0 max(abs(Fmsg))]);
title('Information F-domain');
grid on;
%Carrier
figure('name','Carrier','numbertitle','off');
subplot(2,1,1);
plot(tc,carrier);
title('carrier T-domain');
grid on;
subplot(2,1,2);
plot(ffc,abs(Fcarrier));
axis([-20*fc 20*fc 0 max(abs(Fcarrier))]);
title('Carrier F-domain');
grid on;

%Modulation
figure('name','Modulated','numbertitle','off');
msg = msg(:); %Transpose of msg
msgsh=msgsh(:);
mod = msg.*cos(2*pi*fc*t) - msgsh.* sin(2*pi*fc*t);
subplot(2,1,1);
plot(tm,mod);
title('Modulated T-domain');
grid on;
Fmod=fftshift(fft(mod));
subplot(2,1,2);
plot(ffm,abs(Fmod));
axis([-20*fc 20*fc 0 max(abs(Fcarrier))]);
title('Modulated F-domain');
grid on;

%De-Modulation
figure('name','De-Modulated','numbertitle','off');
demod = mod.*cos(2*pi*fc*t);
demod = demod';
subplot(2,1,1);
plot(tm,demod);
title('De-Modulated T-domain');
grid on;
Fdemod=fftshift(fft(demod));
subplot(2,1,2);
plot(ffm,abs(Fdemod));
axis([-20*fm 20*fm 0 max(abs(Fmsg))]);
title('De-Modulated F-domain');
grid on;

%Filter to remove ripples
figure('name','Ripples Filter','numbertitle','off');
[num,den] = butter(5,0.01,'low');
fildemod=filter(num,den,demod);
subplot(2,1,1);
plot(tm,fildemod);
title('Ripples Filtered De-Modulated T-domain');
grid on;
Ffildemod=fftshift(fft(fildemod));
subplot(2,1,2);
plot(ffm,abs(Ffildemod));
axis([-20*fm 20*fm 0 max(abs(Fmsg))]);
title('Ripples Filtered De-Modulated F-domain');
grid on;

%Removing DC Shift as A=(Ac+Am)/2
figure('name','DC Shift Removal','numbertitle','off');
Dc = 2* fildemod;
subplot(2,1,1);
plot(tm,Dc);
title('Ripples Filtered De-Modulated T-domain');
grid on;
FDc=fftshift(fft(Dc));
subplot(2,1,2);
plot(ffm,abs(FDc));
axis([-20*fm 20*fm 0 max(abs(Fmsg))]);
title('Ripples Filtered De-Modulated F-domain');
grid on;

%Plotting before and after the process
figure('name','before & after','numbertitle','off');
subplot(2,1,1);
plot(tm,msg,'b',tm,Dc,'r');
title('T-domain');
legend('Before','After');
grid on;
subplot(2,1,2);
plot(ffm,abs(Fmsg),'b',ffm,abs(FDc),'r');
axis([-20*fm 20*fm 0 max(abs(Fmsg))]);
title('F-domain');
legend('Before','After');
grid on;

%Efficiency
Et=(Ac*Am/2)^2;
Eu=(Ac*Am/2)^2;
EF=(Eu/Et)*100;
sprintf('Total Energy: %2.3g\nUseful Energy: %2.3g\nEfficiency: %2.3g %%',Et,Eu,EF)

%Clear Screen
prompt = 'Press Enter to close All !';
input(prompt)
close all
clear all
clc

end