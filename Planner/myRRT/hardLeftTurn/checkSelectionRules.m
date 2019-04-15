%%%% script that checks exit rules

good2delete = false;


    
%%%%% dispatch for default    
if  strcmp(primitive, 'default')
    counter = 0;
    
end
 
%%%% dispatch for handbrake turn    
if  strcmp(primitive, 'hardLeftTurn')
    counter = 1;
    idNode = addedNodeId;
end