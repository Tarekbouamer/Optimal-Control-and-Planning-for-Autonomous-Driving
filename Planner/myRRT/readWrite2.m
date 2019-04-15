
function readWrite2(numNodes)
    
    name = ['node' num2str(numNodes) '.par'];
    copyfile('C:\Users\Public\Documents\CarSim903_Data\Runs\Run_6bf0f64f-8b36-4e4a-aeac-41e4d09d2eb7.par',...
        ['C:\Users\Public\Documents\CarSim903_Data\myRRT\nodes\' name]);
    name = ['node' num2str(numNodes) '_end.par'];
    copyfile('C:\Users\Public\Documents\CarSim903_Data\Runs\Run_6bf0f64f-8b36-4e4a-aeac-41e4d09d2eb7_end.par',...
        ['C:\Users\Public\Documents\CarSim903_Data\myRRT\nodes\' name ]);
    
    
end
