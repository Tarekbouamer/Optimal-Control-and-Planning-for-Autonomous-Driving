%%%% script that checks exit rules

good2exit = false;

if strcmp(primitiveStart, 'straight1')
    good2exit = true;
    indices = 1:length(x);
    if ~isempty(indices)
        for i =1:length(indices)
            if ~inpolygon(x(indices(i)),y(indices(i)), areas{idPrimitiveStart}(1,:), areas{idPrimitiveStart}(2,:))
                T = time(indices(i));
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
end

if strcmp(primitiveStart, 'straight2')
    good2exit = true;
    indices = 1:length(x);
    if ~isempty(indices)
        for i =1:length(indices)
            if ~inpolygon(x(indices(i)),y(indices(i)), areas{idPrimitiveStart}(1,:), areas{idPrimitiveStart}(2,:))
                T = time(indices(i));
                token2 = tic;
                sim('maneuvers3');
                timeSim = timeSim + toc(token2);
                trajectory = [x y ksi];
                
                if abs(ksi(end)) > 5*pi/180
                    good2exit = false;
                end
                
                trajectory = downsample(trajectory,downsampleFactor);
                trajectory = trajectory';
                break;
            end
        end
    end
end

if strcmp(primitiveStart, 'turnleft')
	good2exit = true;
    indices = 1:length(x);
    if ~isempty(indices)
        for i =1:length(indices)
            if ~inpolygon(x(indices(i)),y(indices(i)), areas{idPrimitiveStart}(1,:), areas{idPrimitiveStart}(2,:))
                 T = time(indices(i));
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
end

if strcmp(primitiveStart, 'turnright')
	good2exit = true;
     indices = 1:length(x);
    if ~isempty(indices)
        for i =1:length(indices)
            if ~inpolygon(x(indices(i)),y(indices(i)), areas{idPrimitiveStart}(1,:), areas{idPrimitiveStart}(2,:)) 
                 T = time(indices(i));
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
end 

if strcmp(primitiveStart, 'backturnleft')
	good2exit = true;
     indices = 1:length(x);
    if ~isempty(indices)
        for i =1:length(indices)
            if ~inpolygon(x(indices(i)),y(indices(i)), areas{idPrimitiveStart}(1,:), areas{idPrimitiveStart}(2,:)) 
                 T = time(indices(i));
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
end

if strcmp(primitiveStart, 'backturnright')
	good2exit = true;
     indices = 1:length(x);
    if ~isempty(indices)
        for i =1:length(indices)
            if ~inpolygon(x(indices(i)),y(indices(i)), areas{idPrimitiveStart}(1,:), areas{idPrimitiveStart}(2,:)) 
                 T = time(indices(i));
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
end
    
if  strcmp(primitiveStart, 'default')
    good2exit = true;     
end

