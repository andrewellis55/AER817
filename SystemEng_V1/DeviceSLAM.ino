void updateDeviceLocation() {

// Read IMU Values
  DeviceIMU.readGyro();
  DeviceIMU.readAccel();
  DeviceIMU.readMag();

  float roll = atan2(DeviceIMU.ay, DeviceIMU.az);
  float pitch = atan2(-DeviceIMU.ax, sqrt(DeviceIMU.ay * DeviceIMU.ay + DeviceIMU.az * DeviceIMU.az));
  
  float heading;
  if (-DeviceIMU.my == 0)
    heading = (-DeviceIMU.mx < 0) ? PI : 0;
  else
    heading = atan2(-DeviceIMU.mx, -DeviceIMU.my);
    
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
