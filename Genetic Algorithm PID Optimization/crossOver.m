function [ Res ] = crossOver( X )

    N = length(X(:,1));
    for i=1:1:N/2
        kp = X(i,1);
        ki = X(i,2);
        kd = X(i,3);
        kp_ = X(N/2+i,1);
        ki_ = X(N/2+i,2);
        kd_ = X(N/2+i,3);
        
        X(i,1) = bitor(bitand(kp,240), bitand(kp_,15));
        X(i,2) = bitor(bitand(ki,240), bitand(ki_,15));
        X(i,3) = bitor(bitand(kd,240), bitand(kd_,15));
        
        X(N/2+i,1) = bitor(bitand(kp_,240), bitand(kp,15));
        X(N/2+i,2) = bitor(bitand(ki_,240), bitand(ki,15));
        X(N/2+i,3) = bitor(bitand(kd_,240), bitand(kd,15));
    end
    Res = X;
end

