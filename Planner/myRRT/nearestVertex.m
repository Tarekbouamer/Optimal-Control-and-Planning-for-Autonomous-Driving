function [ id ] = nearestVertex( nodes, x, y )

N = length([nodes.x]);

min = (x - nodes.x(1))^2 + (y- nodes.y(1))^2;
id = 1;
for i = 2:N
    
    if  ((x - nodes.x(i))^2 + (y - nodes.y(i))^2) < min
       id = i;
       min = ((x - nodes.x(i))^2 + (y - nodes.y(i))^2);
    end
      
end




end

