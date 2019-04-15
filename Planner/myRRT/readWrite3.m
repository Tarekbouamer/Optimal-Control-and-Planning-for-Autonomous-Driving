
function readWrite3(numNodes,params)
    
   INIT_PBK_L1 =  params(1);
   INIT_PBK_R1 =  params(2);
   INIT_PBK_L2 =  params(3);
   INIT_PBK_R2 =  params(4);
   INIT_STEER_SW =  params(5);
   INIT_THROTTLE_ENGINE =  params(6);
   
    name = ['node' num2str(numNodes) '.par'];
    copyfile('C:\Users\Public\Documents\CarSim903_Data\myRRT\nodes\blank.par',...
        ['C:\Users\Public\Documents\CarSim903_Data\myRRT\nodes\' name]);
    read = fopen('C:\Users\Public\Documents\CarSim903_Data\Runs\Run_6bf0f64f-8b36-4e4a-aeac-41e4d09d2eb7_end.par','r');
    write = fopen([ 'C:\Users\Public\Documents\CarSim903_Data\myRRT\nodes\' name], 'at');

    line = fgets(read);
    startFound = 0;
    while ischar(line)    
        line = fgets(read);
        
        if ~isempty(strfind(line, '! STATE VARIABLES (NEEDED FOR RESTART)'))
            startFound = 1;
            fprintf(write,'%s \n \n', 'PARSFILE');
        end

        if startFound %&& ~isempty(strfind(line, 'SV_'))
            fprintf(write,'%s', line);
        end

        if ~isempty(strfind(line, '! IMPORTED VARIABLES'))
            fprintf(write,'\n \n INIT_PBK_L1 %f', INIT_PBK_L1);
            fprintf(write,'\n \n INIT_PBK_R1 %f', INIT_PBK_R1);
            fprintf(write,'\n \n INIT_PBK_L2 %f', INIT_PBK_L2);
            fprintf(write,'\n \n INIT_PBK_R2 %f', INIT_PBK_R2);
            fprintf(write,'\n \n INIT_STEER_SW %f', INIT_STEER_SW);
            fprintf(write,'\n \n INIT_THROTTLE_ENGINE %f', INIT_THROTTLE_ENGINE);
            fprintf(write,'\n \n %s', 'END');
            break;
        end

    end
    
    

    
    
    


    fclose(read);
    fclose(write);
    
end
