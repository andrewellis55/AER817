function [] = updateGUI_deviceTable(handles, dataMatrixDevice, pk)
%UNTITLED Summary of this function goes here

data = num2cell(dataMatrixDevice(1:pk,1:11));

if (pk < 6)
 tableData = num2cell(dataMatrixPayload(1:pk,1:14));   
else
    tableData = num2cell(dataMatrixPayload(pk-5:pk,1:14));  
end
% data = dataMatrixGlider(1:pk,1:11);
% data(:,2) = cellstr('DEVICE');
set(handles.uitableDevice, 'Data', tableData);

end

