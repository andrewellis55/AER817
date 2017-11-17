function plotEEG(EEG_input)
avg_sens1 = mean([EEG_input.IXDATA.raw.eeg.data(:,1)]);
avg_sens4 = mean([EEG_input.IXDATA.raw.eeg.data(:,4)]);
time = linspace(0,20,length(EEG_input.IXDATA.raw.eeg.data(:,1)));
sensor1 = EEG_input.IXDATA.raw.eeg.data(:,1);
sensor4 = EEG_input.IXDATA.raw.eeg.data(:,4);

% Finding max and min of entire data (Sensor 1)
indexmin = find(min(sensor1) == sensor1); 
x_1min = time(indexmin); 
y_1min = sensor1(indexmin);

indexmax = find(max(sensor1) == sensor1);
x_1max = time(indexmax);
y_1max = sensor1(indexmax);

% Finding max and min of entire data (Sensor 4)
indexmin = find(min(sensor4) == sensor4); 
x_4min = time(indexmin); 
y_4min = sensor4(indexmin);

indexmax = find(max(sensor4) == sensor4);
x_4max = time(indexmax);
y_4max = sensor4(indexmax);


n = 1;
data1_2sec = zeros(228*2,1);

%2 Second of data (Sensor 1)
while (n<=228*2)
    data1_2sec(n) = EEG_input.IXDATA.raw.eeg.data(n,1);
    n = n+1; 
end

%Finding max and min of 2 second data (Sensor 1)
indexmin = find(min(data1_2sec) == data1_2sec); 
x_1min_2sec = time(indexmin); 
y_1min_2sec = data1_2sec(indexmin);

indexmax = find(max(data1_2sec) == data1_2sec);
x_1max_2sec = time(indexmax);
y_1max_2sec = data1_2sec(indexmax);

n = 1;
data1_4sec = zeros(228*2,1);

%2 Second of data (Sensor 4)
while (n<=228*2)
    data4_2sec(n) = EEG_input.IXDATA.raw.eeg.data(n,4);
    n = n+1; 
end

%Finding max and min of 2 second data (Sensor 1)
indexmin = find(min(data4_2sec) == data4_2sec); 
x_4min_2sec = time(indexmin); 
y_4min_2sec = data4_2sec(indexmin);

indexmax = find(max(data4_2sec) == data4_2sec);
x_4max_2sec = time(indexmax);
y_4max_2sec = data4_2sec(indexmax);


% Look at plots
figure(1)
subplot(2,1,1)
hold on
plot(time,sensor1)
plot(x_1min,y_1min,'b*')
plot(x_1max,y_1max,'r*')
plot(x_1min_2sec,y_1min_2sec,'b*')
plot(x_1max_2sec,y_1max_2sec,'r*')
refline(0,avg_sens1)
title('Left ear sensor normal blinks with one heavy blink')
ylabel('mV')
xlabel('time (sec)')
hold off

subplot(2,1,2)
hold on
plot(time,sensor4)
refline(0,avg_sens4)
plot(x_4min,y_4min,'b*')
plot(x_4max,y_4max,'r*')
plot(x_4min_2sec,y_4min_2sec,'b*')
plot(x_4max_2sec,y_4max_2sec,'r*')
title('Right ear sensor normal blinks with one heavy blink')
ylabel('mV')
xlabel('time (sec)')
hold off

% Variations
max_var_1 = y_1max - avg_sens1
max_var_1_2sec = y_1max_2sec - avg_sens1

min_var_1 = y_1min - avg_sens1
min_var_1_2sec = y_1min_2sec - avg_sens1

max_var_4 = y_4max - avg_sens4
max_var_4_2sec = y_4max_2sec - avg_sens4

min_var_4 = y_4min - avg_sens4
min_var_4_2sec = y_4min_2sec - avg_sens4

end