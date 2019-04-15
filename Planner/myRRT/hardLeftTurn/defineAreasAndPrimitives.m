function [areas, primitives] = defineAreasAndPrimitives(vector)
    
 
   
    poly1 = [100; -1.0675];
    poly1 = [poly1 [ 125; -1.0675]];
    poly1 = [poly1 [ 125; 1.0675]];
    poly1 = [poly1 [ 100; 1.0675]];
    
    
    areas = cell(1);
    areas{1} = poly1;
    primitives = cell(2,1);
    primitives{1} = 'straight2';
    

    poly2 = [47; -1.0675+3.5];
    poly2 = [poly2 [68; -1.0675+3.5]];
    poly2 = [poly2 [68; 1.0675+3.5]];
    poly2 = [poly2 [47; 1.0675+3.5]];
    
    areas{2} = poly2;
    primitives{2} = 'straight1';
    
	
    poly3 = [10; -0.9225];
    poly3 = [poly3 [45; -0.9225]];
    poly3 = [poly3 [45; 0.9 ]];
    poly3 = [poly3 [10; 0.9 ]];
    
    areas{3} = poly3;
    primitives{3} = 'turnleft';
    
	poly4 = [68; -1.0675+3.5];
    poly4 = [poly4 [95; -1.0675+3.5]];
    poly4 = [poly4 [95; 1.0675+3.5]];
    poly4 = [poly4 [68; 1.0675+3.5]];
    
    areas{4} = poly4;
    primitives{4} = 'turnright';
    
	poly5 = [15; -1.1+3.5];
    poly5 = [poly5 [47; -1.1+3.5]];
    poly5 = [poly5 [47; 1.0675+3.5]];
    poly5 = [poly5 [15; 1.0675+3.5]];
    
    areas{5} = poly5;
    primitives{5} = 'turnright';
    
	poly6 = [70; -1.0675];
    poly6 = [poly6 [100; -1.0675 ]];
    poly6 = [poly6 [100; 1.0675 ]];
    poly6 = [poly6 [70; 1.0675 ]];
    
    areas{6} = poly6;
    primitives{6} = 'turnleft';
    
	poly7 = [15; 0.9];
    poly7 = [poly7 [45; 0.9 ]];
    poly7 = [poly7 [45; -1.1+3.5 ]];
    poly7 = [poly7 [15; -1.1+3.5 ]];
    
    areas{7} = poly7;
    primitives{7} = 'backturnright';
    
	poly8 = [70; 1.0675];
    poly8 = [poly8 [95; 1.0675 ]];
    poly8 = [poly8 [95; -1.0675+3.5 ]];
    poly8 = [poly8 [70; -1.0675+3.5 ]];
    
    areas{8} = poly8;
    primitives{8} = 'backturnleft';
end