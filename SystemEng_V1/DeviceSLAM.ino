void updateDeviceLocation() {

  telemetry[teleIMUx] = DeviceIMU.ax;
  telemetry[teleIMUy] = DeviceIMU.ay;
  telemetry[teleIMUz] = DeviceIMU.az;
  telemetry[teleMAGx] = DeviceIMU.mx;
  telemetry[teleMAGy] = DeviceIMU.my;
  telemetry[teleMAGz] = DeviceIMU.mz;


}

