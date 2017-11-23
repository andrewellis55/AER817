function [] = setCOMPort(handles)
%setCOMPort sets available serial port of the arduino
%   Looks up all available ports and sets the proper port. If no port,
%   displays EMPTY PORTS.

% Returns serial prot HW information as object.
info = instrhwinfo('serial');
availPorts = info.SerialPorts; % Returns matrix

if (numel(availPorts) ~=0)
    %COM1 Port
    set(handles.COMSelect, 'String', availPorts);
    set(handles.COMSelect, 'Value', numel(availPorts));
    %COM2 Port
    set(handles.COM2Select, 'String', availPorts);
    set(handles.COM2Select, 'Value', numel(availPorts));
else
    set(handles.COMSelect, 'String', 'PORTS EMPTY');
    set(handles.COMSelect, 'Value', 1);    
   
    set(handles.COM2Select, 'String', 'PORTS EMPTY');
    set(handles.COM2Select, 'Value', 1); 
end

end

