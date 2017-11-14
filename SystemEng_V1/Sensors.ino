void initIMU(){
  //initialization code for IMU
    Wire.begin();

    // Calibrate gyro and accelerometers, load biases in bias registers
    myIMU.calibrateMPU9250(myIMU.gyroBias, myIMU.accelBias);

    myIMU.initMPU9250();
    // Initialize device for active mode read of acclerometer, gyroscope, and
    // temperature

    // Get magnetometer calibration from AK8963 ROM
    myIMU.initAK8963(myIMU.factoryMagCalibration);
    // Initialize device for active mode read of magnetometer

    // Get sensor resolutions, only need to do this once
    myIMU.getAres();
    myIMU.getGres();
    myIMU.getMres();

    // The next call delays for 4 seconds, and then records about 15 seconds of
    // data to calculate bias and scale.
    myIMU.magCalMPU9250(myIMU.magBias, myIMU.magScale);
    delay(2000); // Add delay to see results before serial spew of data
}

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
  telemetry[teleGPSLat] = 0;
  telemetry[teleGPSLong] = 0;
  telemetry[teleGPSAlt] = 1;
}

void getBMPData(){
  telemetry[teleBMPAlt] = 0;
}
