void setLocationReference() {
  //Sets the current location to (0,0,0)

}

void updateDeviceLocation() {
// Read IMU Values
if (DeviceIMU.gyroAvailable())
{
  DeviceIMU.readGyro();
}

if (DeviceIMU.accelAvailable())
{
  DeviceIMU.readAccel();
}

if (DeviceIMU.magAvailable())
{
  DeviceIMU.readMag();
}
  

// Obtain Roll Pitch Yaw of device.
  float roll = atan2(DeviceIMU.ay, DeviceIMU.az);
  float pitch = atan2(-DeviceIMU.ax, sqrt(DeviceIMU.ay * DeviceIMU.ay + DeviceIMU.az * DeviceIMU.az));
  
  float heading;
  if (-DeviceIMU.mx == 0)
    heading = (-DeviceIMU.mx < 0) ? PI : 0;
  else
    heading = atan2(-DeviceIMU.my, -DeviceIMU.mx);
    
  heading -= DECLINATION * PI / 180;
  
  if (heading > PI) heading -= (2 * PI);
  else if (heading < -PI) heading += (2 * PI);
  else if (heading < 0) heading += 2 * PI;
  
  // Convert everything from radians to degrees:
  heading *= 180.0 / PI;
  pitch *= 180.0 / PI;
  roll  *= 180.0 / PI;


  telemetry[teleIMUx] = roll;
  telemetry[teleIMUy] = pitch;
  telemetry[teleIMUz] = heading;
}
