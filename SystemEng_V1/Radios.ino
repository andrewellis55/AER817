void sendRadioData() {
  //Sends data to GS

#ifdef DEVICE //SERIAL1 OUTPUT FOR XBEE ONPERSON DEVICE
  for (int i = 0; i < teleSize; i++)
  {
    xbee.print(telemetry[i]);
    xbee.print(',');
  }
<<<<<<< HEAD
  
  xbee.println(' ');
=======

  Serial1.println(' ');
#endif
>>>>>>> f9bd6273ba1e81452e67c473eb411c01bfdce94b

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
