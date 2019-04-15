
function readWrite(numNodes)
    
    name = ['node' num2str(numNodes) '.par'];
    copyfile('C:\Users\dfcdc0\Desktop\RRT\myRRT\nodes\blank.par',...
        ['C:\Users\dfcdc0\Desktop\RRT\myRRT\nodes\' name]);
    read = fopen('C:\Users\dfcdc0\Desktop\RRT\Runs\Run_cbdf3548-6506-4eaf-b11d-4e03acca9a0d_end.par','r');
    write = fopen([ 'C:\Users\dfcdc0\Desktop\RRT\myRRT\nodes\' name], 'at');

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
            fprintf(write,'\n \n %s', 'END');
            break;
        end



    end
    
    fclose(read);
    fclose(write);
    
end
