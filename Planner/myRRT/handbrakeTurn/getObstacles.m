function [obstacles, paramsObst, xLimDown, xLimUp, yLimDown, yLimUp] = getObstacles(name)


xLimDown = -10;
xLimUp = 180;
yLimDown = xLimDown;
yLimUp = 120;
paramsObst = struct('l', [], 'w', [], 'theta', [], 'offset', cell(1));
k = 0;
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [0; -5];
l = 30;
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

theta = 30*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 30;
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


theta = 60*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 30;
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


theta = 60*pi/180;
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


theta = 30*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 38;
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
l = 65;
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
l = 13;
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

theta = 180*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 70;
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







%%%%%%%
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [0; 11];
l = 30;
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

theta = 30*pi/180;
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


theta = 60*pi/180;
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


theta = 90*pi/180;
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


theta = 60*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 30;
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


theta = 30*pi/180;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = obstacles{k}(:,2);
l = 30;
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
l = 41.7;
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