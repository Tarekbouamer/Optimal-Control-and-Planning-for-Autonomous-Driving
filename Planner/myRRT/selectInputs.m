function [ u ] = selectInputs()

u = zeros(4,1);

pLeft = 0.33333;
pRight = 0.33333;
pStraight = 0.33333;
assert( abs(pLeft + pRight + pStraight - 1) < 1e-3);

randNum = rand(1,1);
if randNum < pLeft
    u(1) = rand(1,1) * 20;
else if randNum >= pLeft &&  randNum < (pLeft + pRight)
        u(1) = - rand(1,1)* 20;
    else 
        u(1) = 0;
    end
end

pBrake = 0.05;
pHandbrake = 0.0;
pThrottle = 0.45;
pNoAction = 0.5;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    u(2) = floor(rand(1)*10)/10;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        u(3) = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            u(4) = floor(rand(1)*3)/10;
        end
    end
end





end

