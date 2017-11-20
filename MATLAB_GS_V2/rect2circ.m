function [pos] = rect2circ(x, y, r)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

    x1 = x-r;
    x2 = 2*r;
    y1 = y-r;
    y2 = 2*r;
    
    pos = [x1,y1, x2, y2];

end

