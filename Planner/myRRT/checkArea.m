function [primitive, i] = checkArea(areas, x, y, primitives)

% polygons mustn't intersect!!!!
primitive = 'default';

for i = 1:length(areas)
    if inpolygon(x,y, areas{i}(1,:), areas{i}(2,:))
        primitive = primitives(i);
        break;
    end
end
end