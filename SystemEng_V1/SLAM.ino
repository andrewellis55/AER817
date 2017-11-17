void setLocationReference() {
  //Sets the current location to (0,0,0)

}

void updateLocation() {
  //

  //Gets first acceleration data from IMU
  if (myIMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01)
  {
    myIMU.readAccelData(myIMU.accelCount);  // Read the x/y/z adc values
    myIMU.ax = (float)myIMU.accelCount[0] * myIMU.aRes * g; // - myIMU.accelBias[0];
    myIMU.ay = (float)myIMU.accelCount[1] * myIMU.aRes * g; // - myIMU.accelBias[1];
    myIMU.az = (float)myIMU.accelCount[2] * myIMU.aRes * g - g; // - myIMU.accelBias[2];
  }

  imuTimeDelay(); // delays 100 ms

  //  //Gets second reading of acceleration form IMU
  //  if (myIMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01)
  //  {
  //    myIMU.readAccelData(myIMU.accelCount);  // Read the x/y/z adc values
  //    myIMU2.ax = (float)myIMU.accelCount[0] * myIMU.aRes * g; // - myIMU.accelBias[0];
  //    myIMU2.ay = (float)myIMU.accelCount[1] * myIMU.aRes * g; // - myIMU.accelBias[1];
  //    myIMU2.az = (float)myIMU.accelCount[2] * myIMU.aRes * g - g; // - myIMU.accelBias[2];
  //  }

#ifdef DEBUG_IMU //Outputs raw acceleration data
  telemetry[teleIMUx] = myIMU.ax;
  telemetry[teleIMUy] = myIMU.ay;
  telemetry[teleIMUz] = myIMU.az;

#else //Outputs "distance" values from acceleration data
// IMU X DIRECTION
  if (myIMU.ax * 0.05 <= 0.05){
    telemetry[teleIMUx] = 0;
  }
  else {
    telemetry[teleIMUx] = myIMU.ax * 0.05;
  }

// IMU Y DIRECTION
  if (myIMU.ax * 0.05 <= 0.05){
    telemetry[teleIMUy] = 0;
  }
  else {
    telemetry[teleIMUy] = myIMU.ay * 0.05;
  }
  
// IMU Z DIRECTION
  if (myIMU.ax * 0.05 <= 0.05){
    telemetry[teleIMUz] = 0;
  }
  else {
    telemetry[teleIMUz] = myIMU.az * 0.05;
  }
#endif

}

