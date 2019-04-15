%%%% script that checks exit rules

good2delete = false;

%%%%% dispatch for tight passage 1
    if strcmp(primitiveStart, 'tightPassage')    
         if nodes.leaf(idNode) && (nodes.crashCount(idNode) > 0 || ~good2exit)
            good2delete = true; 
         end
    end
    
    
    
%%%%% dispatch for tight passage 2
if strcmp(primitiveStart, 'tightPassage2')     
   if nodes.leaf(idNode) && (nodes.crashCount(idNode) > 0 || ~good2exit)
        good2delete = true; 
   end
end
    
%%%%% dispatch for default    
    if  strcmp(primitiveStart, 'default')
          if nodes.leaf(idNode)  && nodes.crashCount(idNode) > 2 && idNode ~= 1 
                good2delete = true;
          end
    end
 
%%%% dispatch for handbrake turn    
    if strcmp(primitiveStart, 'handbrakeTurn')
        
    end