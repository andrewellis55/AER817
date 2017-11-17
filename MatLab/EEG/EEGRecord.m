% osc_server_muse;
system('taskkill -f -im muse-player.exe ');
system('taskkill -f -im muse-io.exe ');

system('start "Running: C:\AER817\Project\Muse\muse-io.exe --no-dsp --preset AD --device Muse-4C03" "C:\AER817\Project\Muse\muse-io.exe" --osc osc.tcp://localhost:5000');
pause(10)
blink = 0;
i = 1;

while(i <=4)
    EEGData = [];
    pause(1)
    cmd = strcat('start muse-player.exe -l 5000 -M C:\AER817\Project\eeg_recording', num2str(i), '.mat -s 5001');
    system(cmd);
    pause(1)
    
    tic;
    while(toc <= 2)
        toc;
    end
    
    system('taskkill /im muse-player.exe ');
    pause(5)
    file = strcat('eeg_recording', num2str(i), '.mat')
    EEG_input = load(file);
    plotEEG(EEG_input);
    
    
    %    file = strcat('C:\AER817\Project\eeg_recording', i, '.mat');
    %    pause(1)
    %    system('taskkill -f -im muse-player.exe ');
    %    blink =  Update_EEG(EEG_input);
    
    
    i = i+1;
    pause(2)
end

system('taskkill -f -im muse-player.exe ');
system('taskkill -f -im muse-io.exe ');










% t = tcpip('0.0.0.0', 5555, 'NetworkRole', 'client')
% fopen(tcpclient('localhost',5555))
%
% load('EEG_Recording.mat');
%
% EEG1 = IXDATA.raw.eeg.data(:,1);
% EEG2 = IXDATA.raw.eeg.data(:,2);
% EEG3 = IXDATA.raw.eeg.data(:,3);
% EEG4 = IXDATA.raw.eeg.data(:,4);
%
% x = linspace(0,10,length(EEG1));
%
% plot(x,EEG1)
% hold on
% plot(x,EEG2)
% plot(x,EEG3)
% plot(x,EEG4)