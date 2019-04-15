function [obstacles, paramsObst, xLimDown, xLimUp, yLimDown, yLimUp] = obstacles_handbrakeParkingPrimitive()

paramsObst = struct('l', [], 'w', [], 'theta', [], 'offset', cell(1));
xLimUp = 50;
xLimDown = -50;
yLimUp = 55;
yLimDown = 10;

xCoorObst = (xLimUp + xLimDown)/2 + 10;
yCoorObst = 50;
lF = 1.915; % length
lR = 2.835; % width
width = 1.916; 
wPark = 1.5*width;
lPark = 1.2*(lF + lR);
% obstacle coordinates
[X,Y] = obstVert([xLimDown, xLimUp], [lPark, wPark], [xCoorObst yCoorObst]);
obstPoly = [X; Y];
obstacles{1} = obstPoly;


end