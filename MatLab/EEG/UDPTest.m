data = {''};
u1 = udp('127.0.0.1',765,'LocalPort',777);
 
u1.InputBufferSize = 1024;

 
 
u1.DatagramTerminateMode = 'on';
 
%u1.DatagramReceivedFcn = {'udpcallback'};
 
fopen(u1);


for a = 1:10
str = fscanf(u1)
str(end-31:end)
%data = sscanf(str)
%data = split(str,',')

pause(0.2)
end 



fclose(u1); 
delete(u1)