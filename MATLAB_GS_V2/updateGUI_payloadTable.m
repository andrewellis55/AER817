function [] = updateGUI_payloadTable(handles, dataMatrixPayload, pk)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

data = num2cell(dataMatrixPayload(1:pk,1:14));
if (pk < 6)
 tableData = num2cell(dataMatrixPayload(1:pk,1:14));   
else
    tableData = num2cell(dataMatrixPayload(pk-5:pk,1:14));  
end

% data(:,2) = cellstr('PAYLOAD');
set(handles.uitablePayload, 'Data', tableData);
end

