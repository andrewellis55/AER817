void getRadioData(){
  //Gets Data from the serial
   if(Serial.available()){
//    receiveSerialData();
  }
}

void sendRadioData() {
  //Sends location & panic button state
  Serial1.print(telemetry[teleCount]);
  Serial1.print(',');
  Serial1.print(telemetry[teleButton]);
  Serial1.print(',');
  Serial1.print(telemetry[teleIMUx]);
  Serial1.print(',');
  Serial1.print(telemetry[teleIMUy]);
  Serial1.print(',');
  Serial1.print(telemetry[teleIMUz]);
  Serial1.println(',');


  //DEBUG STUFF
  Serial.print(telemetry[teleCount]);
  Serial.print(',');
  Serial.print(telemetry[teleButton]);
  Serial.print(',');
  Serial.print(telemetry[teleIMUx]);
  Serial.print(',');
  Serial.print(telemetry[teleIMUy]);
  Serial.print(',');
  Serial.print(telemetry[teleIMUz]);
  Serial.println(',');
}
