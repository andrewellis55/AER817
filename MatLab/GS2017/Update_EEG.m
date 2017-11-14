function [] = Update_EEG(handles)
%Everything for the EEG goes in here, including sub functions

%% Instructions
%
%   -all variables that will be plotted should be set as handles.variableName
%   -to plot, use plot(handles.xVarName, handles.yVarName, STYLE (ex. 'r-') ,'Parent', handles.axEEG);
%   -In each loop, the data should be pulled from the EEG, and plotted
%       then it should be analysed for the 'paniced' condition
%
%% Main Code

% After reading in 2 seconds of sensor data
avg_sens1 = mean([IXDATA.raw.eeg.data(:,1)]);
avg_sens4 = mean([IXDATA.raw.eeg.data(:,4)]);
time = linspace(0,2,length(IXDATA.raw.eeg.data(:,1)));
sensor1 = IXDATA.raw.eeg.data(:,1);
sensor4 = IXDATA.raw.eeg.data(:,4);

% Blink check
n=1;
blink = 0;
while (n<=457)

% Sensor 1 blink check
if (sensor1(n) > avg_sens1*1.20 || sensor1(n) < avg_sens1*0.5)
    blink = 1;
end

% Sensor 4 blink check
if (sensor4(n) > avg_sens4*1.20 || sensor4(n) < avg_sens4*0.5)
    blink = 1;
end

n = n+1;
end






end

