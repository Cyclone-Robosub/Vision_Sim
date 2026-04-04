function position = getWorldToImage(r4, cameraPos)
    position = r;
end


function cExt = getCameraExtrinsic(cameraPos)
    RM = getRollMatrix(cameraPos(4));
    PM = getPitchMatrix(cameraPos(5));
    YM = getYawMatrix(cameraPos(6));
    translationM = [1 0 0 -cameraPos(1); 0 1 0 -cameraPos(2); 0 0 1 -cameraPos(3); 0 0 0 1];
    rotationM = rotationM;
end

function rollM = getRollMatrix(roll)
    rollM = [1 0 0; 0 cos(roll) -sin(roll); 0 sin(roll) cos(roll)];
end

function pitchM = getPitchMatrix(pitch)
    pitchM = [cos(pitch) 0 sin(pitch); 0 1 0; -sin(pitch) 0 cos(pitch)];
end

function yawM = getYawMatrix(yaw)
    yawM = [cos(yaw) -sin(yaw) 0; sin(yaw) cos(yaw) 0; 0 0 1];
end