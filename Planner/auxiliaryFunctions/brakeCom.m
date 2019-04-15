function [torques] = brakeCom(forces, wF, wR, params, inputs)

% params has: R, gammaB, gammaM, maxTm, maxTb, maxThb 
% inputs: [delta, brake, handbrake, throttle]
% omega has: R, F
% forces has: FxF, FyF, FyR
% torques has: TbF, TbR, TmF, TmR

torques.TmF = inputs(4) * params.maxTm;
torques.TmR = torques.TmF * params.gammaM;
torques.TmF = torques.TmF * (1-params.gammaM);

handbrake = inputs(3) * params.maxThb;
brake = inputs(2) * params.maxTb;


TbF = 0;
TbR = 0;
 
if brake > 0
   
    if wF ~= 0
        TbF = - brake * (1-params.gammaB);
    else
        TbF = forces.FxF * params.R;
    end
    
    if wR ~= 0
        TbR = TbR - brake * params.gammaB;
    else
        TbR = forces.FxR * params.R;
    end
end

if handbrake > 0
   
    if wR ~= 0
        TbR = TbR - handbrake;
    else
        TbR = forces.FxR * params.R;
    end   
end
   

torques.TbF = TbF;

 
torques.TbR = TbR;



end