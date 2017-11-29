function [triggered] = Update_EEG(handles, EEG_input)
%Everything for the EEG goes in here, including sub functions

%% Instructions
%
%   -all variables that will be plotted should be set as handles.variableName
%   -to plot, use plot(handles.xVarName, handles.yVarName, STYLE (ex. 'r-') ,'Parent', handles.axEEG);
%   -In each loop, the data should be pulled from the EEG, and plotted
%       then it should be analysed for the 'paniced' condition
%
%% Main Code

% Trigger Initialization
 triggered = 0;

 %Blink Machine Learning SVM Initialization
xdata = [1051,1300];
group = ['r', 'p'];
svmBlinkStruct = svmtrain(xdata,group);
 
%Panic Machine Learning SVM Initialization
xdata = [950,1050];
group = ['r', 'p'];
svmPanicStruct = svmtrain(xdata,group);
 
 
% Sensor 1 blink check
sen1blink = svmclassify(svmBlinkStruct,EEG_input(end,1))
if ( sen1blink == 'p')
    triggered = 1;
end

% Sensor 4 blink check
sen4blink = svmclassify(svmBlinkStruct,EEG_input(end,4))
if ( sen4blink == 'p')
    triggered = 1;
end

% Sensor 1 Panic check
sen1panic = svmclassify(svmPanicStruct,EEG_input(end,1))
if ( sen1panic == 'p')
    triggered = 1;
end

% Sensor 4 Panic check
sen4panic = svmclassify(svmPanicStruct,EEG_input(end,4))
if ( sen4panic == 'p')
    triggered = 1;
end





end

