function [] = updateGUI_deviceTable(handles, dataMatrixDevice, pk)
%UNTITLED Summary of this function goes here

data = num2cell(dataMatrixDevice(1:pk,1:11));
% data = dataMatrixGlider(1:pk,1:11);
% data(:,2) = cellstr('DEVICE');
set(handles.uitableDevice, 'Data', data);

end

