function [] = tableHandling(packet, handles)
% After creating the csv file and writing to it from serial, this function
% is called. Takes RAW CSV file and checks each row of column 3 (see mission
% guideline for future use.
% 'glider'. Determines which table to fill on GUI.


%{
Victim Device
---------------
1 - Team ID
2 - DEVICE (2 = victim device)
3 - Packet Count
4 - Button state (1 true 0 false)
5 - BMP Altitude
6 - IMU x
7 - IMU y
8 - IMU z
9 - GPS Lat    *GPS will send 9999 and can pretty much be ignored
10 - GPS Long
11 - GPS Alt

Payload
-------------
1 - Team ID
2 - DEVICE (1 = payload device)
3 - Packet Count
4 - BMP Altitude
5 - IMU x
6 - IMU y
7 - IMU z
8 - GPS Lat    *GPS will send 9999 and can pretty much be ignored
9 - GPS Long
10 - GPS Alt
11- Human Presensce Front
12 - Human Presensce Right
13 - Human Presensce Left
14 - Human Presensce Back

%}


%% MODIFY THIS SECTION BASED ON ABOVE PACKETS
global matrix;

tele = strsplit(packet, ',');
isDeployed = 0;


%packet count
pk = str2num(tele{3});

if (ismember('1', tele{2}))
    for i = 1:14
        matrix.payload(pk, i) = str2num(tele{i}) ;
    end
   updateGUI_payloadTable(handles,matrix.payload, pk);
   
elseif (ismember('2', tele{2}))
%     matrix.device(pk, 1) = str2num(tele{1});
%     matrix.device(pk,2) = 0;
    for i = 1:11
        matrix.device(pk, i) = str2num(tele{i});
    end
    
    if (matrix.device(pk, 4) == 1 && isDeployed == 0)
        %This section can be changed from deployed to paniced
        isDeployed = 1;
        set(handles.deploymentButton, 'BackgroundColor', [0.26 0.96 0.49]);
        set(handles.deploymentButton, 'String', 'PANIC');
        msgbox('device has been deployed!');

    else 
        set(handles.deploymentButton, 'BackgroundColor','yellow');
    end
    %modify

   updateGUI_deviceTable(handles,matrix.device, pk);
   
end
   


end

