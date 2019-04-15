function [yes] = checkColl(trajectory, obstPoly, frontL, rearL, width)

N = size(trajectory,2);

    for i=N:-1:1      
        [X,Y] = carVert([trajectory(1,i) trajectory(2,i)]', trajectory(3,i), frontL, rearL, width);
        carPoly = [X; Y];
        yes = isIntersect(obstPoly, carPoly);        
        if yes
            break;
        end

    end
    
end