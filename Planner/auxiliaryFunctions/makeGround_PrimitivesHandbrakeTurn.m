%%%% put cones into the carsim file
function makeGround_PrimitivesHandbrakeTurn(paramsObst)
     file = fopen('C:\Users\dfcdc0\Desktop\RRT\Roads\AniGroup\AniRep_ac0ea8ab-67b6-445b-917e-c362e25c241b.par','r');
%     file = fopen('C:\Users\Edo\Desktop\AniRep_56ae7af6-ceb0-4b3b-a2c4-5a638f841609.par', 'r');
    line = fgets(file);
    k = 1;
    fileContent{k} = line;
    write = 1;
    while ischar(line)
        k = k+1;
        line = fgets(file);
        if ~isempty(strfind(line, 'ENDTABLE'))
            write = 1;
        end
        
        if write
            fileContent{k} = line;
        end
        
        if ~isempty(strfind(line, '*POINTS_TABLE'))
            write = 0;
        end
        
        
    end
    
    
  
    fclose(file);
    
     file = fopen('C:\Users\dfcdc0\Desktop\RRT\Roads\AniGroup\AniRep_ac0ea8ab-67b6-445b-917e-c362e25c241b.par','wt');
%     file = fopen('C:\Users\Edo\Desktop\AniRep_56ae7af6-ceb0-4b3b-a2c4-5a638f841609.par','wt');

   
    for i=1:length(fileContent)
      
    fprintf(file, '%s', fileContent{i}) ;  
           
       if ~isempty(strfind(fileContent{i}, '*POINTS_TABLE '))
       fprintf(file, '\n') ;  

           for j =1:length(paramsObst.theta)         
               for k=1:paramsObst.l(j)                 
                   A = [cos(paramsObst.theta(j)), -sin(paramsObst.theta(j)); sin(paramsObst.theta(j)), cos(paramsObst.theta(j))];
                   x = (k-1);
                   y = -paramsObst.w(j)/2;
                   coor = A*[x; y] + paramsObst.offset{j};
                   fprintf(file, '%s \n', [num2str(coor(1)) ', ' num2str(coor(2))]) ; 
               end 
           end           
       end
   
    end
    
    fclose(file);
end
