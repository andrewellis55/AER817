function [] = Update_GUIgraph(handles, table_filename)
% First fill the tables with appropriate columns.
% This function then takes the data in the table and plots it with
% specifications from the axis popup menus.


% "container became device"

global matrix;

handles.payloadData = matrix.payload;
handles.deviceData = matrix.device;
char dataSouce;
dataSource = get(handles.graphDataSelect, 'Value');
xAxis = get(handles.graphxAxis, 'Value');
yAxis = get(handles.graphyAxis, 'Value');

% handles.xpayload = handles.payloadData(:,xAxis+2);
% handles.ypayload = handles.payloadData(:,yAxis+2);
% %--
switch dataSource
    case 1 % ON-PERSON DEVICE DATA
        switch xAxis
            case 1
                handles.xdevice = handles.deviceData(:,3);
            case 2
                handles.xdevice = handles.deviceData(:,4);
            case 3
                handles.xdevice = handles.deviceData(:,5);
            case 4
                handles.xdevice = handles.deviceData(:,6);
            case 5
                handles.xdevice = handles.deviceData(:,7);
            case 6
                handles.xdevice = handles.deviceData(:,8);
            case 7
                handles.xdevice = handles.deviceData(:,9);
            case 8
                handles.xdevice = handles.deviceData(:,10);
            case 9
                handles.xdevice = handles.deviceData(:,11);
            case 10
                handles.xdevice = handles.deviceData(:,12);
            case 11
                handles.xdevice = handles.deviceData(:,13);
            case 12
                handles.xdevice = handles.deviceData(:,14);
            otherwise 
                handles.xdevice = 0;
        end
        switch yAxis
            case 1
                handles.ydevice = handles.deviceData(:,3);
            case 2
                handles.ydevice = handles.deviceData(:,4);
            case 3
                handles.ydevice = handles.deviceData(:,5);
            case 4
                handles.ydevice = handles.deviceData(:,6);
            case 5
                handles.ydevice = handles.deviceData(:,7);
            case 6
                handles.ydevice = handles.deviceData(:,8);
            case 7
                handles.ydevice = handles.deviceData(:,9);
            case 8
                handles.ydevice = handles.deviceData(:,10);
            case 9
                handles.ydevice = handles.deviceData(:,11);
            case 10
                handles.ydevice = handles.deviceData(:,12);
            case 11
                handles.ydevice = handles.deviceData(:,13);
            case 12
                handles.ydevice = handles.deviceData(:,14);
            otherwise 
                handles.ydevice = 0;
        end
    case 2 %PAYLOAD DATA
        switch xAxis
            case 1
                handles.xpayload = handles.payloadData(:,3);
            case 2
                handles.xpayload = handles.payloadData(:,4);
            case 3
                handles.xpayload = handles.payloadData(:,5);
            case 4
                handles.xpayload = handles.payloadData(:,6);
            case 5
                handles.xpayload = handles.payloadData(:,7);
            case 6
                handles.xpayload = handles.payloadData(:,8);
            case 7
                handles.xpayload = handles.payloadData(:,9);
            case 8
                handles.xpayload = handles.payloadData(:,10);
            case 9
                handles.xpayload = handles.payloadData(:,11);
            case 10
                handles.xpayload = handles.payloadData(:,12);
            case 11
                handles.xpayload = handles.payloadData(:,13);
            case 12
                handles.xpayload = handles.payloadData(:,14);
            otherwise 
                handles.xpayload = 0;
        end
        switch yAxis
            case 1
                handles.ypayload = handles.payloadData(:,3);
            case 2
                handles.ypayload = handles.payloadData(:,4);
            case 3
                handles.ypayload = handles.payloadData(:,5);
            case 4
                handles.ypayload = handles.payloadData(:,6);
            case 5
                handles.ypayload = handles.payloadData(:,7);
            case 6
                handles.ypayload = handles.payloadData(:,8);
            case 7
                handles.ypayload = handles.payloadData(:,9);
            case 8
                handles.ypayload = handles.payloadData(:,10);
            case 9
                handles.ypayload = handles.payloadData(:,11);
            case 10
                handles.ypayload = handles.payloadData(:,12);
            case 11
                handles.ypayload = handles.payloadData(:,13);
            case 12
                handles.ypayload = handles.payloadData(:,14);
            otherwise 
                handles.ypayload = 0;
        end
    case 3 % MAP AND 3D PLOT OUTPUT
        handles.device_x = handles.deviceData(:,6);
        handles.device_y = handles.deviceData(:,7);
        handles.device_z = handles.deviceData(:,8);

        handles.payload_x = handles.payloadData(:,5);
        handles.payload_y = handles.payloadData(:,6);
        handles.payload_z = handles.payloadData(:,7);  
    case 4
        lonAxis = [-79.3832 -79.3765];
        latAxis = [43.6565 43.6603];
        refLat = 43.658786;
        refLon = -79.380268;
        % pos_x(pk) = cumsum(dx(pk)); % Summation of delta changes in x,y,z position
        % pos_y(pk) = cumsum(dy(pk));
        % pos_z(pk) = cumsum(dz(pk));

        % lat_pos(pk) = round((pos_x(pk) / 111000) + refLat;
        % lon_pos(pk) = round((pos_y(pk) / (111000 * cos(lat_pos(pk)))) + refLon);
end
%--

cla(handles.Graph1);
grid(handles.Graph1, 'on');
hold(handles.Graph1,'on');


switch dataSource
    case 1
        plot(handles.xdevice, handles.ydevice, '.-r','Parent', handles.Graph1);
    case 2    
        plot(handles.xpayload, handles.ypayload, '.-b','Parent', handles.Graph1);
    case 3
%         plot3(handles.payload_x, handles.payload_y, handles.payload_z, '.-k','Parent', handles.Graph1);
    case 4
        
        markerLoc = char(strcat({num2str(refLat,8)},{' '},{num2str(refLon,8)}));
        axes(handles.Graph1)
        axis([lonAxis, latAxis])
        plot_google_map('Axis',handles.Graph1,'Marker',markerLoc,'MapType','hybrid')

      



end

