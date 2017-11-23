void sendRadioData() {
  //Sends data to GS

  for(int i = 0; i < teleSize; i++)
  {
    xbee.print(telemetry[i]);
    xbee.print(',');
  }
  
  xbee.println(' ');

  //DEBUG OUTPUT
  #ifdef DEBUG
  for(int i = 0; i < teleSize; i++)
  {
    Serial.print(telemetry[i]);
    Serial.print(',');
  }
  
  Serial.println(' ');
  #endif
}
