 %%%% this script checks entry rules
 
 
 good2enter = false;
 
if strcmp(primitive, 'turnleft') 
	good2enter = true;  
        for i =1:length(trajectory(1,:))
            if inpolygon(trajectory(1,i),trajectory(2,i), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:))   
                 good2enter = true; 
                 T = time_(i);
                 token2 = tic;
                 sim('maneuvers3'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
            end
        end
end

if strcmp(primitive, 'turnright') 
	good2enter = true; 
        for i =1:length(trajectory(1,:))
            if inpolygon(trajectory(1,i),trajectory(2,i), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:)) 
                 good2enter = true; 
                 T = time_(i);
                 token2 = tic;
                 sim('maneuvers3'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
            end
        end                      
end 

if strcmp(primitive, 'straight1') 
	good2enter = true; 
        for i =1:length(trajectory(1,:))
            if inpolygon(trajectory(1,i),trajectory(2,i), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:)) 
                    good2enter = true; 
                 T = time_(i);
                 token2 = tic;
                 sim('maneuvers3'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
            end
        end                      
end

if strcmp(primitive, 'straight2') 
	good2enter = true; 
        for i =1:length(trajectory(1,:))
            if inpolygon(trajectory(1,i),trajectory(2,i), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:)) 
                    good2enter = true; 
                 T = time_(i);
                 token2 = tic;
                 sim('maneuvers3'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
            end
        end                      
end

if strcmp(primitive, 'backturnright') 
	good2enter = true;  
        for i =1:length(trajectory(1,:))
            if inpolygon(trajectory(1,i),trajectory(2,i), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:))   
                 good2enter = true; 
                 T = time_(i);
                 token2 = tic;
                 sim('maneuvers3'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
            end
        end
end

if strcmp(primitive, 'backturnleft') 
	good2enter = true;  
        for i =1:length(trajectory(1,:))
            if inpolygon(trajectory(1,i),trajectory(2,i), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:))   
                 good2enter = true; 
                 T = time_(i);
                 token2 = tic;
                 sim('maneuvers3'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
            end
        end
end

if  strcmp(primitive, 'default')
    if sqrt(Ux(end)^2 + Uy(end)^2) >= 2
        good2enter = true;  
    end   
end







 
