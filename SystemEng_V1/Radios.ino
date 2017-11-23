void sendRadioData() {
  //Sends data to GS

#ifdef DEVICE //SERIAL1 OUTPUT FOR XBEE ONPERSON DEVICE
  for (int i = 0; i < teleSize; i++)
  {
    Serial1.print(telemetry[i]);
    Serial1.print(',');
  }

  Serial1.println(' ');
#endif

#ifdef PAYLOAD  //SERIAL1 NEEDS TO BE CHANGED TO SOFTWARE SERIAL FOR XBEE OUTPUT ON PAYLOAD PCB
  for (int i = 0; i < teleSize; i++)
  {
    Serial.print(telemetry[i]);
    Serial.print(',');
  }

  Serial.println(' ');
#endif

  
#ifdef DEBUG //DEBUG OUTPUT TO SERIAL MONITOR
  for (int i = 0; i < teleSize; i++)
  {
    Serial.print(telemetry[i]);
    Serial.print(',');
  }

  Serial.println(' ');
#endif
}
