clc
clear all
close all
addpath('../../collisionCheckFunctions');
addpath('../../auxiliaryFunctions');
addpath('../../myRRT');
load('tree');
usePlannerOutputs = 1;
modifyParsfile(1);
uInit = zeros(13,1);
intState = zeros(5,1);
maxThrottle = 0.5;
 set_param('maneuvers', 'StopTime', 'T')
sim('maneuvers'); 
trajectory = [x y ksi];
    trajectory = downsample(trajectory,downsampleFactor);
    trajectory = trajectory';
plot(x,y,'g', 'LineWidth',2)
createTestingGroundCarSim


%%
for i=1:5:length(trajectory(1,:))
        draw_car( trajectory(1,i),trajectory(2,i),trajectory(3,i),lF, lR,width,1,translucency);
        xlim([xLimDown xLimUp])
        ylim([yLimDown yLimUp])   
 end
