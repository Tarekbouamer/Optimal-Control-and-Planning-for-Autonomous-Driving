function [areas, primitives] = defineAreasAndPrimitives()
  
    poly = [52; 0];
    poly = [poly [64; 0]];
    poly = [poly [64; 19]];
    poly = [poly [52; 19]];
      
    areas = cell(1);
    areas{1} = poly;
    primitives = cell(1,1);
    primitives{1} = 'gymkhana';
     
    poly = [34; 10.75];
    poly = [poly [52; 10.75]];
    poly = [poly [52; 17.7]];
    poly = [poly [34; 17.7]];
   
    areas{2} = poly;
    primitives{2} = 'tightPassage';
    
    

    





end