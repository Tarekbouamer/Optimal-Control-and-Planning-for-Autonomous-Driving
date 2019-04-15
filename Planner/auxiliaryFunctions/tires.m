function [forces] = tires(Ux, Uy, wF, wR, delta, r, params )


% params has: lF, lR, R,m,g,mu,h, B, C
% forces has: FxF, FyF, FxR, FyR

eps = 1e-4;

UxF = Ux * cos(delta) + Uy * sin(delta) + r * params.lF * sin(delta);
UyF = -Ux * sin(delta) + Uy * cos(delta) + r * params.lF * cos(delta);
UxR = Ux;
UyR = Uy - params.lR * r;



SxF = robustDiv2(UxF-params.R*wF,params.R*wF, eps);
SyF = (1+SxF) * robustDiv2(UyF,UxF,eps);
SxR = robustDiv2(UxR-params.R*wR,params.R*wR,eps);
SyR = (1+SxR) * robustDiv2(UyR,UxR,eps);

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

function z = robustDiv2(num,den, epsilon)

if den == 0 
    if abs(num) > epsilon
        z = num/epsilon;
    else
        z = 0; %this is static friction let's say
    end
else
    z = num/den;
end  
        
end







