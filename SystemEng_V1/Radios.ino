void sendRadioData() {
  //Sends data to GS

  for(int i = 0; i < teleSize; i++)
  {
    //Serial1.print(telemetry[i]);
    //Serial1.print(',');
  }
  
  //Serial1.println(' ');

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
