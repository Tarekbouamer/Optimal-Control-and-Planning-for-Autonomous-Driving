% set ub obstacles

% clc
 clear all
 close all

addpath('collisionCheckFunctions');
addpath('auxiliaryFunctions');
addpath('myRRT');

rmpath('myRRT/hardLeftTurn');

%change provingGround string to change the course
initialize_parameters;

callAmesim;

provingGround = 'hardLeftTurn';
tau = 0.001;

if strcmp(provingGround, 'handbrakeTurn')
    addpath('myRRT/handbrakeTurn');
    radius = 5;
    maxThrottle = 0.5;
else if strcmp(provingGround, 'hardLeftTurn')
        addpath('myRRT/hardLeftTurn');
        radius = 2;
        maxThrottle = 5;

    else if strcmp(provingGround, 'gymkhana')
            addpath('myRRT/gymkhana');
            radius = 2;
            maxThrottle = 0.1;
        end
    end
end

[obstacles, paramsObst, xLimDown, xLimUp, yLimDown, yLimUp] = getObstacles();
nObst = length(obstacles);

translucency = 0.05;
axis equal
grid on
for i = 1:length(obstacles)
    obs_handle = fill(obstacles{i}(1,:),obstacles{i}(2,:),'r');
    alpha(obs_handle, 0.7);
    hold on
end
grid on
xlim([xLimDown xLimUp])
ylim([yLimDown yLimUp])

%% position of the Front and ADv cars

% [Cars, paramsCars ] = getCars();
% nCars = length(Cars);
% 
% for i = 1:length(Cars)
%     obs_handle = fill(Cars{i}(1,:),Cars{i}(2,:),'g');
%     alpha(obs_handle, 0.7);
%     hold on
% end

nObst = nObst;% + nCars;
obstacles = [obstacles] ;
%car dimensions in %m
lF = 1.056; % length
lR = 2.4-1.056; 
width = 1.45; 


% define start zone

[areas, primitives] = defineAreasAndPrimitives();

for i = 1:length(areas)
    handle = fill(areas{i}(1,:),areas{i}(2,:), round([rand(1) rand(1) rand(1)]));
    alpha(handle, 0.3);
end

% endgame
% poly = [0; 5.5];
 % poly = [poly [5; 5.5]];
 %  poly = [poly [5; 14.5]];
 %poly = [poly [0; 14.5]];
 
 % handle = fill(poly(1,:),poly(2,:), round([rand(1) rand(1) rand(1)]));
 % alpha(handle, 0.3);
 Status= false;
downsampleFactor = 1;
command = [0 0 0 0 0 0];
commandActual= [0 0 0 0 0 0];
usePlannerOutputs = 0;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% this needs to be set manually

% this is convention
speed = 90;
Ux0 = speed/3.6;
Uy0 = 0;
r0 = 0;
ksi0 = 0*pi/180;

x0 = -lF ;
y0 = 0;



w1L0 = speed/3.6/0.3;
w1R0 = speed/3.6/0.3;
w2L0 = speed/3.6/0.3;
w2R0 = speed/3.6/0.3;

 draw_car( x0,y0,ksi0,lF, lR, width,1,0.8);
  % x0 = 99.7181;
  % y0 = 92.3829;

%% Set initial values in AMESIM CAR
	ameputp(sname, car_param.vG_1   , Ux0  );
	ameputp(sname, car_param.vG_2   , 0  );
	ameputp(sname, car_param.vG_3   , 0  );
    
	ameputp(sname, car_param.OG_1   , x0  );
	ameputp(sname, car_param.OG_2   , y0  );  
	ameputp(sname, car_param.OG_3   , 0.584  ); 
    
	ameputp(sname, car_param.omeg_1   , 0  );  
	ameputp(sname, car_param.omeg_2   , 0  ); 
	ameputp(sname, car_param.omeg_3   , ksi0  ); 
    
	ameputp(sname, car_param.Eulerangle_1   , 0   );  
	ameputp(sname, car_param.Eulerangle_2   , 0  );  
	ameputp(sname, car_param.Eulerangle_3   , ksi0   );  
    
	ameputp(sname, car_param.vzrelavg      , 0    );          
	ameputp(sname, car_param.zrelavg       , 0    );          
	ameputp(sname, car_param.Wrelavg       , (w1L0)*(180/pi)     );        
	ameputp(sname, car_param.thetarelavg   , 0    );
    
	ameputp(sname, car_param.vzrelavd      , 0    );         
	ameputp(sname, car_param.zrelavd       , 0    );          
	ameputp(sname, car_param.Wrelavd       , (w1L0)*(180/pi)     );        
 	ameputp(sname, car_param.thetarelavd   , 0    ); 
    
	ameputp(sname, car_param.vzrelarrg     , 0    );        
	ameputp(sname, car_param.zrelarrg      , 0    );       
    ameputp(sname, car_param.Wrelarrg      , (w1L0)*(180/pi)    );       
	ameputp(sname, car_param.thetarelarrg  , 0    );
    
	ameputp(sname, car_param.vzrelarrd     , 0    );         
	ameputp(sname, car_param.zrelarrd      , 0    );         
	ameputp(sname, car_param.Wrelarrd      , (w1L0)*(180/pi)   );         
	ameputp(sname, car_param.thetarelarrd  , 0    );
    
	ameputp(sname, car_param.vycrav   , 0  );         
	ameputp(sname, car_param.ycrav   ,  0 );
    % F L
	ameputp(sname, car_param.WelastoR1_1_FL   ,  0 );
    ameputp(sname, car_param.WelastoR1_2_FL   ,  0 );
    ameputp(sname, car_param.WelastoR1_3_FL   ,  0 );
    
    ameputp(sname, car_param.THETAelastoR1_1_FL   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_2_FL   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_3_FL   ,  0 );
    
    ameputp(sname, car_param.VxelastoR1_FL   ,  0 );
    ameputp(sname, car_param.VyelastoR1_FL   ,  0 );
    ameputp(sname, car_param.XelastoR1_FL    ,  0 );
    ameputp(sname, car_param.YelastoR1_FL    ,  0 );
    
    % F R
	ameputp(sname, car_param.WelastoR1_1_FR   ,  0 );
    ameputp(sname, car_param.WelastoR1_2_FR   ,  0 );
    ameputp(sname, car_param.WelastoR1_3_FR   ,  0 );
    
    ameputp(sname, car_param.THETAelastoR1_1_FR   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_2_FR   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_3_FR   ,  0 );
    
    ameputp(sname, car_param.VxelastoR1_FR   ,  0 );
    ameputp(sname, car_param.VyelastoR1_FR   ,  0 );
    ameputp(sname, car_param.XelastoR1_FR    ,  0 );
    ameputp(sname, car_param.YelastoR1_FR    ,  0 );
     % R L
	ameputp(sname, car_param.WelastoR1_1_RL   ,  0 );
    ameputp(sname, car_param.WelastoR1_2_RL   ,  0 );
    ameputp(sname, car_param.WelastoR1_3_RL   ,  0 );
    
    ameputp(sname, car_param.THETAelastoR1_1_RL   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_2_RL   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_3_RL   ,  0 );
    
    ameputp(sname, car_param.VxelastoR1_RL   ,  0 );
    ameputp(sname, car_param.VyelastoR1_RL   ,  0 );
    ameputp(sname, car_param.XelastoR1_RL    ,  0 );
    ameputp(sname, car_param.YelastoR1_RL    ,  0 );
     % R R
	ameputp(sname, car_param.WelastoR1_1_RR   ,  0 );
    ameputp(sname, car_param.WelastoR1_2_RR   ,  0 );
    ameputp(sname, car_param.WelastoR1_3_RR   ,  0 );
    
    ameputp(sname, car_param.THETAelastoR1_1_RR   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_2_RR   ,  0 );
    ameputp(sname, car_param.THETAelastoR1_3_RR   ,  0 );
    
    ameputp(sname, car_param.VxelastoR1_RR   ,  0 );
    ameputp(sname, car_param.VyelastoR1_RR   ,  0 );
    ameputp(sname, car_param.XelastoR1_RR    ,  0 );
    ameputp(sname, car_param.YelastoR1_RR    ,  0 );
%%
% Read from Amesim Initial position of 70 states 
    [carName.vG_1, carValue.vG_1] = amegetp(sname, car_param.vG_1 );   carValue.vG_1 = str2double(carValue.vG_1) ;
    [carName.vG_2, carValue.vG_2] = amegetp(sname, car_param.vG_2 );   carValue.vG_2 = str2double(carValue.vG_2) ;
    [carName.vG_3, carValue.vG_3] = amegetp(sname, car_param.vG_3 );   carValue.vG_3 = str2double(carValue.vG_3) ;
    
    [carName.OG_1, carValue.OG_1] = amegetp(sname, car_param.OG_1 );   carValue.OG_1 = str2double(carValue.OG_1) ;
    [carName.OG_2, carValue.OG_2] = amegetp(sname, car_param.OG_2 );   carValue.OG_2 = str2double(carValue.OG_2) ;
    [carName.OG_3, carValue.OG_3] = amegetp(sname, car_param.OG_3 );   carValue.OG_3 = str2double(carValue.OG_3) ;
            
    [carName.omeg_1, carValue.omeg_1] = amegetp(sname, car_param.omeg_1 );   carValue.omeg_1 = str2double(carValue.omeg_1) ;
    [carName.omeg_2, carValue.omeg_2] = amegetp(sname, car_param.omeg_2 );   carValue.omeg_2 = str2double(carValue.omeg_2) ;
    [carName.omeg_3, carValue.omeg_3] = amegetp(sname, car_param.omeg_3 );   carValue.omeg_3 = str2double(carValue.omeg_3) ;
  
    [carName.Eulerangle_1, carValue.Eulerangle_1] = amegetp(sname, car_param.Eulerangle_1 );   carValue.Eulerangle_1 = str2double(carValue.Eulerangle_1) ;
    [carName.Eulerangle_2, carValue.Eulerangle_2] = amegetp(sname, car_param.Eulerangle_2 );   carValue.Eulerangle_2 = str2double(carValue.Eulerangle_2) ;
    [carName.Eulerangle_3, carValue.Eulerangle_3] = amegetp(sname, car_param.Eulerangle_3 );   carValue.Eulerangle_3 = str2double(carValue.Eulerangle_3) ;
    
    [carName.vzrelavg   , carValue.vzrelavg   ] = amegetp(sname, car_param.vzrelavg    );   carValue.vzrelavg    = str2double(carValue.vzrelavg   ) ;
    [carName.zrelavg    , carValue.zrelavg    ] = amegetp(sname, car_param.zrelavg     );   carValue.zrelavg     = str2double(carValue.zrelavg    ) ;
    [carName.Wrelavg    , carValue.Wrelavg    ] = amegetp(sname, car_param.Wrelavg     );   carValue.Wrelavg     = str2double(carValue.Wrelavg    ) ;
    [carName.thetarelavg, carValue.thetarelavg] = amegetp(sname, car_param.thetarelavg );   carValue.thetarelavg = str2double(carValue.thetarelavg) ;

    [carName.vzrelavd   , carValue.vzrelavd   ] = amegetp(sname, car_param.vzrelavd    );   carValue.vzrelavd    = str2double(carValue.vzrelavd   ) ;
    [carName.zrelavd    , carValue.zrelavd    ] = amegetp(sname, car_param.zrelavd     );   carValue.zrelavd     = str2double(carValue.zrelavd    ) ;
    [carName.Wrelavd    , carValue.Wrelavd    ] = amegetp(sname, car_param.Wrelavd     );   carValue.Wrelavd     = str2double(carValue.Wrelavd    ) ;
    [carName.thetarelavd, carValue.thetarelavd] = amegetp(sname, car_param.thetarelavd );   carValue.thetarelavd = str2double(carValue.thetarelavd) ;
    
    [carName.vzrelarrg   , carValue.vzrelarrg   ] = amegetp(sname, car_param.vzrelarrg    );   carValue.vzrelarrg    = str2double(carValue.vzrelarrg   ) ;
    [carName.zrelarrg    , carValue.zrelarrg    ] = amegetp(sname, car_param.zrelarrg     );   carValue.zrelarrg     = str2double(carValue.zrelarrg    ) ;
    [carName.Wrelarrg    , carValue.Wrelarrg    ] = amegetp(sname, car_param.Wrelarrg     );   carValue.Wrelarrg     = str2double(carValue.Wrelarrg    ) ;
    [carName.thetarelarrg, carValue.thetarelarrg] = amegetp(sname, car_param.thetarelarrg );   carValue.thetarelarrg = str2double(carValue.thetarelarrg) ;

    [carName.vzrelarrd   , carValue.vzrelarrd   ] = amegetp(sname, car_param.vzrelarrd    );   carValue.vzrelarrd    = str2double(carValue.vzrelarrd   ) ;
    [carName.zrelarrd    , carValue.zrelarrd    ] = amegetp(sname, car_param.zrelarrd     );   carValue.zrelarrd     = str2double(carValue.zrelarrd    ) ;
    [carName.Wrelarrd    , carValue.Wrelarrd    ] = amegetp(sname, car_param.Wrelarrd     );   carValue.Wrelarrd     = str2double(carValue.Wrelarrd    ) ;
    [carName.thetarelarrd, carValue.thetarelarrd] = amegetp(sname, car_param.thetarelarrd );   carValue.thetarelarrd = str2double(carValue.thetarelarrd) ;
    
    [carName.vycrav    , carValue.vycrav    ] = amegetp(sname, car_param.vycrav     );   carValue.vycrav     = str2double(carValue.vycrav    ) ;
    [carName.ycrav     , carValue.ycrav     ] = amegetp(sname, car_param.ycrav      );   carValue.ycrav      = str2double(carValue.ycrav     ) ;
% FL
    [carName.WelastoR1_1_FL, carValue.WelastoR1_1_FL] = amegetp(sname, car_param.WelastoR1_1_FL );   carValue.WelastoR1_1_FL = str2double(carValue.WelastoR1_1_FL) ;
    [carName.WelastoR1_2_FL, carValue.WelastoR1_2_FL] = amegetp(sname, car_param.WelastoR1_2_FL );   carValue.WelastoR1_2_FL = str2double(carValue.WelastoR1_2_FL) ;
    [carName.WelastoR1_3_FL, carValue.WelastoR1_3_FL] = amegetp(sname, car_param.WelastoR1_3_FL );   carValue.WelastoR1_3_FL = str2double(carValue.WelastoR1_3_FL) ;
    
    [carName.THETAelastoR1_1_FL, carValue.THETAelastoR1_1_FL] = amegetp(sname, car_param.THETAelastoR1_1_FL );   carValue.THETAelastoR1_1_FL = str2double(carValue.THETAelastoR1_1_FL) ;
    [carName.THETAelastoR1_2_FL, carValue.THETAelastoR1_2_FL] = amegetp(sname, car_param.THETAelastoR1_2_FL );   carValue.THETAelastoR1_2_FL = str2double(carValue.THETAelastoR1_2_FL) ;
    [carName.THETAelastoR1_3_FL, carValue.THETAelastoR1_3_FL] = amegetp(sname, car_param.THETAelastoR1_3_FL );   carValue.THETAelastoR1_3_FL = str2double(carValue.THETAelastoR1_3_FL) ;
 
    [carName.VxelastoR1_FL, carValue.VxelastoR1_FL] = amegetp(sname, car_param.VxelastoR1_FL );   carValue.VxelastoR1_FL = str2double(carValue.VxelastoR1_FL) ;
    [carName.VyelastoR1_FL, carValue.VyelastoR1_FL] = amegetp(sname, car_param.VyelastoR1_FL );   carValue.VyelastoR1_FL = str2double(carValue.VyelastoR1_FL) ;
    [carName.XelastoR1_FL , carValue.XelastoR1_FL ] = amegetp(sname, car_param.XelastoR1_FL  );   carValue.XelastoR1_FL  = str2double(carValue.XelastoR1_FL ) ;
    [carName.YelastoR1_FL , carValue.YelastoR1_FL ] = amegetp(sname, car_param.YelastoR1_FL  );   carValue.YelastoR1_FL  = str2double(carValue.YelastoR1_FL ) ;
    
% FR
    [carName.WelastoR1_1_FR, carValue.WelastoR1_1_FR] = amegetp(sname, car_param.WelastoR1_1_FR );   carValue.WelastoR1_1_FR = str2double(carValue.WelastoR1_1_FR) ;
    [carName.WelastoR1_2_FR, carValue.WelastoR1_2_FR] = amegetp(sname, car_param.WelastoR1_2_FR );   carValue.WelastoR1_2_FR = str2double(carValue.WelastoR1_2_FR) ;
    [carName.WelastoR1_3_FR, carValue.WelastoR1_3_FR] = amegetp(sname, car_param.WelastoR1_3_FR );   carValue.WelastoR1_3_FR = str2double(carValue.WelastoR1_3_FR) ;
    
    [carName.THETAelastoR1_1_FR, carValue.THETAelastoR1_1_FR] = amegetp(sname, car_param.THETAelastoR1_1_FR );   carValue.THETAelastoR1_1_FR = str2double(carValue.THETAelastoR1_1_FR) ;
    [carName.THETAelastoR1_2_FR, carValue.THETAelastoR1_2_FR] = amegetp(sname, car_param.THETAelastoR1_2_FR );   carValue.THETAelastoR1_2_FR = str2double(carValue.THETAelastoR1_2_FR) ;
    [carName.THETAelastoR1_3_FR, carValue.THETAelastoR1_3_FR] = amegetp(sname, car_param.THETAelastoR1_3_FR );   carValue.THETAelastoR1_3_FR = str2double(carValue.THETAelastoR1_3_FR) ;
 
    [carName.VxelastoR1_FR, carValue.VxelastoR1_FR] = amegetp(sname, car_param.VxelastoR1_FR );   carValue.VxelastoR1_FR = str2double(carValue.VxelastoR1_FR) ;
    [carName.VyelastoR1_FR, carValue.VyelastoR1_FR] = amegetp(sname, car_param.VyelastoR1_FR );   carValue.VyelastoR1_FR = str2double(carValue.VyelastoR1_FR) ;
    [carName.XelastoR1_FR , carValue.XelastoR1_FR ] = amegetp(sname, car_param.XelastoR1_FR  );   carValue.XelastoR1_FR  = str2double(carValue.XelastoR1_FR ) ;
    [carName.YelastoR1_FR , carValue.YelastoR1_FR ] = amegetp(sname, car_param.YelastoR1_FR  );   carValue.YelastoR1_FR  = str2double(carValue.YelastoR1_FR ) ;
 
 % RL
    [carName.WelastoR1_1_RL, carValue.WelastoR1_1_RL] = amegetp(sname, car_param.WelastoR1_1_RL );   carValue.WelastoR1_1_RL = str2double(carValue.WelastoR1_1_RL) ;
    [carName.WelastoR1_2_RL, carValue.WelastoR1_2_RL] = amegetp(sname, car_param.WelastoR1_2_RL );   carValue.WelastoR1_2_RL = str2double(carValue.WelastoR1_2_RL) ;
    [carName.WelastoR1_3_RL, carValue.WelastoR1_3_RL] = amegetp(sname, car_param.WelastoR1_3_RL );   carValue.WelastoR1_3_RL = str2double(carValue.WelastoR1_3_RL) ;
    
    [carName.THETAelastoR1_1_RL, carValue.THETAelastoR1_1_RL] = amegetp(sname, car_param.THETAelastoR1_1_RL );   carValue.THETAelastoR1_1_RL = str2double(carValue.THETAelastoR1_1_RL) ;
    [carName.THETAelastoR1_2_RL, carValue.THETAelastoR1_2_RL] = amegetp(sname, car_param.THETAelastoR1_2_RL );   carValue.THETAelastoR1_2_RL = str2double(carValue.THETAelastoR1_2_RL) ;
    [carName.THETAelastoR1_3_RL, carValue.THETAelastoR1_3_RL] = amegetp(sname, car_param.THETAelastoR1_3_RL );   carValue.THETAelastoR1_3_RL = str2double(carValue.THETAelastoR1_3_RL) ;
 
    [carName.VxelastoR1_RL, carValue.VxelastoR1_RL] = amegetp(sname, car_param.VxelastoR1_RL );   carValue.VxelastoR1_RL = str2double(carValue.VxelastoR1_RL) ;
    [carName.VyelastoR1_RL, carValue.VyelastoR1_RL] = amegetp(sname, car_param.VyelastoR1_RL );   carValue.VyelastoR1_RL = str2double(carValue.VyelastoR1_RL) ;
    [carName.XelastoR1_RL , carValue.XelastoR1_RL ] = amegetp(sname, car_param.XelastoR1_RL  );   carValue.XelastoR1_RL  = str2double(carValue.XelastoR1_RL ) ;
    [carName.YelastoR1_RL , carValue.YelastoR1_RL ] = amegetp(sname, car_param.YelastoR1_RL  );   carValue.YelastoR1_RL  = str2double(carValue.YelastoR1_RL ) ;
    
% RR
    [carName.WelastoR1_1_RR, carValue.WelastoR1_1_RR] = amegetp(sname, car_param.WelastoR1_1_RR );   carValue.WelastoR1_1_RR = str2double(carValue.WelastoR1_1_RR) ;
    [carName.WelastoR1_2_RR, carValue.WelastoR1_2_RR] = amegetp(sname, car_param.WelastoR1_2_RR );   carValue.WelastoR1_2_RR = str2double(carValue.WelastoR1_2_RR) ;
    [carName.WelastoR1_3_RR, carValue.WelastoR1_3_RR] = amegetp(sname, car_param.WelastoR1_3_RR );   carValue.WelastoR1_3_RR = str2double(carValue.WelastoR1_3_RR) ;
    
    [carName.THETAelastoR1_1_RR, carValue.THETAelastoR1_1_RR] = amegetp(sname, car_param.THETAelastoR1_1_RR );   carValue.THETAelastoR1_1_RR = str2double(carValue.THETAelastoR1_1_RR) ;
    [carName.THETAelastoR1_2_RR, carValue.THETAelastoR1_2_RR] = amegetp(sname, car_param.THETAelastoR1_2_RR );   carValue.THETAelastoR1_2_RR = str2double(carValue.THETAelastoR1_2_RR) ;
    [carName.THETAelastoR1_3_RR, carValue.THETAelastoR1_3_RR] = amegetp(sname, car_param.THETAelastoR1_3_RR );   carValue.THETAelastoR1_3_RR = str2double(carValue.THETAelastoR1_3_RR) ;
 
    [carName.VxelastoR1_RR, carValue.VxelastoR1_RR] = amegetp(sname, car_param.VxelastoR1_RR );   carValue.VxelastoR1_RR = str2double(carValue.VxelastoR1_RR) ;
    [carName.VyelastoR1_RR, carValue.VyelastoR1_RR] = amegetp(sname, car_param.VyelastoR1_RR );   carValue.VyelastoR1_RR = str2double(carValue.VyelastoR1_RR) ;
    [carName.XelastoR1_RR , carValue.XelastoR1_RR ] = amegetp(sname, car_param.XelastoR1_RR  );   carValue.XelastoR1_RR  = str2double(carValue.XelastoR1_RR ) ;
    [carName.YelastoR1_RR , carValue.YelastoR1_RR ] = amegetp(sname, car_param.YelastoR1_RR  );   carValue.YelastoR1_RR  = str2double(carValue.YelastoR1_RR ) ;

    %%    
% initialize zero node
nodes = struct('state',cell(1,1), 't', [], 'weight', [], 'x', [], 'y', [],...
    'preceedingEdge', [], 'leaf', [], 'preceedingNode', [], 'crashCount', [],...
    'handle', [], 'intState', cell(1,1));
nodes.state{1} = [carValue.vG_1 carValue.vG_2 carValue.vG_3 carValue.OG_1 carValue.OG_2 carValue.OG_3 ...
                  carValue.omeg_1 carValue.omeg_2 carValue.omeg_3 carValue.Eulerangle_1 carValue.Eulerangle_2 carValue.Eulerangle_3 ...
                  carValue.vzrelavg         carValue.zrelavg         carValue.Wrelavg       carValue.thetarelavg ...
                  carValue.vzrelavd         carValue.zrelavd         carValue.Wrelavd       carValue.thetarelavd ...
                  carValue.vzrelarrg        carValue.zrelarrg        carValue.Wrelarrg      carValue.thetarelarrg ...
                  carValue.vzrelarrd        carValue.zrelarrd        carValue.Wrelarrd      carValue.thetarelarrd ...
                  carValue.vycrav        carValue.ycrav ...
                  carValue.WelastoR1_1_FL         carValue.WelastoR1_2_FL           carValue.WelastoR1_3_FL ...
                  carValue.THETAelastoR1_1_FL     carValue.THETAelastoR1_2_FL       carValue.THETAelastoR1_3_FL ...  
                  carValue.VxelastoR1_FL          carValue.VyelastoR1_FL            carValue.XelastoR1_FL            carValue.YelastoR1_FL ...
                  carValue.WelastoR1_1_FR         carValue.WelastoR1_2_FR           carValue.WelastoR1_3_FR ...
                  carValue.THETAelastoR1_1_FR     carValue.THETAelastoR1_2_FR       carValue.THETAelastoR1_3_FR ...  
                  carValue.VxelastoR1_FR          carValue.VyelastoR1_FR            carValue.XelastoR1_FR            carValue.YelastoR1_FR ...
                  carValue.WelastoR1_1_RL         carValue.WelastoR1_2_RL           carValue.WelastoR1_3_RL ...
                  carValue.THETAelastoR1_1_RL     carValue.THETAelastoR1_2_RL       carValue.THETAelastoR1_3_RL ...  
                  carValue.VxelastoR1_RL          carValue.VyelastoR1_RL            carValue.XelastoR1_RL            carValue.YelastoR1_RL ...
                  carValue.WelastoR1_1_RR         carValue.WelastoR1_2_RR           carValue.WelastoR1_3_RR ...
                  carValue.THETAelastoR1_1_RR     carValue.THETAelastoR1_2_RR       carValue.THETAelastoR1_3_RR ...  
                  carValue.VxelastoR1_RR          carValue.VyelastoR1_RR            carValue.XelastoR1_RR            carValue.YelastoR1_RR ]';   % Push all 70 States values
nodes.t = 0;
nodes.weight = 1;
nodes.x = x0;
nodes.y = y0;
numNodes = 1;
nodes.preceedingEdge = 1;
nodes.leaf = true;
nodes.preceedingNode = -1;
nodes.crashCount = 0;
nodes.intState{1} = zeros(5,1);
nodes.handle = plot(x0, y0, 'r');

% initialize zero edge
edges = struct('beginNode', [], 'endNode', [], 'dt', [], 'inputs', cell(1,1), 'u', cell(1,1), 'handle', [], 'realInputs', cell(1,1));
edges.beginNode = -1;
edges.endNode = 1;
edges.dt = 0;
edges.inputs{1} = zeros(5,1);
edges.u{1}  = zeros(13,1);
edges.handle = plot(x0, y0, 'b');
edges.realInputs{1} = zeros(5,1);
numEdges = 1;

numIter = 0;


%%
open ('maneuvers3');
set_param('maneuvers3', 'StopTime', 'T')
modifyParsfile(1);

timeCol = 0;
timeFile = 0;
timeSim= 0;
timeNodes = 0;
timeTotal = 0;
counter = 0;
deletedNodes = [];
deletedEdges = [];
numDeleted = 0;
useYawController = 0;
useSpeedController = 0;
ksiRef = 0;
UxRef = 50;
token1 = tic;


while numIter <100000

    if counter > 0
        counter = counter - 1;
    else
        idNode = drawRandomSample(1./[nodes.weight], deletedNodes);
    end
    h2 = plot(nodes.x(idNode), nodes.y(idNode), 'rx','Linewidth',3);
   
    [primitiveStart, idPrimitiveStart] = checkArea(areas, nodes.x(idNode), nodes.y(idNode), primitives);
    [u, T, t, controlParams] = getCommands(primitiveStart, nodes.state{idNode});
    

%     car.Ux0 = nodes.state{idNode} (1,end);
%     car.Uy0 = nodes.state{idNode} (2,end);
%     car.r0 = nodes.state{idNode} (3,end); 
%     car.ksi0 = nodes.state{idNode} (4,end); 
%     car.x0 = nodes.state{idNode} (5,end); 
%     car.y0 = nodes.state{idNode} (6,end);
%     car.w1L0 =nodes.state{idNode} (7,end); 
%     car.w1R0 = nodes.state{idNode} (8,end);
%     car.w2L0 = nodes.state{idNode} (9,end);
%     car.w2R0 = nodes.state{idNode} (10,end);

    carValue.vG_1                =  nodes.state{idNode} (1,end);            ameputp(sname, car_param.vG_1   , carValue.vG_1  );
    carValue.vG_2                =  nodes.state{idNode} (2,end);            ameputp(sname, car_param.vG_2   , carValue.vG_2  );
    carValue.vG_3                =  nodes.state{idNode} (3,end);            ameputp(sname, car_param.vG_3   , carValue.vG_3  );
    
    carValue.OG_1                =  nodes.state{idNode} (4,end);            ameputp(sname, car_param.OG_1   , carValue.OG_1  );
    carValue.OG_2                =  nodes.state{idNode} (5,end);            ameputp(sname, car_param.OG_2   , carValue.OG_2  );  
    carValue.OG_3                =  nodes.state{idNode} (6,end);            ameputp(sname, car_param.OG_3   , carValue.OG_3  ); 
    
    carValue.omeg_1              =  nodes.state{idNode} (7,end);            ameputp(sname, car_param.omeg_1   , carValue.omeg_1  );  
    carValue.omeg_2              =  nodes.state{idNode} (8,end);            ameputp(sname, car_param.omeg_2   , carValue.omeg_2  ); 
    carValue.omeg_3              =  nodes.state{idNode} (9,end);            ameputp(sname, car_param.omeg_3   , carValue.omeg_3  ); 
    
    carValue.Eulerangle_1        =  nodes.state{idNode} (10,end);           ameputp(sname, car_param.Eulerangle_1   , carValue.Eulerangle_1   );  
    carValue.Eulerangle_2        =  nodes.state{idNode} (11,end);           ameputp(sname, car_param.Eulerangle_2   , carValue.Eulerangle_2   );  
    carValue.Eulerangle_3        =  nodes.state{idNode} (12,end);           ameputp(sname, car_param.Eulerangle_3   , carValue.Eulerangle_3   );  
    
    carValue.vzrelavg            =  nodes.state{idNode} (13,end);           ameputp(sname, car_param.vzrelavg      , carValue.vzrelavg     );          
    carValue.zrelavg             =  nodes.state{idNode} (14,end);           ameputp(sname, car_param.zrelavg       , carValue.zrelavg      );          
    carValue.Wrelavg             =  nodes.state{idNode} (15,end);           ameputp(sname, car_param.Wrelavg       , carValue.Wrelavg      );        
    carValue.thetarelavg         =  nodes.state{idNode} (16,end);           ameputp(sname, car_param.thetarelavg   , carValue.thetarelavg  );
    
    carValue.vzrelavd            =  nodes.state{idNode} (17,end);           ameputp(sname, car_param.vzrelavd      , carValue.vzrelavd     );         
    carValue.zrelavd             =  nodes.state{idNode} (18,end);           ameputp(sname, car_param.zrelavd       , carValue.zrelavd      );          
    carValue.Wrelavd             =  nodes.state{idNode} (19,end);           ameputp(sname, car_param.Wrelavd       , carValue.Wrelavd      );        
    carValue.thetarelavd         =  nodes.state{idNode} (20,end);           ameputp(sname, car_param.thetarelavd   , carValue.thetarelavd  ); 
    
    carValue.vzrelarrg           =  nodes.state{idNode} (21,end);           ameputp(sname, car_param.vzrelarrg     , carValue.vzrelarrg    );        
    carValue.zrelarrg            =  nodes.state{idNode} (22,end);           ameputp(sname, car_param.zrelarrg      , carValue.zrelarrg     );       
    carValue.Wrelarrg            =  nodes.state{idNode} (23,end);           ameputp(sname, car_param.Wrelarrg      , carValue.Wrelarrg     );       
    carValue.thetarelarrg        =  nodes.state{idNode} (24,end);           ameputp(sname, car_param.thetarelarrg  , carValue.thetarelarrg );
    
    carValue.vzrelarrd           =  nodes.state{idNode} (25,end);           ameputp(sname, car_param.vzrelarrd     , carValue.vzrelarrd    );         
    carValue.zrelarrd            =  nodes.state{idNode} (26,end);           ameputp(sname, car_param.zrelarrd      , carValue.zrelarrd     );         
    carValue.Wrelarrd            =  nodes.state{idNode} (27,end);           ameputp(sname, car_param.Wrelarrd      , carValue.Wrelarrd     );       
    carValue.thetarelarrd        =  nodes.state{idNode} (28,end);           ameputp(sname, car_param.thetarelarrd  , carValue.thetarelarrd );
    
    carValue.vycrav              =  nodes.state{idNode} (29,end);           ameputp(sname, car_param.vycrav   , carValue.vycrav  );         
    carValue.ycrav               =  nodes.state{idNode} (30,end);           ameputp(sname, car_param.ycrav   , carValue.ycrav  ); 
%%    
    carValue.WelastoR1_1_FL      =  nodes.state{idNode} (31,end);           ameputp(sname, car_param.WelastoR1_1_FL   , carValue.WelastoR1_1_FL  ); 
    carValue.WelastoR1_2_FL      =  nodes.state{idNode} (32,end);           ameputp(sname, car_param.WelastoR1_2_FL   , carValue.WelastoR1_2_FL  ); 
    carValue.WelastoR1_3_FL      =  nodes.state{idNode} (33,end);           ameputp(sname, car_param.WelastoR1_3_FL   , carValue.WelastoR1_3_FL  ); 
    
    carValue.THETAelastoR1_1_FL      = nodes.state{idNode} (34,end);        ameputp(sname, car_param.THETAelastoR1_1_FL   , carValue.THETAelastoR1_1_FL  ); 
    carValue.THETAelastoR1_2_FL      = nodes.state{idNode} (35,end);        ameputp(sname, car_param.THETAelastoR1_2_FL   , carValue.THETAelastoR1_2_FL  ); 
    carValue.THETAelastoR1_3_FL      = nodes.state{idNode} (36,end);        ameputp(sname, car_param.THETAelastoR1_3_FL   , carValue.THETAelastoR1_3_FL  ); 
  
	carValue.VxelastoR1_FL      = nodes.state{idNode} (37,end);             ameputp(sname, car_param.VxelastoR1_FL   , carValue.VxelastoR1_FL  ); 
    carValue.VyelastoR1_FL      = nodes.state{idNode} (38,end);             ameputp(sname, car_param.VyelastoR1_FL   , carValue.VyelastoR1_FL  ); 
    carValue.XelastoR1_FL       = nodes.state{idNode} (39,end);             ameputp(sname, car_param.XelastoR1_FL   , carValue.XelastoR1_FL  ); 
    carValue.YelastoR1_FL       = nodes.state{idNode} (40,end);             ameputp(sname, car_param.YelastoR1_FL   , carValue.YelastoR1_FL  );
  %%  
    carValue.WelastoR1_1_FR      =  nodes.state{idNode} (41,end);           ameputp(sname, car_param.WelastoR1_1_FR   , carValue.WelastoR1_1_FL  ); 
    carValue.WelastoR1_2_FR      =  nodes.state{idNode} (42,end);           ameputp(sname, car_param.WelastoR1_2_FR   , carValue.WelastoR1_2_FL  ); 
    carValue.WelastoR1_3_FR      =  nodes.state{idNode} (43,end);           ameputp(sname, car_param.WelastoR1_3_FR   , carValue.WelastoR1_3_FL  ); 
    
    carValue.THETAelastoR1_1_FR      = nodes.state{idNode} (44,end);        ameputp(sname, car_param.THETAelastoR1_1_FR   , carValue.THETAelastoR1_1_FR  ); 
    carValue.THETAelastoR1_2_FR      = nodes.state{idNode} (45,end);        ameputp(sname, car_param.THETAelastoR1_2_FR   , carValue.THETAelastoR1_2_FR  ); 
    carValue.THETAelastoR1_3_FR      = nodes.state{idNode} (46,end);        ameputp(sname, car_param.THETAelastoR1_3_FR   , carValue.THETAelastoR1_3_FR  ); 
  
	carValue.VxelastoR1_FR      = nodes.state{idNode} (47,end);             ameputp(sname, car_param.VxelastoR1_FR   , carValue.VxelastoR1_FR  ); 
    carValue.VyelastoR1_FR      = nodes.state{idNode} (48,end);             ameputp(sname, car_param.VyelastoR1_FR   , carValue.VyelastoR1_FR  ); 
    carValue.XelastoR1_FR       = nodes.state{idNode} (49,end);             ameputp(sname, car_param.XelastoR1_FR   , carValue.XelastoR1_FR  ); 
    carValue.YelastoR1_FR       = nodes.state{idNode} (50,end);             ameputp(sname, car_param.YelastoR1_FR   , carValue.YelastoR1_FR  ); 
  %%  
    carValue.WelastoR1_1_RL      =  nodes.state{idNode} (51,end);           ameputp(sname, car_param.WelastoR1_1_RL   , carValue.WelastoR1_1_RL  ); 
    carValue.WelastoR1_2_RL      =  nodes.state{idNode} (52,end);           ameputp(sname, car_param.WelastoR1_2_RL   , carValue.WelastoR1_2_RL  ); 
    carValue.WelastoR1_3_RL      =  nodes.state{idNode} (53,end);           ameputp(sname, car_param.WelastoR1_3_RL   , carValue.WelastoR1_3_RL  ); 
    
    carValue.THETAelastoR1_1_RL      = nodes.state{idNode} (54,end);        ameputp(sname, car_param.THETAelastoR1_1_RL   , carValue.THETAelastoR1_1_RL  ); 
    carValue.THETAelastoR1_2_RL      = nodes.state{idNode} (55,end);        ameputp(sname, car_param.THETAelastoR1_2_RL   , carValue.THETAelastoR1_2_RL  ); 
    carValue.THETAelastoR1_3_RL      = nodes.state{idNode} (56,end);        ameputp(sname, car_param.THETAelastoR1_3_RL   , carValue.THETAelastoR1_3_RL  ); 
  
	carValue.VxelastoR1_RL      = nodes.state{idNode} (57,end);             ameputp(sname, car_param.VxelastoR1_RL   , carValue.VxelastoR1_RL  ); 
    carValue.VyelastoR1_RL      = nodes.state{idNode} (58,end);             ameputp(sname, car_param.VyelastoR1_RL   , carValue.VyelastoR1_RL  ); 
    carValue.XelastoR1_RL       = nodes.state{idNode} (59,end);             ameputp(sname, car_param.XelastoR1_RL   , carValue.XelastoR1_RL  ); 
    carValue.YelastoR1_RL       = nodes.state{idNode} (60,end);             ameputp(sname, car_param.YelastoR1_RL   , carValue.YelastoR1_RL  ); 
  %%  
    carValue.WelastoR1_1_RR      =  nodes.state{idNode} (61,end);           ameputp(sname, car_param.WelastoR1_1_RR   , carValue.WelastoR1_1_RR  ); 
    carValue.WelastoR1_2_RR      =  nodes.state{idNode} (62,end);           ameputp(sname, car_param.WelastoR1_2_RR   , carValue.WelastoR1_2_RR  ); 
    carValue.WelastoR1_3_RR      =  nodes.state{idNode} (63,end);           ameputp(sname, car_param.WelastoR1_3_RR   , carValue.WelastoR1_3_RR  ); 
    
    carValue.THETAelastoR1_1_RR      = nodes.state{idNode} (64,end);        ameputp(sname, car_param.THETAelastoR1_1_RR   , carValue.THETAelastoR1_1_RR  ); 
    carValue.THETAelastoR1_2_RR      = nodes.state{idNode} (65,end);        ameputp(sname, car_param.THETAelastoR1_2_RR   , carValue.THETAelastoR1_2_RR); 
    carValue.THETAelastoR1_3_RR      = nodes.state{idNode} (66,end);        ameputp(sname, car_param.THETAelastoR1_3_RR   , carValue.THETAelastoR1_3_RR  ); 
  
	carValue.VxelastoR1_RR      = nodes.state{idNode} (67,end);             ameputp(sname, car_param.VxelastoR1_RR   , carValue.VxelastoR1_RR  ); 
    carValue.VyelastoR1_RR      = nodes.state{idNode} (68,end);             ameputp(sname, car_param.VyelastoR1_RR   , carValue.VyelastoR1_RR  ); 
    carValue.XelastoR1_RR       = nodes.state{idNode} (69,end);             ameputp(sname, car_param.XelastoR1_RR   , carValue.XelastoR1_RR  ); 
    carValue.YelastoR1_RR       = nodes.state{idNode} (70,end);             ameputp(sname, car_param.YelastoR1_RR   , carValue.YelastoR1_RR  ); 
    %%

    
%     Ux  = nodes.state{idNode} (1,end); 
%     Uy  = nodes.state{idNode} (2,end); 
%     r   = nodes.state{idNode} (3,end); 
%     ksi = nodes.state{idNode} (4,end); 
%     x   = nodes.state{idNode} (5,end); 
%     y   = nodes.state{idNode} (6,end); 
%     w1L = nodes.state{idNode} (7,end); 
%     w1R = nodes.state{idNode} (8,end); 
%     w2L = nodes.state{idNode} (9,end); 
%     w2R = nodes.state{idNode} (10,end); 
%     
%     ameputp(sname, car.UX   , nodes.state{idNode} (1,end) );
%     ameputp(sname, car.UY   , nodes.state{idNode} (2,end) );
% %   ameputp(sname, car.R    , nodes.state{idNode} (3,end)*180/pi  );
%     ameputp(sname, car.KSI  , nodes.state{idNode} (4,end)*180/pi );
%     ameputp(sname, car.X    , nodes.state{idNode} (5,end) );
%     ameputp(sname, car.Y    , nodes.state{idNode} (6,end) );
%     ameputp(sname, car.W1L  , nodes.state{idNode} (7,end) *180/pi );
%     ameputp(sname, car.W1R  , nodes.state{idNode} (8,end) *180/pi );
%     ameputp(sname, car.W2L  , nodes.state{idNode} (9,end) *180/pi );
%     ameputp(sname, car.W2R  , nodes.state{idNode} (10,end)*180/pi );
    
    
    selectYawController = controlParams(1);
    Uref = controlParams(2);ksiRef = controlParams(3);xRef = controlParams(4);yRef = controlParams(5);
    
   % modify parsfile
   modifyParsfile(idNode);
    
   % initilaize steps 
    uInit = edges.u{nodes.preceedingEdge(idNode)}  ;
    intState = nodes.intState{idNode} ;
 
  % simulate
     token2 = tic;
    sim('maneuvers3');
     timeSim = timeSim + toc(token2);
     
    
  % downsample so that its easier to work with     
    trajectory = [x y ksi];
    trajectory = downsample(trajectory,downsampleFactor);
    trajectory = trajectory';
    time_ = downsample(time,downsampleFactor);
 
  % visualize so that I can debug  
      h3 = plot(trajectory(1,:), trajectory(2,:), 'r');
     pause(0.05)
    
    crash = true;
    
    % check rules for exiting certain area
    checkExitRules;

    [primitive, idPrimitive] = findIntersection(areas, [trajectory(1,:) x(end)], [trajectory(2,:) y(end)], primitives, primitiveStart);
    
    checkEntryRules;
    rulesSatisfied = good2exit && good2enter;
    
    if rulesSatisfied
         crash = false;
         token2 = tic;
         for i= 1:nObst
             crash = crash || checkColl(trajectory, obstacles{i}, lF, lR, width); 
         end
         timeCol = timeCol + toc(token2);
    end
   
    [results,var_names] = ameloadt(sname);

    carValue.vG_1 = amegetvar(results,var_names,     car_var.vG_1);
    carValue.vG_2 = amegetvar(results,var_names,     car_var.vG_2);
    carValue.vG_3 = amegetvar(results,var_names,     car_var.vG_3);
    
    carValue.OG_1 = amegetvar(results,var_names,     car_var.OG_1);
    carValue.OG_2 = amegetvar(results,var_names,     car_var.OG_2);
    carValue.OG_3 = amegetvar(results,var_names,     car_var.OG_3);
            
    carValue.omeg_1 = amegetvar(results,var_names,     car_var.omeg_1);
    carValue.omeg_2 = amegetvar(results,var_names,     car_var.omeg_2);
    carValue.omeg_3 = amegetvar(results,var_names,     car_var.omeg_3);
  
    carValue.Eulerangle_1 = amegetvar(results,var_names,     car_var.Eulerangle_1);
    carValue.Eulerangle_2 = amegetvar(results,var_names,     car_var.Eulerangle_2);
    carValue.Eulerangle_3 = amegetvar(results,var_names,     car_var.Eulerangle_3);
    
    carValue.vzrelavg    = amegetvar(results,var_names,     car_var.vzrelavg   );
    carValue.zrelavg     = amegetvar(results,var_names,     car_var.zrelavg    );
    carValue.Wrelavg     = amegetvar(results,var_names,     car_var.Wrelavg    );
    carValue.thetarelavg = amegetvar(results,var_names,     car_var.thetarelavg);

    carValue.vzrelavd    = amegetvar(results,var_names,     car_var.vzrelavd   );
    carValue.zrelavd     = amegetvar(results,var_names,     car_var.zrelavd    );
    carValue.Wrelavd     = amegetvar(results,var_names,     car_var.Wrelavd    );
    carValue.thetarelavd = amegetvar(results,var_names,     car_var.thetarelavd);
    
    carValue.vzrelarrg    = amegetvar(results,var_names,     car_var.vzrelarrg   );
    carValue.zrelarrg     = amegetvar(results,var_names,     car_var.zrelarrg    );
    carValue.Wrelarrg     = amegetvar(results,var_names,     car_var.Wrelarrg    );
    carValue.thetarelarrg = amegetvar(results,var_names,     car_var.thetarelarrg);

    carValue.vzrelarrd    = amegetvar(results,var_names,     car_var.vzrelarrd   );
    carValue.zrelarrd     = amegetvar(results,var_names,     car_var.zrelarrd    );
    carValue.Wrelarrd     = amegetvar(results,var_names,     car_var.Wrelarrd    );
    carValue.thetarelarrd = amegetvar(results,var_names,     car_var.thetarelarrd);

    carValue.vycrav     = amegetvar(results,var_names,     car_var.vycrav);
    carValue.ycrav      = amegetvar(results,var_names,     car_var.ycrav);
 %%   
    carValue.WelastoR1_1_FL      = amegetvar(results,var_names,     car_var.WelastoR1_1_FL);
    carValue.WelastoR1_2_FL      = amegetvar(results,var_names,     car_var.WelastoR1_2_FL);
    carValue.WelastoR1_3_FL      = amegetvar(results,var_names,     car_var.WelastoR1_3_FL);
    
    carValue.THETAelastoR1_1_FL      = amegetvar(results,var_names,     car_var.THETAelastoR1_1_FL);
    carValue.THETAelastoR1_2_FL      = amegetvar(results,var_names,     car_var.THETAelastoR1_2_FL);
    carValue.THETAelastoR1_3_FL      = amegetvar(results,var_names,     car_var.THETAelastoR1_3_FL);
  
	carValue.VxelastoR1_FL      = amegetvar(results,var_names,     car_var.VxelastoR1_FL);
    carValue.VyelastoR1_FL      = amegetvar(results,var_names,     car_var.VyelastoR1_FL);
    carValue.XelastoR1_FL       = amegetvar(results,var_names,     car_var.XelastoR1_FL );
    carValue.YelastoR1_FL       = amegetvar(results,var_names,     car_var.YelastoR1_FL );
 %%
    carValue.WelastoR1_1_FR      = amegetvar(results,var_names,     car_var.WelastoR1_1_FR);
    carValue.WelastoR1_2_FR      = amegetvar(results,var_names,     car_var.WelastoR1_2_FR);
    carValue.WelastoR1_3_FR      = amegetvar(results,var_names,     car_var.WelastoR1_3_FR);
    
    carValue.THETAelastoR1_1_FR      = amegetvar(results,var_names,     car_var.THETAelastoR1_1_FR);
    carValue.THETAelastoR1_2_FR      = amegetvar(results,var_names,     car_var.THETAelastoR1_2_FR);
    carValue.THETAelastoR1_3_FR      = amegetvar(results,var_names,     car_var.THETAelastoR1_3_FR);
  
	carValue.VxelastoR1_FR      = amegetvar(results,var_names,     car_var.VxelastoR1_FR);
    carValue.VyelastoR1_FR      = amegetvar(results,var_names,     car_var.VyelastoR1_FR);
    carValue.XelastoR1_FR       = amegetvar(results,var_names,     car_var.XelastoR1_FR );
    carValue.YelastoR1_FR       = amegetvar(results,var_names,     car_var.YelastoR1_FR );
 %%
     carValue.WelastoR1_1_RL      = amegetvar(results,var_names,     car_var.WelastoR1_1_RL);
    carValue.WelastoR1_2_RL      = amegetvar(results,var_names,     car_var.WelastoR1_2_RL);
    carValue.WelastoR1_3_RL      = amegetvar(results,var_names,     car_var.WelastoR1_3_RL);
    
    carValue.THETAelastoR1_1_RL      = amegetvar(results,var_names,     car_var.THETAelastoR1_1_RL);
    carValue.THETAelastoR1_2_RL      = amegetvar(results,var_names,     car_var.THETAelastoR1_2_RL);
    carValue.THETAelastoR1_3_RL      = amegetvar(results,var_names,     car_var.THETAelastoR1_3_RL);
  
	carValue.VxelastoR1_RL      = amegetvar(results,var_names,     car_var.VxelastoR1_RL);
    carValue.VyelastoR1_RL      = amegetvar(results,var_names,     car_var.VyelastoR1_RL);
    carValue.XelastoR1_RL       = amegetvar(results,var_names,     car_var.XelastoR1_RL );
    carValue.YelastoR1_FL       = amegetvar(results,var_names,     car_var.YelastoR1_FL );
 %%
    carValue.WelastoR1_1_RR      = amegetvar(results,var_names,     car_var.WelastoR1_1_RR);
    carValue.WelastoR1_2_RR      = amegetvar(results,var_names,     car_var.WelastoR1_2_RR);
    carValue.WelastoR1_3_RR      = amegetvar(results,var_names,     car_var.WelastoR1_3_RR);
    
    carValue.THETAelastoR1_1_RR      = amegetvar(results,var_names,     car_var.THETAelastoR1_1_RR);
    carValue.THETAelastoR1_2_RR      = amegetvar(results,var_names,     car_var.THETAelastoR1_2_RR);
    carValue.THETAelastoR1_3_RR      = amegetvar(results,var_names,     car_var.THETAelastoR1_3_RR);
  
	carValue.VxelastoR1_RR      = amegetvar(results,var_names,     car_var.VxelastoR1_RR);
    carValue.VyelastoR1_RR      = amegetvar(results,var_names,     car_var.VyelastoR1_RR);
    carValue.XelastoR1_RR       = amegetvar(results,var_names,     car_var.XelastoR1_RR );
    carValue.YelastoR1_RR       = amegetvar(results,var_names,     car_var.YelastoR1_RR );
 %%
    % if there is no collision add the new node
    % this is not a function because I don't want to pass a huge structure
    % which may cause stack overflow
    if ~crash && rulesSatisfied 
        
        if isempty(deletedNodes)
            numNodes = numNodes + 1;
            numEdges = numEdges + 1;

            % add node
            nodes.state = [nodes.state; cell(1)];
            nodes.state{end} = [ carValue.vG_1(end)   carValue.vG_2(end)   carValue.vG_3(end)   carValue.OG_1(end)         carValue.OG_2(end)         carValue.OG_3(end) ...
                  carValue.omeg_1(end) carValue.omeg_2(end) carValue.omeg_3(end) carValue.Eulerangle_1(end) carValue.Eulerangle_2(end) carValue.Eulerangle_3(end) ...
                  carValue.vzrelavg(end)         carValue.zrelavg(end)         carValue.Wrelavg(end)       carValue.thetarelavg(end) ...
                  carValue.vzrelavd(end)         carValue.zrelavd(end)         carValue.Wrelavd(end)       carValue.thetarelavd(end) ...
                  carValue.vzrelarrg(end)        carValue.zrelarrg(end)        carValue.Wrelarrg(end)      carValue.thetarelarrg(end) ...
                  carValue.vzrelarrd(end)        carValue.zrelarrd(end)        carValue.Wrelarrd(end)      carValue.thetarelarrd(end) ...
                  carValue.vycrav(end)        carValue.ycrav(end) ... 
                  carValue.WelastoR1_1_FL(end)         carValue.WelastoR1_2_FL(end)           carValue.WelastoR1_3_FL(end) ...
                  carValue.THETAelastoR1_1_FL(end)     carValue.THETAelastoR1_2_FL(end)       carValue.THETAelastoR1_3_FL(end) ...  
                  carValue.VxelastoR1_FL(end)          carValue.VyelastoR1_FL(end)            carValue.XelastoR1_FL(end)            carValue.YelastoR1_FL(end) ...
                  carValue.WelastoR1_1_FR(end)         carValue.WelastoR1_2_FR(end)           carValue.WelastoR1_3_FR(end) ...
                  carValue.THETAelastoR1_1_FR(end)     carValue.THETAelastoR1_2_FR(end)       carValue.THETAelastoR1_3_FR(end) ...  
                  carValue.VxelastoR1_FR(end)          carValue.VyelastoR1_FR(end)            carValue.XelastoR1_FR(end)            carValue.YelastoR1_FR(end) ...
                  carValue.WelastoR1_1_RL(end)         carValue.WelastoR1_2_RL(end)           carValue.WelastoR1_3_RL(end) ...
                  carValue.THETAelastoR1_1_RL(end)     carValue.THETAelastoR1_2_RL(end)       carValue.THETAelastoR1_3_RL(end) ...  
                  carValue.VxelastoR1_RL(end)          carValue.VyelastoR1_RL(end)            carValue.XelastoR1_RL(end)            carValue.YelastoR1_RL(end) ...
                  carValue.WelastoR1_1_RR(end)         carValue.WelastoR1_2_RR(end)           carValue.WelastoR1_3_RR(end) ...
                  carValue.THETAelastoR1_1_RR(end)     carValue.THETAelastoR1_2_RR(end)       carValue.THETAelastoR1_3_RR(end) ...  
                  carValue.VxelastoR1_RR(end)          carValue.VyelastoR1_RR(end)            carValue.XelastoR1_RR(end)            carValue.YelastoR1_RR(end) ]';   % Push all 70 States values
              
              
            nodes.t = [nodes.t; nodes.t(idNode) + T];
            nodes.weight =[nodes.weight; 1];
            nodes.x = [nodes.x; x(end)];
            nodes.y = [nodes.y; y(end)];
            nodes.preceedingEdge = [nodes.preceedingEdge; numEdges];
            nodes.preceedingNode = [nodes.preceedingNode; idNode];
            nodes.leaf = [nodes.leaf; true];
            nodes.leaf(idNode) = false;
            nodes.crashCount = [nodes.crashCount; 0];
            nodes.intState = [nodes.intState; cell(1,1)];
            nodes.intState{end} = [delta(end)*180/pi; brake(end); handbrake(end); throttle(end); gears(end)];

            % add the edge
            edges.beginNode = [edges.beginNode; idNode];
            edges.endNode = [edges.endNode; numNodes];
            edges.dt = [edges.dt; T];       
            edges.inputs = [edges.inputs; cell(1,1)];
            edges.inputs{end} = [downsample(time', 1)+nodes.t(nodes.preceedingNode(numNodes));...
                            downsample(delta_', 1); downsample(brake_',  1);...
                            downsample(handbrake_',  1); downsample(throttle_',  1); downsample(gears_', 1)];
            edges.realInputs = [edges.realInputs; cell(1,1)];
            edges.realInputs{end} = [downsample(time', 1)+nodes.t(nodes.preceedingNode(numNodes));...
                downsample(delta', 1); downsample(brake',  1);...
                downsample(handbrake',  1); downsample(throttle',  1); downsample(gears', 1)];
            edges.u = [edges.u; cell(1,1)];
            edges.u{end}  = u;
            
            % plot the new edge
            temp = plot(trajectory(1,:), trajectory(2,:), 'b');
            edges.handle = [edges.handle; temp];
            temp = plot(x(end), y(end), 'bo');
            nodes.handle = [nodes.handle; temp];

            addedNodeId = numNodes;
        
        else
            newNodeId = deletedNodes(end);
            newEdgeId = deletedEdges(end);
            
            nodes.state{newNodeId} = [carValue.vG_1(end)   carValue.vG_2(end)   carValue.vG_3(end)   carValue.OG_1(end)         carValue.OG_2(end)         carValue.OG_3(end) ...
                  carValue.omeg_1(end) carValue.omeg_2(end) carValue.omeg_3(end) carValue.Eulerangle_1(end) carValue.Eulerangle_2(end) carValue.Eulerangle_3(end) ...
                  carValue.vzrelavg(end)         carValue.zrelavg(end)         carValue.Wrelavg(end)       carValue.thetarelavg(end) ...
                  carValue.vzrelavd(end)         carValue.zrelavd(end)         carValue.Wrelavd(end)       carValue.thetarelavd(end) ...
                  carValue.vzrelarrg(end)        carValue.zrelarrg(end)        carValue.Wrelarrg(end)      carValue.thetarelarrg(end) ...
                  carValue.vzrelarrd(end)        carValue.zrelarrd(end)        carValue.Wrelarrd(end)      carValue.thetarelarrd(end) ...
                  carValue.vycrav(end)        carValue.ycrav(end) ...
                  carValue.WelastoR1_1_FL(end)         carValue.WelastoR1_2_FL(end)           carValue.WelastoR1_3_FL(end) ...
                  carValue.THETAelastoR1_1_FL(end)     carValue.THETAelastoR1_2_FL(end)       carValue.THETAelastoR1_3_FL(end) ...  
                  carValue.VxelastoR1_FL(end)          carValue.VyelastoR1_FL(end)            carValue.XelastoR1_FL(end)            carValue.YelastoR1_FL(end) ...
                  carValue.WelastoR1_1_FR(end)         carValue.WelastoR1_2_FR(end)           carValue.WelastoR1_3_FR(end) ...
                  carValue.THETAelastoR1_1_FR(end)     carValue.THETAelastoR1_2_FR(end)       carValue.THETAelastoR1_3_FR(end) ...  
                  carValue.VxelastoR1_FR(end)          carValue.VyelastoR1_FR(end)            carValue.XelastoR1_FR(end)            carValue.YelastoR1_FR(end) ...
                  carValue.WelastoR1_1_RL(end)         carValue.WelastoR1_2_RL(end)           carValue.WelastoR1_3_RL(end) ...
                  carValue.THETAelastoR1_1_RL(end)     carValue.THETAelastoR1_2_RL(end)       carValue.THETAelastoR1_3_RL(end) ...  
                  carValue.VxelastoR1_RL(end)          carValue.VyelastoR1_RL(end)            carValue.XelastoR1_RL(end)            carValue.YelastoR1_RL(end) ...
                  carValue.WelastoR1_1_RR(end)         carValue.WelastoR1_2_RR(end)           carValue.WelastoR1_3_RR(end) ...
                  carValue.THETAelastoR1_1_RR(end)     carValue.THETAelastoR1_2_RR(end)       carValue.THETAelastoR1_3_RR(end) ...  
                  carValue.VxelastoR1_RR(end)          carValue.VyelastoR1_RR(end)            carValue.XelastoR1_RR(end)            carValue.YelastoR1_RR(end) ]';   % Push all 70 States values
               
                                  
            nodes.t(newNodeId) =  nodes.t(idNode) + T;
            nodes.weight(newNodeId) = 1;
            nodes.x(newNodeId) = x(end);
            nodes.y(newNodeId) = y(end);
            nodes.preceedingEdge(newNodeId) = newEdgeId; 
            nodes.preceedingNode(newNodeId) =  idNode;
            nodes.leaf(newNodeId) = true;
            nodes.leaf(idNode) = false;
            nodes.crashCount(newNodeId) = 0;
            nodes.intState{newNodeId} = [delta(end)*180/pi; brake(end); handbrake(end); throttle(end); gears(end)];

            % add the edge
            edges.beginNode(newEdgeId) = idNode;
            edges.endNode(newEdgeId) = newNodeId;
            edges.dt(newEdgeId) = T;       
            edges.inputs{newEdgeId} = [downsample(time', 1)+nodes.t(nodes.preceedingNode(newNodeId));...
                            downsample(delta_', 1); downsample(brake_',  1);...
                            downsample(handbrake_',  1); downsample(throttle_',  1); downsample(gears_', 1)];
            edges.realInputs{newEdgeId} = [downsample(time', 1)+nodes.t(nodes.preceedingNode(newNodeId));...
                downsample(delta', 1); downsample(brake',  1);...
                downsample(handbrake',  1); downsample(throttle',  1); downsample(gears', 1)];
            edges.u{newEdgeId}  = u;         
            deletedNodes = deletedNodes(1:(end-1));
            deletedEdges = deletedEdges(1:(end-1));
            temp = plot(trajectory(1,:), trajectory(2,:), 'b');
            edges.handle(newEdgeId) = temp;
            temp = plot(x(end), y(end), 'bo');
            nodes.handle(newNodeId) = temp;
            addedNodeId = newNodeId;
            
            
        end
        
        % modify parsfiles
        token2 = tic;
        readWrite(addedNodeId);
        timeFile = timeFile + toc(token2);
    
        %update weights
        token2 = tic;
        nodes.weight = setNodeWeights(nodes, radius, addedNodeId);
        timeNodes  = timeNodes + toc(token2);    
        
        
        
        % if the new node has reached the desired area then break the
        % outer loop

% hard left
        
      if x(end) >=127;
          Status= true;
            break;
      end

% hb turn

     %  if  y(end) > 100 && x(end) < 110
      %       break;
       % end

%gymkhana

      %   if  y(end) > 25 
       %   break;
      %  end
        
        [primitive, idPrimitive] = checkArea(areas, x(end), y(end), primitives);
        checkSelectionRules;
    else
        addedNodeId = idNode;
       [primitive, idPrimitive] = checkArea(areas, nodes.x(idNode), nodes.y(idNode), primitives);
        checkSelectionRules; 
    end
    
    if crash
        nodes.crashCount(idNode) = nodes.crashCount(idNode) + 1;
    end
    
    checkDeletingRules;
    % iterations++
    numIter = numIter + 1;
    
    if good2delete
            deletedNodes = [deletedNodes; idNode];
            deletedEdges = [deletedEdges; nodes.preceedingEdge(idNode)];
            delete(nodes.handle(idNode));
            delete(edges.handle(nodes.preceedingEdge(idNode)));
            temp = find(nodes.preceedingNode(idNode));
            if isempty(temp)
                nodes.leaf(nodes.preceedingNode(idNode)) = true;
            else
                hasNoChildren = true;
                for i=1:length(temp)
                    if ~ismember(temp(i),deletedNodes)
                        hasNoChildren = false;
                        break;     
                    end
                end
                if hasNoChildren
                    nodes.leaf(nodes.preceedingNode(idNode)) = true;
                end

            end
            counter = 0;
            numDeleted = numDeleted + 1;      
    end
%     Distance = 60 - nodes.x(idNode);
%     bonus= fix(floor(100 - 5*100/80)/30);
%     
%     if strcmp(primitiveStart, 'backsteeringAdv')
%         bonus = bonus*2;
%     else if strcmp(primitiveStart, 'backsteeringFront')
%             bonus = bonus*3;
%         end
%     end
    
%     nodes.weight(idNode)=nodes.weight(idNode)+bonus;
%     
    delete(h2);
    delete(h3);
   % x0= trajectory (1,end);
    %y0= trajectory (2,end);
    
 
    
end
timeTotal = toc(token1);
%%

% goo through all the nodes and collect the commands

idNode = addedNodeId;
  %idNode = find ( nodes.y > 30,1);
T = nodes.t(idNode);
listEdges = [];
idEdge = numEdges;


while 1
    
    idEdge = nodes.preceedingEdge(idNode);
    listEdges = [listEdges; idEdge];
    idNode = edges.beginNode(idEdge);
    
    if edges.beginNode(idEdge) == 1
        break;
    end
    
end


listEdges = flip(listEdges);
listNodes = 1;
T1=[];
for i =1:length(listEdges)
   T1= [T1 ;edges.dt(listEdges(i))];
end

for i=1:length(listEdges)
    listNodes = [listNodes; edges.endNode(listEdges(i))];
end

pathX = zeros(length(listNodes),1);
pathY = zeros(length(listNodes),1);

for i=1:length(listNodes)
    pathX(i) = nodes.x(listNodes(i));
    pathY(i) = nodes.y(listNodes(i));
end

plot(pathX, pathY, 'go', 'LineWidth',3)
hold on



  commandActual = [];
  command = [];

for i =1:length(listEdges)

    commandActual = [commandActual edges.inputs{listEdges(i)}(:,1:(end-1))];
end

 commandActual = commandActual';

usePlannerOutputs = 1;
modifyParsfile(1);
uInit = zeros(13,1);
intState = zeros(5,1);
TRAJECTORY =[];
for i=1:length(T1)
    
    idNode=listNodes(i);
    
    carValue.vG_1                =  nodes.state{idNode} (1,end);            ameputp(sname, car_param.vG_1   , carValue.vG_1  );
    carValue.vG_2                =  nodes.state{idNode} (2,end);            ameputp(sname, car_param.vG_2   , carValue.vG_2  );
    carValue.vG_3                =  nodes.state{idNode} (3,end);            ameputp(sname, car_param.vG_3   , carValue.vG_3  );
    
    carValue.OG_1                =  nodes.state{idNode} (4,end);            ameputp(sname, car_param.OG_1   , carValue.OG_1  );
    carValue.OG_2                =  nodes.state{idNode} (5,end);            ameputp(sname, car_param.OG_2   , carValue.OG_2  );  
    carValue.OG_3                =  nodes.state{idNode} (6,end);            ameputp(sname, car_param.OG_3   , carValue.OG_3  ); 
    
    carValue.omeg_1              =  nodes.state{idNode} (7,end);            ameputp(sname, car_param.omeg_1   , carValue.omeg_1  );  
    carValue.omeg_2              =  nodes.state{idNode} (8,end);            ameputp(sname, car_param.omeg_2   , carValue.omeg_2  ); 
    carValue.omeg_3              =  nodes.state{idNode} (9,end);            ameputp(sname, car_param.omeg_3   , carValue.omeg_3  ); 
    
    carValue.Eulerangle_1        =  nodes.state{idNode} (10,end);           ameputp(sname, car_param.Eulerangle_1   , carValue.Eulerangle_1   );  
    carValue.Eulerangle_2        =  nodes.state{idNode} (11,end);           ameputp(sname, car_param.Eulerangle_2   , carValue.Eulerangle_2   );  
    carValue.Eulerangle_3        =  nodes.state{idNode} (12,end);           ameputp(sname, car_param.Eulerangle_3   , carValue.Eulerangle_3   );  
    
    carValue.vzrelavg            =  nodes.state{idNode} (13,end);           ameputp(sname, car_param.vzrelavg      , carValue.vzrelavg     );          
    carValue.zrelavg             =  nodes.state{idNode} (14,end);           ameputp(sname, car_param.zrelavg       , carValue.zrelavg      );          
    carValue.Wrelavg             =  nodes.state{idNode} (15,end);           ameputp(sname, car_param.Wrelavg       , carValue.Wrelavg      );        
    carValue.thetarelavg         =  nodes.state{idNode} (16,end);           ameputp(sname, car_param.thetarelavg   , carValue.thetarelavg  );
    
    carValue.vzrelavd            =  nodes.state{idNode} (17,end);           ameputp(sname, car_param.vzrelavd      , carValue.vzrelavd     );         
    carValue.zrelavd             =  nodes.state{idNode} (18,end);           ameputp(sname, car_param.zrelavd       , carValue.zrelavd      );          
    carValue.Wrelavd             =  nodes.state{idNode} (19,end);           ameputp(sname, car_param.Wrelavd       , carValue.Wrelavd      );        
    carValue.thetarelavd         =  nodes.state{idNode} (20,end);           ameputp(sname, car_param.thetarelavd   , carValue.thetarelavd  ); 
    
    carValue.vzrelarrg           =  nodes.state{idNode} (21,end);           ameputp(sname, car_param.vzrelarrg     , carValue.vzrelarrg    );        
    carValue.zrelarrg            =  nodes.state{idNode} (22,end);           ameputp(sname, car_param.zrelarrg      , carValue.zrelarrg     );       
    carValue.Wrelarrg            =  nodes.state{idNode} (23,end);           ameputp(sname, car_param.Wrelarrg      , carValue.Wrelarrg     );       
    carValue.thetarelarrg        =  nodes.state{idNode} (24,end);           ameputp(sname, car_param.thetarelarrg  , carValue.thetarelarrg );
    
    carValue.vzrelarrd           =  nodes.state{idNode} (25,end);           ameputp(sname, car_param.vzrelarrd     , carValue.vzrelarrd    );         
    carValue.zrelarrd            =  nodes.state{idNode} (26,end);           ameputp(sname, car_param.zrelarrd      , carValue.zrelarrd     );         
    carValue.Wrelarrd            =  nodes.state{idNode} (27,end);           ameputp(sname, car_param.Wrelarrd      , carValue.Wrelarrd     );       
    carValue.thetarelarrd        =  nodes.state{idNode} (28,end);           ameputp(sname, car_param.thetarelarrd  , carValue.thetarelarrd );
    
    carValue.vycrav              =  nodes.state{idNode} (29,end);           ameputp(sname, car_param.vycrav   , carValue.vycrav  );         
    carValue.ycrav               =  nodes.state{idNode} (30,end);           ameputp(sname, car_param.ycrav   , carValue.ycrav  ); 
%%    
    carValue.WelastoR1_1_FL      =  nodes.state{idNode} (31,end);           ameputp(sname, car_param.WelastoR1_1_FL   , carValue.WelastoR1_1_FL  ); 
    carValue.WelastoR1_2_FL      =  nodes.state{idNode} (32,end);           ameputp(sname, car_param.WelastoR1_2_FL   , carValue.WelastoR1_2_FL  ); 
    carValue.WelastoR1_3_FL      =  nodes.state{idNode} (33,end);           ameputp(sname, car_param.WelastoR1_3_FL   , carValue.WelastoR1_3_FL  ); 
    
    carValue.THETAelastoR1_1_FL      = nodes.state{idNode} (34,end);        ameputp(sname, car_param.THETAelastoR1_1_FL   , carValue.THETAelastoR1_1_FL  ); 
    carValue.THETAelastoR1_2_FL      = nodes.state{idNode} (35,end);        ameputp(sname, car_param.THETAelastoR1_2_FL   , carValue.THETAelastoR1_2_FL  ); 
    carValue.THETAelastoR1_3_FL      = nodes.state{idNode} (36,end);        ameputp(sname, car_param.THETAelastoR1_3_FL   , carValue.THETAelastoR1_3_FL  ); 
  
	carValue.VxelastoR1_FL      = nodes.state{idNode} (37,end);             ameputp(sname, car_param.VxelastoR1_FL   , carValue.VxelastoR1_FL  ); 
    carValue.VyelastoR1_FL      = nodes.state{idNode} (38,end);             ameputp(sname, car_param.VyelastoR1_FL   , carValue.VyelastoR1_FL  ); 
    carValue.XelastoR1_FL       = nodes.state{idNode} (39,end);             ameputp(sname, car_param.XelastoR1_FL   , carValue.XelastoR1_FL  ); 
    carValue.YelastoR1_FL       = nodes.state{idNode} (40,end);             ameputp(sname, car_param.YelastoR1_FL   , carValue.YelastoR1_FL  );
  %%  
    carValue.WelastoR1_1_FR      =  nodes.state{idNode} (41,end);           ameputp(sname, car_param.WelastoR1_1_FR   , carValue.WelastoR1_1_FL  ); 
    carValue.WelastoR1_2_FR      =  nodes.state{idNode} (42,end);           ameputp(sname, car_param.WelastoR1_2_FR   , carValue.WelastoR1_2_FL  ); 
    carValue.WelastoR1_3_FR      =  nodes.state{idNode} (43,end);           ameputp(sname, car_param.WelastoR1_3_FR   , carValue.WelastoR1_3_FL  ); 
    
    carValue.THETAelastoR1_1_FR      = nodes.state{idNode} (44,end);        ameputp(sname, car_param.THETAelastoR1_1_FR   , carValue.THETAelastoR1_1_FR  ); 
    carValue.THETAelastoR1_2_FR      = nodes.state{idNode} (45,end);        ameputp(sname, car_param.THETAelastoR1_2_FR   , carValue.THETAelastoR1_2_FR  ); 
    carValue.THETAelastoR1_3_FR      = nodes.state{idNode} (46,end);        ameputp(sname, car_param.THETAelastoR1_3_FR   , carValue.THETAelastoR1_3_FR  ); 
  
	carValue.VxelastoR1_FR      = nodes.state{idNode} (47,end);             ameputp(sname, car_param.VxelastoR1_FR   , carValue.VxelastoR1_FR  ); 
    carValue.VyelastoR1_FR      = nodes.state{idNode} (48,end);             ameputp(sname, car_param.VyelastoR1_FR   , carValue.VyelastoR1_FR  ); 
    carValue.XelastoR1_FR       = nodes.state{idNode} (49,end);             ameputp(sname, car_param.XelastoR1_FR   , carValue.XelastoR1_FR  ); 
    carValue.YelastoR1_FR       = nodes.state{idNode} (50,end);             ameputp(sname, car_param.YelastoR1_FR   , carValue.YelastoR1_FR  ); 
  %%  
    carValue.WelastoR1_1_RL      =  nodes.state{idNode} (51,end);           ameputp(sname, car_param.WelastoR1_1_RL   , carValue.WelastoR1_1_RL  ); 
    carValue.WelastoR1_2_RL      =  nodes.state{idNode} (52,end);           ameputp(sname, car_param.WelastoR1_2_RL   , carValue.WelastoR1_2_RL  ); 
    carValue.WelastoR1_3_RL      =  nodes.state{idNode} (53,end);           ameputp(sname, car_param.WelastoR1_3_RL   , carValue.WelastoR1_3_RL  ); 
    
    carValue.THETAelastoR1_1_RL      = nodes.state{idNode} (54,end);        ameputp(sname, car_param.THETAelastoR1_1_RL   , carValue.THETAelastoR1_1_RL  ); 
    carValue.THETAelastoR1_2_RL      = nodes.state{idNode} (55,end);        ameputp(sname, car_param.THETAelastoR1_2_RL   , carValue.THETAelastoR1_2_RL  ); 
    carValue.THETAelastoR1_3_RL      = nodes.state{idNode} (56,end);        ameputp(sname, car_param.THETAelastoR1_3_RL   , carValue.THETAelastoR1_3_RL  ); 
  
	carValue.VxelastoR1_RL      = nodes.state{idNode} (57,end);             ameputp(sname, car_param.VxelastoR1_RL   , carValue.VxelastoR1_RL  ); 
    carValue.VyelastoR1_RL      = nodes.state{idNode} (58,end);             ameputp(sname, car_param.VyelastoR1_RL   , carValue.VyelastoR1_RL  ); 
    carValue.XelastoR1_RL       = nodes.state{idNode} (59,end);             ameputp(sname, car_param.XelastoR1_RL   , carValue.XelastoR1_RL  ); 
    carValue.YelastoR1_RL       = nodes.state{idNode} (60,end);             ameputp(sname, car_param.YelastoR1_RL   , carValue.YelastoR1_RL  ); 
  %%  
    carValue.WelastoR1_1_RR      =  nodes.state{idNode} (61,end);           ameputp(sname, car_param.WelastoR1_1_RR   , carValue.WelastoR1_1_RR  ); 
    carValue.WelastoR1_2_RR      =  nodes.state{idNode} (62,end);           ameputp(sname, car_param.WelastoR1_2_RR   , carValue.WelastoR1_2_RR  ); 
    carValue.WelastoR1_3_RR      =  nodes.state{idNode} (63,end);           ameputp(sname, car_param.WelastoR1_3_RR   , carValue.WelastoR1_3_RR  ); 
    
    carValue.THETAelastoR1_1_RR      = nodes.state{idNode} (64,end);        ameputp(sname, car_param.THETAelastoR1_1_RR   , carValue.THETAelastoR1_1_RR  ); 
    carValue.THETAelastoR1_2_RR      = nodes.state{idNode} (65,end);        ameputp(sname, car_param.THETAelastoR1_2_RR   , carValue.THETAelastoR1_2_RR); 
    carValue.THETAelastoR1_3_RR      = nodes.state{idNode} (66,end);        ameputp(sname, car_param.THETAelastoR1_3_RR   , carValue.THETAelastoR1_3_RR  ); 
  
	carValue.VxelastoR1_RR      = nodes.state{idNode} (67,end);             ameputp(sname, car_param.VxelastoR1_RR   , carValue.VxelastoR1_RR  ); 
    carValue.VyelastoR1_RR      = nodes.state{idNode} (68,end);             ameputp(sname, car_param.VyelastoR1_RR   , carValue.VyelastoR1_RR  ); 
    carValue.XelastoR1_RR       = nodes.state{idNode} (69,end);             ameputp(sname, car_param.XelastoR1_RR   , carValue.XelastoR1_RR  ); 
    carValue.YelastoR1_RR       = nodes.state{idNode} (70,end);             ameputp(sname, car_param.YelastoR1_RR   , carValue.YelastoR1_RR  ); 
    %%

    command  = [];
    command = [command edges.inputs{listEdges(i)}(:,1:(end-1))];
    command  = command';

    set_param('maneuvers3', 'StopTime', 'T1(i)')
    sim('maneuvers3'); 
    
   
    trajectory = [  Ux(1:end-1,1) Uy(1:end-1,1)  r(1:end-1,1) ksi(1:end-1,1) x(1:end-1,1) y(1:end-1,1) ];
    trajectory = downsample(trajectory,downsampleFactor);
    TRAJECTORY= [TRAJECTORY ; trajectory ];
    trajectory = trajectory';

    plot(x,y,'o', 'LineWidth',1)

end 

% %createTestingGroundCarSim
% end
%   figure (2)
%   plot(time,throttle)
%   hold on
%   plot(commandActual(:,1, commandActual(:,5),'r'))
%   grid on
% 
% % 
 kkkk=downsample(result2.Data,500);
for i=1:1:length(kkkk(:,6))
        draw_car( kkkk(i,5),kkkk(i,6),kkkk(i,4),1.056, 1.344,1.45,2,0.3);
 % plot(TRAJECTORY(i,5),TRAJECTORY(i,6),'o', 'LineWidth',1)
        %xlim([xLimDown xLimUp])
%         ylim([yLimDown yLimUp])   
  end
% % % 
% % save('commandActual.mat')
% % save('TRAJECTORY.mat')
% % 
% trajectory5=[TRAJECTORY(:,1) TRAJECTORY(:,2) TRAJECTORY(:,4) TRAJECTORY(:,3) TRAJECTORY(:,5) TRAJECTORY(:,6)];