% matrices and shit

function [A,B,f0] = linearize(states0, inputs0, params, FyF0, FyR0)

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
FyR0 = -params.mu*params.FzR*sin(params.C*atan(params.B*atan((Uy0 - params.lR*r0)/Ux0 )));

C11 = -params.mu*params.FzF*cos(params.C*atan(params.B*(atan((Uy0 + params.lF*r0)/Ux0) - delta0)))*params.C...
    /(1 + (params.B*(atan((Uy0 + params.lF*r0)/Ux0) - delta0))^2 )*params.B...
    *Ux0^2/(Ux0^2+(Uy0 + r0*params.lF)^2);
C12 = params.mu*params.FzF*cos(params.C*atan(params.B*(atan((Uy0 + params.lF*r0)/Ux0) - delta0)))*params.C...
    /(1 + (params.B*(atan((Uy0 + params.lF*r0)/Ux0) - delta0))^2 )*params.B;
C2 = -params.mu*params.FzR*cos(params.C*atan(params.B*atan((Uy0 - params.lR*r0)/Ux0)))*params.C...
    /(1 + (params.B*atan((Uy0 - params.lR*r0)/Ux0))^2 )*params.B...
    *Ux0^2/(Ux0^2+(Uy0 - r0*params.lR)^2);

row1 = [(1/params.m*sin(delta0)*C11*(Uy0 + params.lF * r0)/(Ux0)^2), ...
    (r0 - 1/params.m*sin(delta0)*C11/Ux0),...
    (Uy0 -1/params.m*sin(delta0)*C11*params.lF/Ux0),...
    0, 0, 0];
row2 = 1/params.m*[(-r0*params.m - cos(delta0)*C11*(Uy0+params.lF*r0)/(Ux0)^2 - C2*(Uy0-params.lR*r0)/Ux0^2 ),...
    cos(delta0)*C11/Ux0 + C2/Ux0,...
    (-Ux0*params.m + cos(delta0)*C11*params.lF/Ux0 - C2*params.lR/Ux0),...
    0, 0, 0];
row3 = 1/params.Iz*[(-params.lF*cos(delta0)*C11*(Uy0+params.lF*r0)/(Ux0)^2 + params.lR*C2*(Uy0 - params.lR*r0)/Ux0^2),...
    (params.lF*cos(delta0)*C11/Ux0 - params.lR*C2/Ux0),...
    (params.lF*cos(delta0)*C11*params.lF/Ux0 + params.lR*C2*params.lR/Ux0),...
    0, 0, 0];
row4 = [0, 0, 1, 0, 0, 0];
row5 = [cos(ksi0), -sin(ksi0), 0, (-Ux0*sin(ksi0) - Uy0*cos(ksi0)), 0, 0];
row6 = [sin(ksi0), cos(ksi0), 0, (Ux0*cos(ksi0) - Uy0*sin(ksi0)),0 ,0];

A = [row1; row2; row3; row4; row5; row6];


row1 = 1/params.m*[(-FxF0*sin(delta0)-FyF0*cos(delta0) - C12*sin(delta0)), cos(delta0), 1];
row2 = 1/params.m*[(FxF0*cos(delta0)-FyF0*sin(delta0) + cos(delta0)*C12), sin(delta0), 0];
row3 = 1/params.Iz*params.lF*[ (FxF0*cos(delta0) - FyF0*sin(delta0) + cos(delta0)*C12), sin(delta0), 0 ];
row4 = [0, 0, 0];
row5 = [0, 0 ,0];
row6 = [0, 0, 0];

B = [row1; row2; row3; row4; row5; row6];

du = 1/params.m * (FxF0*cos(delta0) - FyF0*sin(delta0) + FxR0) + Uy0*r0;
dv = 1/params.m * (FxF0*sin(delta0) + FyF0*cos(delta0) + FyR0) - Ux0*r0;
dr = 1/params.Iz * (params.lF*(FxF0*sin(delta0) + FyF0*cos(delta0)) - params.lR*FyR0);
dksi = r0;
dx = Ux0*cos(ksi0) - Uy0*sin(ksi0);
dy = Ux0*sin(ksi0) + Uy0*cos(ksi0);

f0 = [du dv dr dksi dx dy]';

end