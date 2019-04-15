function [obstacles, paramsObst, xLimDown, xLimUp, yLimDown, yLimUp] = getObstacles(vector)



xLimDown = -10;
xLimUp = 140;
yLimDown = -20;
yLimUp = 20;
paramsObst = struct('l', [], 'w', [], 'theta', [], 'offset', cell(1));
k = 0;
%% Section 1
% right boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [0; -0.9225];
l = 15;
w = 0.1;
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

%left  boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [0; 0.9225+0.1];
l = 15;
w = 0.1;
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


%% Section 2
% Horrizontal right boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [15; -0.9225];
l = 30;
w = 0.1;
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

%horizontal left  boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [15; 0.995+0.1+3.5];
l = 30;
w = 0.1;
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

% Verticla right boarders
theta = pi/2;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [15+30; -0.995];
l = 3.5;
w = 0.1;
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

%verical left  boarders
theta = pi/2;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [15; 0.9225+0.1];
l = 3.5;
w = 0.1;
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
%% Section 3
% right boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [15+30; 3.5-0.995];
l = 25;
w = 0.1;
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

%left  boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [15+30; 0.995+0.1+3.5];
l = 25;
w = 0.1;
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
%% Section 4
% Horrizontal right boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [70; -1.0675];
l = 25;
w = 0.1;
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

%horizontal left  boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [70; 0.995+0.1+3.5];
l = 25;
w = 0.1;
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

% Verticla right boarders
theta = pi/2;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [70; -1.0675];
l = 3.5;
w = 0.1;
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

%verical left  boarders
theta = pi/2;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [95; 1.0675+0.1];
l = 3.5;
w = 0.1;
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
%% Section 5
% right boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [95; -1.0675];
l = 30;
w = 0.1;
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

%left  boarders
theta = 0;
A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
offset = [95; 1.0675+0.1];
l = 30;
w = 0.1;
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
% %Virtual obstacle
% if F1_Distance > 15
%     
%     theta = 0;
%     A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
%     offset = [0; 3.5];
%     l = F1_Distance-15;
%     w = 2.5;
%     obstPoly = A*[0; 0] + offset;
%     obstPoly = [obstPoly, A*[l; 0]+offset];
%     obstPoly = [obstPoly, A*[l; -w]+offset];
%     obstPoly = [obstPoly, A*[0; -w]+offset];
%     k = k+1;
%     obstacles{k} = obstPoly;
%     paramsObst.l(k) = l;
%     paramsObst.w(k) = w;
%     paramsObst.theta(k) = theta;
%     paramsObst.offset{k} = offset;
% end
% 
%     theta = 0;
%     A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
%     offset = [F1_Distance+6; -0.5];
%     l = 20;
%     w = 2.5;
%     obstPoly = A*[0; 0] + offset;
%     obstPoly = [obstPoly, A*[l; 0]+offset];
%     obstPoly = [obstPoly, A*[l; -w]+offset];
%     obstPoly = [obstPoly, A*[0; -w]+offset];
%     k = k+1;
%     obstacles{k} = obstPoly;
%     paramsObst.l(k) = l;
%     paramsObst.w(k) = w;
%     paramsObst.theta(k) = theta;
%     paramsObst.offset{k} = offset;
% 
% % theta = 180*pi/180;
% % A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
% % offset = obstacles{k}(:,2);
% % l = 35;
% % w = 1;
% % obstPoly = A*[0; 0] + offset;
% % obstPoly = [obstPoly, A*[l; 0]+offset];
% % obstPoly = [obstPoly, A*[l; -w]+offset];
% % obstPoly = [obstPoly, A*[0; -w]+offset];
% % k = k+1;
% % obstacles{k} = obstPoly;
% % paramsObst.l(k) = l;
% % paramsObst.w(k) = w;
% % paramsObst.theta(k) = theta;
% % paramsObst.offset{k} = offset;
% % 
% % theta = 0;
% % A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
% % offset = [0; 5.5];
% % l = 22;
% % w = 1;
% % obstPoly = A*[0; 0] + offset;
% % obstPoly = [obstPoly, A*[l; 0]+offset];
% % obstPoly = [obstPoly, A*[l; -w]+offset];
% % obstPoly = [obstPoly, A*[0; -w]+offset];
% % k = k+1;
% % obstacles{k} = obstPoly;
% % paramsObst.l(k) = l;
% % paramsObst.w(k) = w;
% % paramsObst.theta(k) = theta;
% % paramsObst.offset{k} = offset;
% 
% 
% 
%         
% 
%     
% 
% 
% 


end