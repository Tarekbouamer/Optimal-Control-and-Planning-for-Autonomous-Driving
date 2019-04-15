function [X,Y] = obstVert( figureLimitsX, parkDim, coor)

xLimDown = figureLimitsX(1);
xLimUp = figureLimitsX(2);
yCoorObst = coor(2);
xCoorObst = coor(1);

lPark = parkDim(1)/2;
wPark = parkDim(2);
k = 5;

vertex1 = xLimDown*k;
vertex2 = xCoorObst - lPark;
vertex3 = xCoorObst - lPark;    
vertex4 = xCoorObst + lPark;
vertex5 = xCoorObst + lPark;
vertex6 = xLimUp*k;

X = [vertex1 vertex2 vertex3 vertex4 vertex5 vertex6 xLimUp*k xLimDown*k];

vertex1 = yCoorObst;
vertex2 = yCoorObst;
vertex3 = yCoorObst + wPark;    
vertex4 = yCoorObst + wPark;
vertex5 = yCoorObst;
vertex6 = yCoorObst;

Y = [vertex1 vertex2 vertex3 vertex4 vertex5 vertex6 yCoorObst*k yCoorObst*k];


end