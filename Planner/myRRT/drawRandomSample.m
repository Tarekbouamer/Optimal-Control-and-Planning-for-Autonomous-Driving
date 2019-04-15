function [ id ] = drawRandomSample( weights, deletedNodes )

while 1

    CDF = cumsum(weights);

    CDF = 100 * CDF; % scale from 0 to 1000;

    randNum = rand(1,1) * CDF(end);

    id = find(CDF >= randNum, 1, 'first');
    
    if isempty(find(deletedNodes == id, 1))
        break;
    end

end

end

