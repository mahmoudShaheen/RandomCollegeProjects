%clear all;
clc; 
length = 1;
ind = 1;

n = ones(22,1);
CPU_T = ones(22,1);
GPU_T = ones(22,1);

while (length<10000000)    
    X = rand(length,1);
    Y = rand(length,1);
    
    pause(0.5);

    tic;
    A = X.*X + Y + Y.*X;
    AF = abs(fft(A));
    Ai = ifft(AF);
    CPU_T(ind) = toc;
    %time=toc;
    disp(CPU_T(ind));
    
    XG = gpuArray(X);
    YG = gpuArray(Y);
    G = gpuArray(A);

    disp('GPU Alloation Done');
    pause(0.5);

    tic
    G = XG.*XG + YG + YG.*XG;
    GF = abs(fft(G));
    Gi = ifft(GF);
    GPU_T(ind) = toc;
    %time = toc;
    disp(GPU_T(ind));
    
    n(ind) = length;
    ind = ind +1;
    length = length*2;
end

plot(n,CPU_T);
hold on;
plot(n,GPU_T);
