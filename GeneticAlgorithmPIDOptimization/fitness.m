function [ Res ] = fitness( X )
    R1 = 10e3;
    C1 = 100e-6;
	R2 = 10e3;
	C2 = 100e-6;
    sys = tf(1,[R1*C1*R2*C2 (R1*C1+R1*C2+R2*C2) 1]);		% Process transfer function to be controlled
    
    for n=1:1:length(X(:,1))
        Kp = X(n,1);
        Ki = X(n,2);
        Kd = X(n,3);
        Controller = tf([Kd Kp Ki],[1 0]);
        TF = series(Controller,sys);
        TF = feedback(TF,1);
        S = stepinfo(TF);
        Ts = S.SettlingTime;
        Os = S.Overshoot;
        Res(n) = abs(Os + 1i*Ts);
    end
end

