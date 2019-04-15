function [A, B, f0] = numericalLinearization(x0, u0, params)
% currentState is a vector [Ux Uy r Ksi x y wF wR]
% nextState is avector [Ux Uy r Ksi x y wF wR]
% units [m/s m/s rad/s/s rad m m rad/s rad/s]

%inputs is a vector
% params is a structure [delta brake handbrake throttle]
% units [rad % % %], & is in [0,1]

params.Dz1 = 0;
params.Dz2 = 0;
eps = 1e-4;
A = zeros(8,8);
B = zeros(8,3);

for i = 1:8    
        vec = zeros(8,1);
        vec(i)= eps;
        point1 = x0 + vec;
        point2 = x0 - vec;
        der = 1/(2*eps) * (f(point1, u0, params) - f(point2, u0, params));
        A(:,i) = der;                
end

for i = 1:3
        vec = zeros(3,1);
        vec(i)= eps;
        point1 = u0 + vec;
        point2 = u0 - vec;
        der = 1/(2*eps) * (f(x0, point1, params) - f(x0, point2, params));
        B(:,i) = der;            
end

f0 = f(x0,u0,params);

end


function y = deadZone(x, low, high)

if x < low
    y = x - low;
else if x > high
        y = x - high;
    else
        y = 0;
    end
end

y = x;

end



function [dX] = f(states, inputs, params)

% params is a structure others are vectors
% state vector [Ux Uy r Ksi x y wF wR]
% input vector [delta brake handbrake throttle]

% if states(7) < 0
%     states(7) = 0;
% end
% 
% if states(8) < 0
%     states(8) = 0;
% end
% 
% 
% states(1) = deadZone(states(1), -params.Dz1, params.Dz1);
% states(2) = deadZone(states(2), -params.Dz1, params.Dz1);
% states(3) = deadZone(states(3), -params.Dz2, params.Dz2);
% if states(7) < 0
%     states(7) = 0;
% end
% 
% if states(8) < 0
%     states(8) = 0;
% end


rollFric = params.m*params.g*params.muRoll*0;

[forces] = tires(states(1), states(2), states(7), states(8),...
    inputs(1), states(3), params );
[torques] = brakeCom(forces, states(7), states(8), params, inputs);

du = 1/params.m*(deadZone(forces.FxF * cos(inputs(1)) - forces.FyF * sin(inputs(1)) + forces.FxR +...
    params.m * states(2) * states(3), -rollFric, rollFric) - params.b * states(1));

dv = 1/params.m*(deadZone(forces.FxF * sin(inputs(1)) + forces.FyF * cos(inputs(1)) + forces.FyR -...
    params.m * states(1) * states(3), -rollFric, rollFric) - params.b * states(2));

dr = 1/params.Iz * (params.lF*(forces.FxF*sin(inputs(1)) + forces.FyF*cos(inputs(1))) -...
    params.lR*forces.FyR);

dKsi = states(3);

dx = states(1) * cos(states(4)) - states(2) * sin(states(4));
dy = states(1) * sin(states(4)) + states(2) * cos(states(4));

dwF = 1/params.Iw * (torques.TmF + torques.TbF - forces.FxF*params.R);
dwR = 1/params.Iw * (torques.TmR + torques.TbR - forces.FxR*params.R);

dX = [du dv dr dKsi dx dy dwF dwR]';
end

function [forces] = tires(Ux, Uy, wF, wR, delta, r, params )


% params has: lF, lR, R,m,g,mu,h, B, C
% forces has: FxF, FyF, FxR, FyR

eps = 1e-4;

UxF = Ux * cos(delta) + Uy * sin(delta) + r * params.lF * sin(delta);
UyF = -Ux * sin(delta) + Uy * cos(delta) + r * params.lF * cos(delta);
UxR = Ux;
UyR = Uy - params.lR * r;



SxF = robustDiv(UxF-params.R*wF,params.R*wF, eps);
SyF = (1+SxF) * robustDiv(UyF,UxF,eps);
SxR = robustDiv(UxR-params.R*wR,params.R*wR,eps);
SyR = (1+SxR) * robustDiv(UyR,UxR,eps);

SR = sqrt( (SxR)^2 + (SyR)^2 );
SF = sqrt( (SxF)^2 + (SyF)^2 );

muF = sin(params.C*atan(params.B*SF));
muR = sin(params.C*atan(params.B*SR));

muxF = - muF * robustDiv(SxF,SF,eps);
muyF = - muF * robustDiv(SyF,SF,eps);
muxR = - muR * robustDiv(SxR,SR,eps);
muyR = - muR * robustDiv(SyR,SR,eps);


num =  (params.m*params.g*params.lR - params.mu*params.h*params.m*params.g*muxR);
den = params.lF + params.lR +params.mu*params.h*(muxF*cos(delta)-muyF*sin(delta) -muxR);
FzF = robustDiv(num,den,eps);
FzR = (params.m*params.g-FzF);

forces.FxF = params.mu*FzF*muxF;
forces.FyF = params.mu*FzF*muyF;
forces.FxR = params.mu*FzR*muxR;
forces.FyR = params.mu*FzR*muyR;

end

function z = robustDiv(num,den, epsilon)

if den == 0 
    if num ~= 0
        z = num/epsilon;
    else
        z = 0; %this is static friction let's say
    end
else
    z = num/den;
end  
    
end

function [torques] = brakeCom(forces, wF, wR, params, inputs)

% params has: R, gammaB, gammaM, maxTm, maxTb, maxThb 
% inputs: [delta, brake, handbrake, throttle]
% omega has: R, F
% forces has: FxF, FyF, FyR
% torques has: TbF, TbR, TmF, TmR

torques.TmF = 0 * params.maxTm;
torques.TmR = torques.TmF * params.gammaM;
torques.TmF = torques.TmF * (1-params.gammaM);

handbrake = inputs(3) * params.maxThb;
brake = inputs(2) * params.maxTb;


TbF = 0;
TbR = 0;
 
if brake > 0
   
    if wF ~= 0
        TbF = - brake * (1-params.gammaB);
    else
        TbF = forces.FxF * params.R;
    end
    
    if wR ~= 0
        TbR = TbR - brake * params.gammaB;
    else
        TbR = forces.FxR * params.R;
    end
end

if handbrake > 0
   
    if wR ~= 0
        TbR = TbR - handbrake;
    else
        TbR = forces.FxR * params.R;
    end   
end
   

torques.TbF = TbF;

 
torques.TbR = TbR;



end





