function [y2] = map(x2)

x1 =000;
x3 = 400;
y1 = 0;
y3 = 1;

y2 = (x2-x1)*(y3-y1)/(x3-x1) + y1;

if (y2 <y1)
    y2=y1;
end

if (y2>y3)
    y2=y3;
end

end

