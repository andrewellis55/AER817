function [blink] = Update_EEG(handles, EEG_input)
%Everything for the EEG goes in here, including sub functions

%% Instructions
%
%   -all variables that will be plotted should be set as handles.variableName
%   -to plot, use plot(handles.xVarName, handles.yVarName, STYLE (ex. 'r-') ,'Parent', handles.axEEG);
%   -In each loop, the data should be pulled from the EEG, and plotted
%       then it should be analysed for the 'paniced' condition
%
%% Main Code

% Blink check
 blink = 0;

% Sensor 1 blink check
if ( EEG_input(end,1) > 1000)
    blink = 1;
end

% Sensor 4 blink check
if (EEG_input(end,4) > 1000)
    blink = 1;
end

end

