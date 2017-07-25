function [ X ] = mutate( X )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    for y=1:1:length(X(:,1))
        for x = 1:1:3
            X(y,x) = bitxor(X(y,x),bitshift(1,floor(8*rand()))); 
        end
    end
end

