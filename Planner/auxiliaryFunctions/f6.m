function [f0] = f(states0, inputs0, params, FyF0, FyR0)

% states [Ux0 Uy0 r0 ksi0 x0 y0]'
% inputs [delta FxF FxR]'

Ux0 = states0(1) + 1e-4; %Ux0 mustn't be 0
Uy0 = states0(2);
r0 = states0(3);
ksi0 = states0(4);
% x0 = states(5);
% y0 = states(6);

delta0 = inputs0(1);
FxF0 = inputs0(2);
FxR0 = inputs0(3);

% 
FyF0 = -params.mu*params.FzF*sin(params.C*atan(params.B*(atan((Uy0 + params.lF*r0)/Ux0) - delta0)));
FyR0 = -params.mu*params.FzR*sin(params.C*atan(params.B*atan( (Uy0 - params.lR*r0)/Ux0 )));

du = 1/params.m * (FxF0*cos(delta0) - FyF0*sin(delta0) + FxR0) + Uy0*r0;
dv = 1/params.m * (FxF0*sin(delta0) + FyF0*cos(delta0) + FyR0) - Ux0*r0;
dr = 1/params.Iz * (params.lF*(FxF0*sin(delta0) + FyF0*cos(delta0)) - params.lR*FyR0);
dksi = r0;
dx = Ux0*cos(ksi0) - Uy0*sin(ksi0);
dy = Ux0*sin(ksi0) + Uy0*cos(ksi0);

f0 = [du dv dr dksi dx dy]';