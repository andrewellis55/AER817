function [] = humanSense(handles,data)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

front = data(1);
right = data(2);
left = data(3);
back = data(4);


rectangle(handles.axProximity, 'Position',rect2circ(2.5,5,2.5),'Curvature',[1 1], 'FaceColor',[map(left) 0 0])
rectangle(handles.axProximity, 'Position',rect2circ(5,2.5,2.5),'Curvature',[1 1], 'FaceColor',[map(back) 0 0])
rectangle(handles.axProximity, 'Position',rect2circ(7.5,5,2.5),'Curvature',[1 1], 'FaceColor',[map(right) 0 0])
rectangle(handles.axProximity, 'Position',rect2circ(5,7.5,2.5),'Curvature',[1 1], 'FaceColor',[map(front) 0 0])

axis(handles.axProximity, 'equal')
axis(handles.axProximity, [0 10 0 10])


end

