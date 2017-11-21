void setDeviceLocationReference() {
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
    printAttitude(DeviceIMU.ax, DeviceIMU.ay, DeviceIMU.az, 
                 -DeviceIMU.my, -DeviceIMU.mx, DeviceIMU.mz);              
}


void printAttitude(float ax, float ay, float az, float mx, float my, float mz)
{
  float roll = atan2(ay, az);
  float pitch = atan2(-ax, sqrt(ay * ay + az * az));
  
  float heading;
  if (my == 0)
    heading = (mx < 0) ? PI : 0;
  else
    heading = atan2(mx, my);
    
  heading -= DECLINATION * PI / 180;
  
  if (heading > PI) heading -= (2 * PI);
  else if (heading < -PI) heading += (2 * PI);
  else if (heading < 0) heading += 2 * PI;
  
  // Convert everything from radians to degrees:
  heading *= 180.0 / PI;
  pitch *= 180.0 / PI;
  roll  *= 180.0 / PI;

  // Good chance this is all wrong. 
// IMU X DIRECTION
  if (DeviceIMU.ax * 0.05 <= 0.05){
    telemetry[teleIMUx] = 0;
  }
  else {
    telemetry[teleIMUx] = DeviceIMU.ax * 0.05*cos(roll)*9.81;
  }

// IMU Y DIRECTION
  if (myIMU.ax * 0.05 <= 0.05){
    telemetry[teleIMUy] = 0;
  }
  else {
    telemetry[teleIMUy] = DeviceIMU.ay * 0.05*cos(pitch)*9.81;
  }
  
// IMU Z DIRECTION
  if (DeviceIMU.ax * 0.05 <= 0.05){
    telemetry[teleIMUz] = 0;
  }
  else {
    telemetry[teleIMUz] = DeviceIMU.az *0.05;
  }

}
