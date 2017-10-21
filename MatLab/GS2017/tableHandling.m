function [] = tableHandling(packet, handles)
% After creating the csv file and writing to it from serial, this function
% is called. Takes RAW CSV file and checks each row of column 3 (see mission
% guideline for future use.
% 'glider'. Determines which table to fill on GUI.


%{
Victim Device
---------------
1 - Device ID
~ - DEVICE
2 - TeleMissionTime
3 - Paniced (1 true 0 flase)
4 - Time since panic
5 - Relative Lat
6 - Relative Long
7 - Relative Alt
8 - GPS Lat    *GPS will send 9999 and can pretty much be ignored
9 - GPS Long
10 - GPS Alt



Payload
-------------
1 - Device ID
~ - PAYLOAD
2 - TeleMissionTime
3 - Relative Lat
4 - Relative Long
5 - Relative Alt
6 - GPS Lat    *GPS will send 9999 and can pretty much be ignored
7 - GPS Long
8 - GPS Alt
9 - Human Presensce Front
10 - Human Presensce Right
11 - Human Presensce Left
12 - Human Presensce Back

%}


%% MODIFY THIS SECTION BASED ON ABOVE PACKETS
global matrix;

tele = strsplit(packet, ',');
isDeployed = 0;


%packet count
pk = str2num(tele{3});

if (ismember('DEVICE', tele{2}))
    matrix.device(pk, 1) = str2num(tele{1});
    matrix.device(pk,2) = 0;
    for i = 3:12
        matrix.device(pk, i) = str2num(tele{i}) ;
    end
    updateGUI_deviceTable(handles,matrix.device, pk);
   
else
    matrix.payload(pk, 1) = str2num(tele{1});
    matrix.payload(pk,2) = 0;
    for i = 3:12
        matrix.payload(pk, i) = str2num(tele{i});
    end
    
    if (matrix.payload(pk, 9) == 1 && isDeployed == 0)
        %This section can be changed from deployed to paniced
        isDeployed = 1;
        set(handles.deploymentButton, 'BackgroundColor', [0.26 0.96 0.49]);
        set(handles.deploymentButton, 'String', 'Is Deployed: T');
        msgbox('device has been deployed!');

    else 
        set(handles.deploymentButton, 'BackgroundColor','yellow');
    end
    %modify
    updateGUI_payloadTable(handles,matrix.payload, pk);
end
   


end

