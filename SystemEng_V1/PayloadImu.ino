
#include "quaternionFilters.h"
#include "MPU9250.h"

#define SerialDebug false

#define mintimeInt 0.01

#define Kp 2.0f * 5.0f
#define Ki 0.0f

float filX;
float filY;
float filZ;

float vx = 0;
float vy = 0;
float vz = 0;

float dx = 0;
float dy = 0;
float dz = 0;

  long startTime;

  long zeroDelay;
  boolean zeroed = false;
  


void setupIMU() {

 inertialData ID;


  #ifdef DEVICE
  initDeviceIMU();
  getDeviceIMUData(&ID);
  #endif

  #ifdef PAYLOAD
  initPayloadIMU();
  getPayloadIMUData(&ID);
  #endif

  filX = 0;//ID.ax;
  filY = 0;//ID.ay;
  filZ = ID.az;
  
  startTime = micros();
  zeroDelay = millis();

}



void hpFilter(inertialData *ID){
  float EMA_a = 0.08;
  
  filX = (EMA_a * ID->ax) + ((1-EMA_a)*filX);  //run the EMA
  ID->ax = ID->ax - filX;                   //calculate the high-pass signal

  filY = (EMA_a * ID->ay) + ((1-EMA_a)*filY);
  ID->ay = ID->ay - filY;

  filZ = (EMA_a * ID->az) + ((1-EMA_a)*filZ); 
  ID->az = ID->az - filZ;  

  
}


void slam(){
  
  startTime = micros();
  inertialData ID;
  #ifdef PAYLOAD
  getPayloadIMUData(&ID);
  #endif

  #ifdef DEVICE
  getDeviceIMUData(&ID);
  #endif 
  
  hpFilter(&ID);
 
  while (micros() - startTime < mintimeInt * 1000000){
  }
  
  float timeInt = (micros() - startTime) / 1000000.0;

  vx = vx + ID.ax * timeInt;
  vy = vy + ID.ay * timeInt;
  vz = vz + ID.az * timeInt;

  dx = dx + vx * timeInt + 0.5 * ID.ax * pow(timeInt, 2);
  dy = dy + vy * timeInt + 0.5 * ID.ay * pow(timeInt, 2);
  dz = dz + vz * timeInt + 0.5 * ID.az * pow(timeInt, 2);

  if (millis() - zeroDelay > 2000 && zeroed == false){
    zeroed = true;
    vx= 0;
    vy = 0;
    vz = 0;

    dx = 0;
    dy = 0;
    dz = 0;

    filX = 0;
    filY = 0;
    filZ = 0;
    
  }





    telemetry[teleIMUx] = dx;
    telemetry[teleIMUy] = dy;
    //telemetry[teleIMUz] = 0;


  #ifdef DEBUG_IMU
  Serial.print(dx);
  Serial.print(",");
  Serial.println(dy);

//Serial.println(timeInt);
  #endif

 // printAccel(ID);
  
trimVal(ID.ax);
trimVal(ID.ay);
trimVal(ID.az);
  
 
}


void printAccel(inertialData ID){
  Serial.print(ID.ax);
  Serial.print(",");
  Serial.print(ID.ay);
  Serial.print(",");
  Serial.print(ID.az);


  //Serial.println(sqrt(pow(ID.ax, 2) + pow(ID.ay, 2) +pow(ID.az, 2)));


  
}




float trimVal(float val){
  

  if (abs(val) < 0.1){
    return 0;
  } else {
    return val;
  }
  
}

void initPayloadIMU(){
   //initialization code for IMU
  Wire.begin();

// Start by performing self test and reporting values
  //myIMU.MPU9250SelfTest(myIMU.selfTest);

  // Calibrate gyro and accelerometers, load biases in bias registers
  myIMU.calibrateMPU9250(myIMU.gyroBias, myIMU.accelBias);
  myIMU.initMPU9250();

  // Get magnetometer calibration from AK8963 ROM
  myIMU.initAK8963(myIMU.factoryMagCalibration);
  
  // Get sensor resolutions, only need to do this once
  myIMU.getAres();
  myIMU.getGres();
  myIMU.getMres();

  // Calibrates magnometer
  //myIMU.magCalMPU9250(myIMU.magBias, myIMU.magScale);
}





void getPayloadIMUData(inertialData *ID){
// If intPin goes high, all data registers have new data
  // On interrupt, check if data ready interrupt
  if (myIMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01){
    myIMU.readAccelData(myIMU.accelCount);  // Read the x/y/z adc values

    // Now we'll calculate the accleration value into actual g's
    // This depends on scale being set
    myIMU.ax = (float)myIMU.accelCount[0] * myIMU.aRes; // - myIMU.accelBias[0];
    myIMU.ay = (float)myIMU.accelCount[1] * myIMU.aRes; // - myIMU.accelBias[1];
    myIMU.az = (float)myIMU.accelCount[2] * myIMU.aRes; // - myIMU.accelBias[2];

    myIMU.readGyroData(myIMU.gyroCount);  // Read the x/y/z adc values

    // Calculate the gyro value into actual degrees per second
    // This depends on scale being set
    myIMU.gx = (float)myIMU.gyroCount[0] * myIMU.gRes;
    myIMU.gy = (float)myIMU.gyroCount[1] * myIMU.gRes;
    myIMU.gz = (float)myIMU.gyroCount[2] * myIMU.gRes;

    myIMU.readMagData(myIMU.magCount);  // Read the x/y/z adc values

    // Calculate the magnetometer values in milliGauss
    // Include factory calibration per data sheet and user environmental
    // corrections
    // Get actual magnetometer value, this depends on scale being set
    myIMU.mx = (float)myIMU.magCount[0] * myIMU.mRes
               * myIMU.factoryMagCalibration[0] - myIMU.magBias[0];
    myIMU.my = (float)myIMU.magCount[1] * myIMU.mRes
               * myIMU.factoryMagCalibration[1] - myIMU.magBias[1];
    myIMU.mz = (float)myIMU.magCount[2] * myIMU.mRes
               * myIMU.factoryMagCalibration[2] - myIMU.magBias[2];
  } // if (readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01)

  // Must be called before updating quaternions!
  myIMU.updateTime();

  // Sensors x (y)-axis of the accelerometer is aligned with the y (x)-axis of
  // the magnetometer; the magnetometer z-axis (+ down) is opposite to z-axis
  // (+ up) of accelerometer and gyro! We have to make some allowance for this
  // orientationmismatch in feeding the output to the quaternion filter. For the
  // MPU-9250, we have chosen a magnetic rotation that keeps the sensor forward
  // along the x-axis just like in the LSM9DS0 sensor. This rotation can be
  // modified to allow any convenient orientation convention. This is ok by
  // aircraft orientation standards! Pass gyro rate as rad/s
  MahonyQuaternionUpdate(myIMU.ax, myIMU.ay, myIMU.az, myIMU.gx * DEG_TO_RAD,
                         myIMU.gy * DEG_TO_RAD, myIMU.gz * DEG_TO_RAD, myIMU.my,
                         myIMU.mx, myIMU.mz, myIMU.deltat);

  






      myIMU.count = millis();


    // Serial print and/or display at 0.5 s rate independent of data rates
    myIMU.delt_t = millis() - myIMU.count;



// Define output variables from updated quaternion---these are Tait-Bryan
// angles, commonly used in aircraft orientation. In this coordinate system,
// the positive z-axis is down toward Earth. Yaw is the angle between Sensor
// x-axis and Earth magnetic North (or true North if corrected for local
// declination, looking down on the sensor positive yaw is counterclockwise.
// Pitch is angle between sensor x-axis and Earth ground plane, toward the
// Earth is positive, up toward the sky is negative. Roll is angle between
// sensor y-axis and Earth ground plane, y-axis up is positive roll. These
// arise from the definition of the homogeneous rotation matrix constructed
// from quaternions. Tait-Bryan angles as well as Euler angles are
// non-commutative; that is, the get the correct orientation the rotations
// must be applied in the correct order which for this configuration is yaw,
// pitch, and then roll.
// For more see
// http://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
// which has additional links.
      myIMU.yaw   = atan2(2.0f * (*(getQ()+1) * *(getQ()+2) + *getQ()
                    * *(getQ()+3)), *getQ() * *getQ() + *(getQ()+1)
                    * *(getQ()+1) - *(getQ()+2) * *(getQ()+2) - *(getQ()+3)
                    * *(getQ()+3));
      myIMU.pitch = -asin(2.0f * (*(getQ()+1) * *(getQ()+3) - *getQ()
                    * *(getQ()+2)));
      myIMU.roll  = atan2(2.0f * (*getQ() * *(getQ()+1) + *(getQ()+2)
                    * *(getQ()+3)), *getQ() * *getQ() - *(getQ()+1)
                    * *(getQ()+1) - *(getQ()+2) * *(getQ()+2) + *(getQ()+3)
                    * *(getQ()+3));
      myIMU.pitch *= RAD_TO_DEG;
      myIMU.yaw   *= RAD_TO_DEG;

      // Declination of SparkFun Electronics (40°05'26.6"N 105°11'05.9"W) is
      //   8° 30' E  ± 0° 21' (or 8.5°) on 2016-07-19
      // - http://www.ngdc.noaa.gov/geomag-web/#declination
      myIMU.yaw  -= 10.5;
      myIMU.roll *= RAD_TO_DEG;




      myIMU.count = millis();
      myIMU.sumCount = 0;
      myIMU.sum = 0;



        ID->gx =  myIMU.ax * 9.81;
        ID->gy =  myIMU.ay * 9.81;
        ID->gz =  myIMU.az * 9.81;

        ID->yaw = myIMU.yaw;
        ID->pitch = myIMU.pitch;
        ID->roll = myIMU.roll;

        float q[4];
        
        q[0] =  *getQ();
        q[1] =  *(getQ()+1);
        q[2] =  *(getQ()+2);
        q[3] =  *(getQ()+3);

        ID->ax = trimVal(9.81 * (myIMU.ax - (2 * (q[1] * q[3] - q[0] * q[2]))));
        ID->ay = trimVal(9.81 * (myIMU.ay - (2 * (q[0] * q[1] + q[2] * q[3]))));
        ID->az = trimVal(9.81 * (myIMU.az - (q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3])));


      
}




void initDeviceIMU(){
    imu.settings.device.commInterface = IMU_MODE_I2C;
  imu.settings.device.mAddress = LSM9DS1_M;
  imu.settings.device.agAddress = LSM9DS1_AG;

  if (imu.begin()){

  } else{
  
  }
}

void getDeviceIMUData(inertialData *ID){


if ( imu.gyroAvailable() )
  {
    // To read from the gyroscope,  first call the
    // readGyro() function. When it exits, it'll update the
    // gx, gy, and gz variables with the most current data.
    imu.readGyro();
  }
  if ( imu.accelAvailable() )
  {
    // To read from the accelerometer, first call the
    // readAccel() function. When it exits, it'll update the
    // ax, ay, and az variables with the most current data.
    imu.readAccel();
  }
  if ( imu.magAvailable() )
  {
    // To read from the magnetometer, first call the
    // readMag() function. When it exits, it'll update the
    // mx, my, and mz variables with the most current data.
    imu.readMag();
  }


float roll = atan2(imu.ay, imu.az);
  float pitch = atan2(-imu.ax, sqrt(imu.ay * imu.ay + imu.az * imu.az));
  
  float heading;
  if (-imu.my == 0)
    heading = (-imu.mx < 0) ? PI : 0;
  else
    heading = atan2(-imu.mx, -imu.my);
    
  heading -= DECLINATION * PI / 180;
  
  if (heading > PI) heading -= (2 * PI);
  else if (heading < -PI) heading += (2 * PI);
  else if (heading < 0) heading += 2 * PI;
  
  // Convert everything from radians to degrees:
  heading *= 180.0 / PI;
  pitch *= 180.0 / PI;
  roll  *= 180.0 / PI;
  



      float deltat = (micros()-startTime)/1000000.0;
  MahonyQuaternionUpdate(imu.ax, imu.ay, imu.az, imu.gx * DEG_TO_RAD, imu.gy * DEG_TO_RAD, imu.gz * DEG_TO_RAD, imu.mx, imu.my, imu.mz, deltat);
  
        float q[4];
        
        q[0] =  *getQ();
        q[1] =  *(getQ()+1);
        q[2] =  *(getQ()+2);
        q[3] =  *(getQ()+3);

  

  ID->gx = imu.calcAccel(imu.ax);
  ID->gy = imu.calcAccel(imu.ay);
  ID->gz = imu.calcAccel(imu.az);

  ID->pitch = pitch;
  ID->roll = roll;
  ID->yaw = heading;

        ID->ax = trimVal(9.81 * (imu.ax - (2 * (q[1] * q[3] - q[0] * q[2]))))/10000.0;
        ID->ay = trimVal(9.81 * (imu.ay - (2 * (q[0] * q[1] + q[2] * q[3]))))/10000.0;
        ID->az = trimVal(9.81 * (imu.az - (q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3])))/10000.0;

     

}

 
