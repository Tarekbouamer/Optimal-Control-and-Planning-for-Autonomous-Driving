function [u, T, t, controlParams] = getCommands(primitive, state)



if strcmp(primitive, 'default') 
    [u, T, t, controlParams] = commandsDefault();
    else if strcmp(primitive, 'gymkhana')
           [u, T, t, controlParams] = commandsGymkhana();
         else if strcmp(primitive, 'tightPassage')
             [u, T, t, controlParams] = commandsTightPassage();
             end
        end
end

t = t + ones(13,1)*0.01;
T =  T + 0.01;

end



function [u, T, t, controlParams] = commandsTightPassage()
 
t = zeros(13,1);
u = zeros(13,1);

T = 10;


u(12) = 1;
u(13) = 1;

selectYawController = 1;
Uref = 20;
ksiRef = 0;
xRef = 0;
yRef = 0;



controlParams = zeros(5,1);
controlParams(1) = selectYawController;
controlParams(2) = Uref;
controlParams(3) = ksiRef;
controlParams(4) = xRef;
controlParams(5) = yRef;

end


function [u, T, t, controlParams]= commandsDefault()

t = zeros(13,1);
u = zeros(13,1);

 steer = 0;
 counterSteer = 0;
 steerBack = 0;
 brakeOn = 0;
 brakeOff = 0;
 handbrakeOn = 0;
 handbrakeOff = 0;
 throttleOn = 0;
 throttleOff = 0;

pLeft = 0.3333;
pRight = 0.3333;
pStraight = 0.3333;
assert( abs(pLeft + pRight + pStraight - 1) < 1e-3);

randNum = rand(1,1);
if randNum < pLeft
    steer = rand(1,1) * 15;
else if randNum >= pLeft &&  randNum < (pLeft + pRight)
        steer = - rand(1,1)* 15;
    else 
        steer = 0;
    end
end

pBrake = 0.3;
pHandbrake = 0.0;
pThrottle = 0.35;
pNoAction = 0.35;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*2)/10;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = 0.07;
        end
    end
end
 T = round(rand(1,1)*10)/10 + 0.5;
 u(1) = steer;
 u(2) = counterSteer;
 u(3) = steerBack;
 u(4) = brakeOn;
 u(5) = brakeOff;
 u(6) = handbrakeOn;
 u(7) = handbrakeOff;
 u(8) = throttleOn;
 u(9) = throttleOff;

useYawController = 0;
useSpeedController = 0;
selectYawController = 1;
Uref = 20;
ksiRef = 0;
xRef = 0;
yRef = 0;

controlParams = zeros(5,1);
controlParams(1) = selectYawController;
controlParams(2) = Uref;
controlParams(3) = ksiRef;
controlParams(4) = xRef;
controlParams(5) = yRef;

end

function [u, T, t, controlParams] = commandsGymkhana()

    t = zeros(13,1);
    u = zeros(13,1);
    
    

    steer = -20;
    counterSteer = 40;
    steerBack = -20;
    brakeOn = 0;
    brakeOff = 0;
    handbrakeOn = 0;
    handbrakeOff = 0;
    throttleOn = 1;
    throttleOff = -0.9;

    
    t(10) = round(rand(1)*10)/10; % downshift
    u(10) = -5; 
    t(1) = t(10) + 0.2; %  steering + throttle
    t(8) = t(1);
    
    t(9) = t(1) + 0.5 +round(rand(1)*10)/10; % no more throttle

   
    
    t(2) = t(1) + 0.5 + round(rand(1)*20)/10; % countersteer
    t(12) = t(2);
    u(12) = 1;
    t(3) = t(2) + round(rand(1)*10)/10; % steerback
    t(11) = t(3)+ 0.2;
    u(11) = 5;
    u(1) = -20;
    u(2) = +40;
    u(3) = -20;
    u(8) = 1;
    u(9) = -0.9;
    
    T = 10;
    
    u(1) = steer;
    u(2) = counterSteer;
    u(3) = steerBack;
    u(4) = brakeOn;
    u(5) = brakeOff;
    u(6) = handbrakeOn;
    u(7) = handbrakeOff;
    u(8) = throttleOn;
    u(9) = throttleOff;
    
    
    
    selectYawController = 1;
    Uref = 50;
    ksiRef = -270;
    xRef = 0;
    yRef = 0;

    controlParams = zeros(5,1);
    controlParams(1) = selectYawController;
    controlParams(2) = Uref;
    controlParams(3) = ksiRef;
    controlParams(4) = xRef;
    controlParams(5) = yRef;
end
