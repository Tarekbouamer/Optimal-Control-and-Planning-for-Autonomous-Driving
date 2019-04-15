
function readWrite(numNodes)
    
    name = ['node' num2str(numNodes) '.par'];
    copyfile('C:\Users\hqm3yy\Desktop\New folder\SimAMESIM3\myRRT\nodes\blank.par',...
        ['C:\Users\hqm3yy\Desktop\New folder\SimAMESIM3\myRRT\nodes\' name]);
    read = fopen('C:\Users\hqm3yy\Desktop\New folder\SimAMESIM3\Runs\Run_6bf0f64f-8b36-4e4a-aeac-41e4d09d2eb7_end.par','r');
    write = fopen([ 'C:\Users\hqm3yy\Desktop\New folder\SimAMESIM3\myRRT\nodes\' name], 'at');

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
