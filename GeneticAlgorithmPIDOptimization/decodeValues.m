function [ Res ] = decodeValues( X, Limits )
    Res = X;    
    for y=1:1:length(X(:,1))
        Res(y,1) = Limits(1)*X(y,1)/255;
        Res(y,2) = Limits(2)*X(y,2)/255;
        Res(y,3) = Limits(3)*X(y,3)/255;
    end
end

