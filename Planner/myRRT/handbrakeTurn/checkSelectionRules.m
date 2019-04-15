%%%% script that checks exit rules

good2delete = false;

%%%%% dispatch for tight passage 1
if strcmp(primitive, 'tightPassage')    
    counter = 1;
    idNode = addedNodeId;
end
            
    
%%%%% dispatch for tight passage 2
if strcmp(primitive, 'tightPassage2')     
   counter = 1;
   idNode = addedNodeId;
end
    
%%%%% dispatch for default    
if  strcmp(primitive, 'default')
    counter = 0;
end
 
%%%% dispatch for handbrake turn    
if strcmp(primitive, 'handbrakeTurn')
    counter = 20;
    idNode = addedNodeId;
end