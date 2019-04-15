function [xb, xhb] = calcualteBrakingCommand (wR, wF, wRprev, wFprev, FxR, FxF, params,xbPrev, xhbPrev)


if FxR > 0
    FxR = 0;
end

if FxF > 0 
    FxF  = 0;
end

derF = (wF - wFprev)/params.T;
derR = (wR - wRprev)/params.T;

xb = -(params.Iw * derF + FxF*params.R)/(1-params.gammaB)/params.maxTb;

xhb = - (params.Iw * derR + FxR*params.R + params.gammaB*xb*params.maxTb)/params.maxThb;

if wF == 0
    xb = xbPrev;
end

if wR == 0
    xhb = xhbPrev;
end

if xb <0
    xb = 0;
end

if xb >1
    xb = 1;
end

if xhb <0
    xhb = 0;
end

if xhb >1
    xhb = 1;
end


end