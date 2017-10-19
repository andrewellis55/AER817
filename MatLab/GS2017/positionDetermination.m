function [ ] = positionDetermination(pk)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

    vel = matrix.glider(:,6); % Velocity from pitot tube
    heading = matrix.glider(:,9); % Direction from magnometer (degrees)
    pitch = matrix.glider(:,13); % Placeholder for pitch data (degrees)

    dx(pk) = vel(pk) * cosd(heading(pk)) * cosd(pitch(pk)); % Change in x,y,z position over 1 second update interval
    dy(pk) = vel(pk) * sind(heading(pk)) * cosd(pitch(pk));
    dz(pk) = vel(pk) * sind(pitch(pk));

    px = 0; % Original position, to be set to container GPS location at time of deployment
    py = 0;

    px = cumsum(dx); % Summation of delta changes in x,y,z position
    py = cumsum(dy);
    pz = cumsum(dz);

    
end

