%%
data = {''};
u1 = udp('127.0.0.1',777,'LocalPort',777);
 
u1.InputBufferSize = 1024;
 
u1.DatagramTerminateMode = 'on';
 
%u1.DatagramReceivedFcn = {'udpcallback'};
 
fopen(u1);
 
%%
buf = 400;
dataVec = zeros(buf,7);
refresh = .02;
tic;
startTime = toc;
lastTime = startTime;
go = 1;
 
while(go)
 
str = fscanf(u1)
parts = strsplit(str,',');
newVec = zeros(1,7);
if(length(parts)==7)
 for jj = 1:7
 if(length(str2num(parts{jj}))==0)
 newVec(jj)=0;
 else
 newVec(jj) = str2num(parts{jj});
 end
 end
end
 
dataVec(1:end-1,:) = dataVec(2:end,:);
dataVec(end,:) = newVec;
 
if(toc-lastTime > 10)
 figure(1)
 plot(dataVec(:,1:6))
 title(num2str(mean(diff(dataVec(:,7)))))
 drawnow;
 lastTime = toc;
end
 
if(1==1)
 go = 0;
end
 
end
 
%%
fclose(u1); delete(u1)