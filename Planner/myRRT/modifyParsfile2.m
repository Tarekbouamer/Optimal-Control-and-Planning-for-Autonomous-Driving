function modifyParsfile2(idNode)

file = fopen('C:\Users\Public\Documents\CarSim903_Data\myRRT\includeExtParsfile2.par', 'wt');

fprintf(file,'%s \n \n', 'PARSFILE');
% fprintf(file,'%s \n \n', 'OPT_INIT_CONFIG 0');
% fprintf(file,'%s \n \n', 'OPT_INIT_PATH 0');


string = 'SPECIAL_PARSFILE C:\Users\Public\Documents\CarSim903_Data\myRRT\nodes2\';
string = [string 'node' num2str(idNode) '_end.par'];
fprintf(file,'%s \n \n', string);

string = 'PARSFILE C:\Users\Public\Documents\CarSim903_Data\myRRT\nodes2\';
string = [string 'node' num2str(idNode) '.par'];
fprintf(file,'%s \n \n', string);


fprintf(file,'%s \n \n', 'END');

fclose(file);
end