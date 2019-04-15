function modifyParsfile(idNode)


file = fopen('C:\Users\dfcdc0\Desktop\RRT\myRRT\includeExtParsfile.par', 'wt');

fprintf(file,'%s \n \n', 'PARSFILE');
% fprintf(file,'%s \n \n', 'OPT_INIT_CONFIG 0');
% fprintf(file,'%s \n \n', 'OPT_INIT_PATH 0');

string = 'PARSFILE C:\Users\dfcdc0\Desktop\RRT\myRRT\nodes\';
string = [string 'node' num2str(idNode) '.par'];
fprintf(file,'%s \n \n', string);

fprintf(file,'%s \n \n', 'END');

fclose(file);


end