

void checkPanicButton(){
  //Checks if panic button has been pressed
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH){
    telemetry[teleButton] = 0;
  }
  else if (buttonState == LOW){
    telemetry[teleButton] = 1;
  }
}

void getGPSData(){
  telemetry[teleGPSLat] = 9999;
  telemetry[teleGPSLong] = 9999;
  telemetry[teleGPSAlt] = 9999;
}

void getBMPData(){
  telemetry[teleBMPAlt] = 9999;
}

void initDeviceIMU(){
  // Before initializing the IMU, there are a few settings
  // we may need to adjust. Use the settings struct to set
  // the device's communication mode and addresses:
  DeviceIMU.settings.device.commInterface = IMU_MODE_I2C;
  DeviceIMU.settings.device.mAddress = LSM9DS1_M;
  DeviceIMU.settings.device.agAddress = LSM9DS1_AG;
  DeviceIMU.begin();
}

