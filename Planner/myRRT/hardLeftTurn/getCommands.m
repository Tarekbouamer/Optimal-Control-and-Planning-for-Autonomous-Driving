function [u, T, t, controlParams] = getCommands(primitive, state)



if strcmp(primitive, 'default')
    [u, T, t, controlParams] = commandsDefault();
    
else if strcmp(primitive, 'straight1')
        [u, T, t, controlParams] = commandsStraight1();
        
    else if strcmp(primitive, 'straight2')
            [u, T, t, controlParams] = commandsStraight2();
            
        else if strcmp(primitive, 'turnleft')
                [u, T, t, controlParams] = commandsturnleft();
                
            else if strcmp(primitive, 'turnright')
                    [u, T, t, controlParams] = commandsturnright();
                    
                else if strcmp(primitive, 'backturnright')
                        [u, T, t, controlParams] = commandsbackturnright();
                        
                    else if strcmp(primitive, 'backturnleft')
                            [u, T, t, controlParams] = commandsbackturnleft();
                        end
                    end
                end
            end
        end
    end
end

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


 pLeft = 0;
 pRight = 0;
 pStraight = 1;
assert( abs(pLeft + pRight + pStraight  - 1) < 1e-3);

randNum = rand(1,1);
if randNum < pLeft
    steer = rand(1,1) *168;
else if randNum >= (pLeft) &&  randNum < (pLeft +  pRight)
        steer = -rand(1,1)*168 ;
    else 
        steer = 0;
    end
    
end


pBrake = 1 ;
pHandbrake = 0.0;
pThrottle = 0;
pNoAction = 0;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*50)/100;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*50)/100;
        end
    end
end

T = round(rand(1,1)*3)/10 + 0.4;

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
Uref = 70/3.6;
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


function [u, T, t, controlParams] = commandsStraight1()
 

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
 
 pLeft = 0.333;
 pLeftEx = 0;
 pRight = 0.333;
 pStraight = 0.333;
assert( abs(pLeft + pRight + pStraight + pLeftEx - 1) < 1e-3);

randNum = rand(1,1);
    if randNum < pLeft
        steer = rand(1,1) *168;
        else if randNum >= (pLeft + pLeftEx) &&  randNum < (pLeft + pLeftEx +  pRight)
            steer = -rand(1,1)*168 ;
            else 
              steer = 0;
            end
    end 

pBrake = 0.5;
pHandbrake = 0.0;
pThrottle = 0.0;
pNoAction = 0.5;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*50)/100;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*50)/100;
        end
    end
end

T = round(rand(1,1)*3)/10 + 0.1;

 u(1) = steer;
 u(2) = counterSteer;
 u(3) = steerBack;
 u(4) = brakeOn;
 u(5) = brakeOff;
 u(6) = handbrakeOn;
 u(7) = handbrakeOff;
 u(8) = throttleOn;
 u(9) = throttleOff;

selectYawController = 3;
Uref = 75/3.6;
ksiRef = 0;
xRef = 0;
yRef = 3.5;

controlParams = zeros(5,1);
controlParams(1) = selectYawController;
controlParams(2) = Uref;
controlParams(3) = ksiRef;
controlParams(4) = xRef;
controlParams(5) = yRef;
end

function [u, T, t, controlParams] = commandsStraight2()
 
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
 
 pLeft = 0.333;
 pLeftEx = 0;
 pRight = 0.333;
 pStraight = 0.333;
assert( abs(pLeft + pRight + pStraight + pLeftEx - 1) < 1e-3);

randNum = rand(1,1);
    if randNum < pLeft
        steer = rand(1,1) *168;
        else if randNum >= (pLeft + pLeftEx) &&  randNum < (pLeft + pLeftEx +  pRight)
            steer = -rand(1,1)*168;
            else 
              steer = 0;
            end
    end 

pBrake = 0.4;
pHandbrake = 0.0;
pThrottle = 0;
pNoAction = 0.6;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*50)/100;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*50)/100;
        end
    end
end

T = round(rand(1,1)*3)/10 + 0.1;


 u(1) = steer;
 u(2) = counterSteer;
 u(3) = steerBack;
 u(4) = brakeOn;
 u(5) = brakeOff;
 u(6) = handbrakeOn;
 u(7) = handbrakeOff;
 u(8) = throttleOn;
 u(9) = throttleOff;

selectYawController = 3;
Uref = 80/3.6;
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

 function [u, T, t, controlParams] = commandsturnleft()
 

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
 
 pLeft = 0.6;
 pLeftEx = 0.2;
 pRight = 0;
 pStraight = 0.2;
assert( abs(pLeft + pRight + pStraight + pLeftEx - 1) < 1e-3);

randNum = rand(1,1);
if randNum < pLeft
    steer = rand(1,1) *100;
else if randNum >= pLeft &&  randNum < (pLeft + pLeftEx)
        steer = rand(1,1)*68 +100;
else if randNum >= (pLeft + pLeftEx) &&  randNum < (pLeft + pLeftEx +  pRight)
        steer = -rand(1,1)*250 ;
    else 
        steer = 0;
    end
    end 
end

pBrake = 0.8;
pHandbrake = 0;
pThrottle = 0;
pNoAction = 0.2;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*50)/100;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*50)/100;
        end
    end
end

T = round(rand(1,1)*3)/10 + 0.1;
 
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
Uref = 70/3.6;
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
 
 function [u, T, t, controlParams] = commandsturnright()
 

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
 
 pRight = 0.6;
 pRightEx = 0.2;
 pLeft = 0;
 pStraight = 0.2;
assert( abs(pLeft + pRight + pStraight + pRightEx - 1) < 1e-3);

randNum = rand(1,1);
if randNum < pRight
    steer = -rand(1,1) *168;
else if randNum >= pRight &&  randNum < (pRight + pRightEx)
        steer = -rand(1,1)*68 -100;
else if randNum >= (pRight + pRightEx) &&  randNum < (pLeft + pRightEx +  pLeft)
        steer = rand(1,1)*168 ;
    else 
        steer = 0;
    end
    end 
end

pBrake = 0.6;
pHandbrake = 0;
pThrottle = 0.0;
pNoAction = 0.4;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*50)/100;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*50)/100;
        end
    end
end

T = round(rand(1,1)*3)/10 + 0.1;

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
Uref = 70/3.6;
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

 function [u, T, t, controlParams] = commandsbackturnright()
 

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
 
 pLeft = 0;
 pLeftEx = 0;
 pRight = 0.3;
 pStraight = 0.7;
assert( abs(pLeft + pRight + pStraight + pLeftEx - 1) < 1e-3);

randNum = rand(1,1);
    if randNum < pLeft
        steer = rand(1,1) *168;
        else if randNum >= (pLeft + pLeftEx) &&  randNum < (pLeft + pLeftEx +  pRight)
            steer = -rand(1,1)*168 ;
            else 
              steer = 0;
            end
    end 


pBrake = 0.5;
pHandbrake = 0;
pThrottle = 0.0;
pNoAction = 0.5;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*50)/100;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*50)/100;
        end
    end
end

T = round(rand(1,1)*3)/10 + 0.1;

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
Uref = 70/3.6;
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

  function [u, T, t, controlParams] = commandsbackturnleft()
 

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
 
 pLeft = 0.5;
 pLeftEx = 0;
 pRight = 0;
 pStraight = 0.5;
assert( abs(pLeft + pRight + pStraight + pLeftEx - 1) < 1e-3);

randNum = rand(1,1);
    if randNum < pLeft
        steer = rand(1,1) *168;
        else if randNum >= (pLeft + pLeftEx) &&  randNum < (pLeft + pLeftEx +  pRight)
            steer = -rand(1,1)*168 ;
            else 
              steer = 0;
            end
    end 


pBrake = 0.4;
pHandbrake = 0;
pThrottle = 0.0;
pNoAction = 0.6;
assert( abs(pBrake + pHandbrake + pThrottle + pNoAction - 1) < 1e-3);

randNum = rand(1,1);

if randNum < pBrake
    brakeOn = floor(rand(1)*50)/100;
else if randNum >= pBrake && randNum < (pBrake + pHandbrake)
        handbrakeOn = 1;
    else if randNum >= (pBrake + pHandbrake) && randNum < (pBrake + pHandbrake + pThrottle)
            throttleOn = floor(rand(1)*50)/100;
        end
    end
end

T = round(rand(1,1)*3)/10 + 0.1;

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
Uref = 70/3.6;
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
