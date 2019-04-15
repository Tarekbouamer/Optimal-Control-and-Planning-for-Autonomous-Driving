function [ cPress ] = proportioning( lPress )

if lPress <= 1.5
    cPress = lPress;
else
    cPress = 0.3 * lPress + 1.05;
end

end

