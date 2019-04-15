%%%% script that checks exit rules

good2exit = false;

%%%%% dispatch for tight passage 1
if strcmp(primitiveStart, 'tightPassage')     
    if abs(trajectory(3,end)) < 5*pi/180
        good2exit = true;
    end
end
    
%%%%% dispatch for default    
if  strcmp(primitiveStart, 'default')
    good2exit = true;     
end

%%%% dispatch for handbrake turn    
if strcmp(primitiveStart, 'gymkhana')
    if abs(ksi(end) + 3*pi/2) <= 45*pi/180 && y(end) >= 27
        good2exit = true;                           
    end
end