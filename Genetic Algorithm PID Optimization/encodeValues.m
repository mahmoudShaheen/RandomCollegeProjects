function [ Res ] = encodeValues( X  , Limits)
    Res = X;    
    for y=1:1:length(X(:,1))
        Res(y,1) = floor(255*X(y,1)/Limits(1));
        Res(y,2) = floor(255*X(y,2)/Limits(2));
        Res(y,3) = floor(255*X(y,3)/Limits(3));
    end
end

