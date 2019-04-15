function [areas, primitives] = defineAreasAndPrimitives()
   
    poly = [130; 92];
    poly = [poly [179; 92]];
    poly = [poly [179; 106]];
    poly = [poly [140; 106]];
    poly = [poly [140; 99]];
    poly = [poly [130; 99]];
    
    areas = cell(1);
    areas{1} = poly;
    primitives = cell(1,1);
    primitives{1} = 'handbrakeTurn';

    poly = [100; 92];
    poly = [poly [130; 92]];
    poly = [poly [130; 99]];
    poly = [poly [100; 99]];
    areas{2} = poly;
    primitives{2} = 'tightPassage';

    
    poly = [115; 99];
    poly = [poly [140; 99]];
    poly = [poly [140; 106]];
    poly = [poly [115; 106]];
    areas{3} = poly;
    primitives{3} = 'tightPassage2';





end