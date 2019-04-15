function [Cars, paramsCars] = getCars()



paramsCars = struct('l', [], 'w', [], 'theta', [], 'offset', cell(1));
k = 0;
l = 2.4;
w = 1.45;


    
    theta = 0;
    A = [cos(theta) -sin(theta); sin(theta) cos(theta)];
    offset = [-2.4; -1.45/2];

    obstPoly = A*[0; 0] + offset;
    obstPoly = [obstPoly, A*[l; 0]+offset];
    obstPoly = [obstPoly, A*[l; w]+offset];
    obstPoly = [obstPoly, A*[0; w]+offset];
    
    k = k+1;
    
    Cars{k} = obstPoly;
    paramsCars.l(k) = l;
    paramsCars.w(k) = w;
    paramsCars.theta(k) = theta;
    paramsCars.offset{k} = offset;
