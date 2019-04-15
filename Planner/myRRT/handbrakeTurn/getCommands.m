function [u, T, t, controlParams] = getCommands(primitive, state)



    if strcmp(primitive, 'default') 
        [u, T, t, controlParams] = commandsDefault();
        else if strcmp(primitive, 'handbrakeTurn')
               [u, T, t, controlParams] = commandsHandbrakeTurn();
             else if strcmp(primitive, 'tightPassage')
                 [u, T, t, controlParams] = commandsTightPassage(state);
                 else if strcmp(primitive, 'tightPassage2')
                        [u, T, t, controlParams] = commandsTightPassage2(state);
                     end
                 end
            end
    end
    
    t = t + ones(13,1)*0.01;
    T =  T + 0.01;

end

function [u, T, t, controlParams] = commandsTightPassage2(state)
 
t = zeros(13,1);
u = zeros(13,1);
u(13) = 1;
u(12) = 1;

T = 5;

selectYawController = 1;
Uref = 40;
ksiRef = 180;
xRef = 0;
yRef = 0;

controlParams = zeros(5,1);
controlParams(1) = selectYawController;
controlParams(2) = Uref;
controlParams(3) = ksiRef;
controlParams(4) = xRef;
controlParams(5) = yRef;
end


function [u, T, t, controlParams] = commandsTightPassage(state)
 
t = zeros(13,1);
u = zeros(13,1);

u(13) = 1;
u(12) = 1;
T = 5;
selectYawController = 1;
Uref = 50;
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
timeMargin = 0.0;

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
    steer = rand(1,1) * 10;
else if randNum >= pLeft &&  randNum < (pLeft + pRight)
        steer = - rand(1,1)* 10;
    else 
        steer = 0;
    end
end

pBrake = 0.1;
pHandbrake = 0.0;
pThrottle = 0.45;
pNoAction = 0.45;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*3)/10;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*1)/10 + 0.1;
        end
    end
end
 T = round(rand(1,1)*10)/10 + 1;
 
 u(1) = steer;
 t(1) = timeMargin;
 u(2) = -steer*0;
 t(2) = T - timeMargin;
 
%  u(2) = counterSteer;
 u(3) = steerBack;
 
 u(4) = brakeOn;
 t(4) = timeMargin;
 u(5) = -brakeOn*0;
 t(5) = T - timeMargin;
 
 u(6) = handbrakeOn;
 u(7) = handbrakeOff;
 
 u(8) = throttleOn;
 t(8) = timeMargin;
 u(9) = -throttleOn*0;
 t(9) = T - timeMargin;

selectYawController = 1;
Uref = 0;
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

function [u, T, t, controlParams] = commandsHandbrakeTurn()

    t = zeros(13,1);
    u = zeros(13,1);
    
    
    steerBack = 0;
    
    steer = 15;
    counterSteer = -15;
    brakeOn = 0.1;
    brakeOff = -0.1;
    handbrakeOn = 1;
    handbrakeOff = -1;
    throttleOn = 0.2;
    throttleOff = 0;

    
    t(1) = round(rand(1)*10)/10; % steering + hanbrake

    t(2) = t(1) + 2 + round(rand(1)*25)/10;
    
    t(3) = 0;
    
    t(4) = t(1);
    t(5) = t(1) + 0.2;

    t(6) = t(1) + 0.1;
    t(7) = t(2);
    t(8) = t(1) + 2 + round(rand(1)*2)/10;
    t(9) = 0;
    
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
    Uref = 0;
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
