function [ nextState, nextStateInt ] = evolve1ms( currentStateInt, inputs, params)

% currentState is a vector [Ux Uy r Ksi x y wF wR]
% nextState is avector [Ux Uy r Ksi x y wF wR]
% units [m/s m/s rad/s/s rad m m rad/s rad/s]

%inputs is a vector
% params is a structure [delta brake handbrake throttle]
% units [rad % % %], & is in [0,1]

inputs(1) = saturation(inputs(1), -params.maxDelta, params.maxDelta);
inputs(2) = saturation(inputs(2), 0, 1);
inputs(3) = saturation(inputs(3), 0, 1);
inputs(4) = saturation(inputs(4), 0, 1);


if currentStateInt(7) < 0
    currentStateInt(7) = 0;
end

if currentStateInt(8) < 0;
    currentStateInt(8) = 0;
end

% time step
dt = 0.001;

% Euler
 nextStateInt = currentStateInt + dt*f(currentStateInt, inputs, params);

% Runge Kutta 4th order
% k1 = f(currentStateInt, inputs, params);
% k2 = f(currentStateInt + dt*k1/2, inputs, params);
% k3 = f(currentStateInt + dt*k2/2, inputs, params);
% k4 = f(currentStateInt + dt*k3, inputs, params);
% nextStateInt = currentStateInt + dt/6*(k1+ 2*k2 +2*k3 +k4);

if nextStateInt(7) < 0
    nextStateInt(7) = 0;
end

if nextStateInt(8) < 0;
    nextStateInt(8) = 0;
end

nextState = [deadZone(nextStateInt(1),-params.Dz1, params.Dz1);...
    deadZone(nextStateInt(2),-params.Dz1, params.Dz1);...
    deadZone(nextStateInt(3),-params.Dz2, params.Dz2);...
    nextStateInt(4:end)];



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

end

function y = saturation(x, low,high)

if x > high
    y = high;
else if x < low
        y = low;
    else
        y = x;
    end
end

end

function [dX] = f(states, inputs, params)

% params is a structure others are vectors
% state vector [Ux Uy r Ksi x y wF wR]
% input vector [delta brake handbrake throttle]

states(1) = deadZone(states(1), -params.Dz1, params.Dz1);
states(2) = deadZone(states(2), -params.Dz1, params.Dz1);
states(3) = deadZone(states(3), -params.Dz2, params.Dz2);
if states(7) < 0
    states(7) = 0;
end

if states(8) < 0
    states(8) = 0;
end


rollFric = params.m*params.g*params.muRoll;

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