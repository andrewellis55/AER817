//void setLocationReference() {
//  //Sets the current location to (0,0,0)
//
//}
//
//void updateDeviceLocation() {
//  //
//
//  //Gets first acceleration data from IMU
//  if (myIMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01)
//  {
//    myIMU.readAccelData(myIMU.accelCount);  // Read the x/y/z adc values
//    myIMU.ax = (float)myIMU.accelCount[0] * myIMU.aRes * g; // - myIMU.accelBias[0];
//    myIMU.ay = (float)myIMU.accelCount[1] * myIMU.aRes * g; // - myIMU.accelBias[1];
//    myIMU.az = (float)myIMU.accelCount[2] * myIMU.aRes * g - g; // - myIMU.accelBias[2];
//  
//
//  // Gets magnometer data
//    myIMU.readMagData(myIMU.magCount);  // Read the x/y/z adc values
//    myIMU.mx = (float)myIMU.magCount[0] * myIMU.mRes
//               * myIMU.factoryMagCalibration[0] - myIMU.magBias[0];
//    myIMU.my = (float)myIMU.magCount[1] * myIMU.mRes
//               * myIMU.factoryMagCalibration[1] - myIMU.magBias[1];
//    myIMU.mz = (float)myIMU.magCount[2] * myIMU.mRes
//               * myIMU.factoryMagCalibration[2] - myIMU.magBias[2];
//  }
//  
////  imuTimeDelay(); // delays 100 ms
//

