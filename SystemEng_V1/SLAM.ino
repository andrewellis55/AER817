void setLocationReference(){
  //Sets the current location to (0,0,0)
}

void updateLocation(){
  //Updates location based on IMU data using SLAM algorythem
   if (myIMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01)
    {
      myIMU.readAccelData(myIMU.accelCount);  // Read the x/y/z adc values
  
//      Now we'll calculate the accleration value into actual g's
//      This depends on scale being set
//      myIMU.ax = (float)myIMU.accelCount[0] * myIMU.aRes; // - myIMU.accelBias[0];
//      myIMU.ay = (float)myIMU.accelCount[1] * myIMU.aRes; // - myIMU.accelBias[1];
//      myIMU.az = (float)myIMU.accelCount[2] * myIMU.aRes; // - myIMU.accelBias[2];
     } 
  
    telemetry[teleIMULat] = (float)myIMU.accelCount[0];
    telemetry[teleIMULong] = (float)myIMU.accelCount[1];
    telemetry[teleIMUAlt] = (float)myIMU.accelCount[2];

}
