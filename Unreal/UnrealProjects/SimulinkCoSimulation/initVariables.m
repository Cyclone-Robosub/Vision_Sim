ddxFilter = zeros(1080,1920);
ddyFilter = zeros(1080,1920);
for l = 0:1079
    for k = 0:1919
        ddyFilter(l+1,k+1) = (2i * pi / 1080 * l);
    end
end
for l = 0:1079
    for k = 0:1919
        ddxFilter(l+1,k+1) = (2i * pi / 1920 * k);
    end
end