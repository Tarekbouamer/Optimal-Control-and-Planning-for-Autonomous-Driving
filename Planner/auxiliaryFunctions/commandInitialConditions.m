function params = commandInitialConditions(delta, brake, handbrake, throttle)

    INIT_PBK_L1 = 13*brake;
    INIT_PBK_R1 = 13*brake;
    INIT_PBK_L2 = proportioning(13*brake) + handbrake*2000/150;
    INIT_PBK_R2 = proportioning(13*brake) + handbrake*2000/150;
    INIT_STEER_SW = delta * 180/pi/0.0581597;
    INIT_THROTTLE_ENGINE = throttle;

    params(1) = INIT_PBK_L1;
    params(2) = INIT_PBK_R1;
    params(3) = INIT_PBK_L2;
    params(4) = INIT_PBK_R2;
    params(5) = INIT_STEER_SW;
    params(6) = INIT_THROTTLE_ENGINE;
    
    
    

end
