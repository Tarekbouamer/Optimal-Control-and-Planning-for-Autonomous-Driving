function [obstacles, paramsObst, xLimDown, xLimUp, yLimDown, yLimUp] = obstacles_dummy()

xLimDown = -5;
xLimUp = 60;
yLimDown = -20;
yLimUp = 20;
paramsObst = struct('l', [], 'w', [], 'theta', [], 'offset', cell(1));

obstacles = {};




end