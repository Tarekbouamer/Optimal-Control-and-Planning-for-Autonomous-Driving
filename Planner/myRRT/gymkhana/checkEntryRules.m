 %%%% this script checks entry rules
 
 
 good2enter = false;
 
 
%%%%% dispatch for tight passage
if strcmp(primitive, 'tightPassage')   
    indices = find(abs(ksi) < 45*pi/180);
    if ~isempty(indices)
        for i =1:length(indices)
            if inpolygon(x(indices(i)),y(indices(i)), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:)) 
                 good2enter = true;    
                 T = time(indices(i));
                 token2 = tic;
                 sim('maneuvers'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
            end
        end
    end
                    
end
   
%%%%% dispatch for tight passage 2

if strcmp(primitive, 'gymkhana')   
    for k=1:length(trajectory(1,:))
         if inpolygon(trajectory(1,k),trajectory(2,k), areas{idPrimitive}(1,:), areas{idPrimitive}(2,:)) 
             if abs(trajectory(3,k)) < 5*pi/180
                 good2enter = true;      
                 T = time_(k);
                 token2 = tic;
                 sim('maneuvers'); 
                 timeSim = timeSim + toc(token2);
                 trajectory = [x y ksi];
                 trajectory = downsample(trajectory,downsampleFactor);
                 trajectory = trajectory';
                 break;
             end            
         end
    end                   
end

    
%%%%% dispatch for default    
if  strcmp(primitive, 'default')
    if sqrt(Ux(end)^2 + Uy(end)^2) >= 3
        good2enter = true;  
    end
end





 
 
