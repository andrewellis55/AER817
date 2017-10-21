function [] = updateGUI_payloadTable(handles, dataMatrixPayload, pk)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

data = num2cell(dataMatrixPayload(1:pk,1:11));
data(:,2) = cellstr('PAYLOAD');
set(handles.uitablePayload, 'Data', data);
end

