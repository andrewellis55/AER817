

void initDeviceBMP(){
  DeviceBMP.begin();
  baseAlt = DeviceBMP.readAltitude(1012);
}

void checkPanicButton() {
  //Checks if panic button has been pressed
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    telemetry[teleButton] = 0;
  }
  else if (buttonState == LOW) {
    telemetry[teleButton] = 1;
  }
}

void getGPSData() {
  telemetry[teleGPSLat] = 9999;
  telemetry[teleGPSLong] = 9999;
  telemetry[teleGPSAlt] = 9999;
}

void getBMPData() {
  telemetry[teleIMUz] = DeviceBMP.readAltitude(1012) - baseAlt;
  telemetry[teleBMPAlt] = DeviceBMP.readAltitude(1012) - baseAlt;
}


