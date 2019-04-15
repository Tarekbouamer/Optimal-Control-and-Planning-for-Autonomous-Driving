function [primitive, i] = findIntersection(areas, x, y, primitives, currentPrimitive)

% polygons mustn't intersect!!!!
primitive = 'default';
breakOuterLoop = false;
for j = 1: length(x)
    for i = 1:length(areas)
        if inpolygon(x(j),y(j), areas{i}(1,:), areas{i}(2,:)) && ~strcmp(primitives{i},currentPrimitive)
            primitive = primitives(i);
            breakOuterLoop = true;
            break;
        end
    end
    
    if breakOuterLoop
        break;
    end
end
end