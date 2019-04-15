function [obstacles, paramsObst, xLimDown, xLimUp, yLimDown, yLimUp] = getObstacles(name)


xLimDown = -10;
xLimUp = 100;
yLimDown = xLimDown;
yLimUp = 100;
paramsObst = struct('l', [], 'w', [], 'theta', [], 'offset', cell(1));
k = 0;
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [0; -3.5];
l = 20;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = 45*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 20;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = 0*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 20;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = -90*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 11;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;


theta = 0*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 10;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;


theta = 90*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 18;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = pi;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 5;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = 90*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k-1}(:,2);
l = 21;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

%%%

theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [0; 4.5];
l = 20;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = 45*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 20;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = 0*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 19;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = 0*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 2;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

theta = 90*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k-1}(:,2);
l = 20;
w = 1;
obstPoly = A*[0; 0] + offset;
obstPoly = [obstPoly, A*[l; 0]+offset];
obstPoly = [obstPoly, A*[l; -w]+offset];
obstPoly = [obstPoly, A*[0; -w]+offset];
k = k+1;
obstacles{k} = obstPoly;
paramsObst.l(k) = l;
paramsObst.w(k) = w;
paramsObst.theta(k) = theta;
paramsObst.offset{k} = offset;

    





end