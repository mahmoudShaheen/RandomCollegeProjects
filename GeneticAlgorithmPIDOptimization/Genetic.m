M = 100;		% Number of iterations
PopSize = 10;		% Population Size

CurrentGen = rand(PopSize,3);

Controller_Limits = [ 5, 3, 1];			%[Kp, Ki, Kd]

for y=1:1:PopSize
    CurrentGen(y,1) = Controller_Limits(1)*rand();		
    CurrentGen(y,2) = Controller_Limits(2)*rand();		
    CurrentGen(y,3) = Controller_Limits(3)*rand();		
end


BestSol = CurrentGen(1,:);
BestObj = fitness(BestSol);

for n=1:1:M
    %disp(CurrentGen);
    ObjectiveValues = fitness(CurrentGen);
    %disp(ObjectiveValues);
    SortedOutputs = sort(ObjectiveValues,'ascend');

    SortedGeneration = CurrentGen;
    for i=1:1:PopSize
        SortedGeneration(i,:) = CurrentGen(find(ObjectiveValues==SortedOutputs(i),1),:);  
    end
    
    if(BestObj>SortedOutputs(1))
        BestObj = SortedOutputs(1);
        BestSol = SortedGeneration(1,:);
    end

    BinaryGen = encodeValues(SortedGeneration, Controller_Limits);

    CrossGen = crossOver(BinaryGen);
    CrossGen = mutate(CrossGen);

    CurrentGen = decodeValues(CrossGen, Controller_Limits);
    disp('Generation number ');
    disp(n);
end

disp('solution is :');
disp(BestObj);
disp(BestSol);

% showing output
    R = 10e3;
    C = 100e-6;
    sys = tf(1,[R*C*R*C 3*R*C 1]);
    Kp = BestSol(1);
    Ki = BestSol(2);
    Kd = BestSol(3);
    Controller = tf([Kd Kp Ki],[1 0]);
    TF = series(Controller,sys);
    TF = feedback(TF,1);
    S = stepinfo(TF);
    Ts = S.SettlingTime;
    Os = S.Overshoot;
    disp(Ts);
    disp(Os);
    Res(n) = abs(Os + 1i*Ts);
    step(sys);
    hold on;
    step(TF);
    hold off;
