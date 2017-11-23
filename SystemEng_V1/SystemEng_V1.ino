//Libraries

#include "quaternionFilters.h"
#include "MPU9250.h"

#include "SparkFun_AK9750_Arduino_Library.h"
#include <SoftwareSerial.h>


//DeviceIMU
#include <Wire.h>
#include <SPI.h>
#include <SparkFunLSM9DS1.h>
#define LSM9DS1_M  0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG  0x6B // Would be 0x6A if SDO_AG is LOW

//#define DEBUG
#define DEBUG_IMU 7
#define PAYLOAD
 
//Global Variable Declarations
int delayTime;
int buttonPin;
int buttonState;
int DeviceID = 1234;



typedef struct {
  float gx;
  float gy;
  float gz;

  float ax;
  float ay;
  float az;

  float pitch;
  float yaw;
  float roll;

} inertialData;


float g;
MPU9250 myIMU;
LSM9DS1 DeviceIMU;

AK9750 movementSensor; //Hook object to the library

long teleTime;

SoftwareSerial xbee(4, 3); // RX, TX
  
//Telemetry packet
#ifdef DEVICE
  #define teleDeviceID 0
  #define teleDevice 1
  #define teleCount 2
  #define teleButton 3
  #define teleBMPAlt 4
  #define teleIMUx 5
  #define teleIMUy 6
  #define teleIMUz 7
  #define teleGPSLat 8
  #define teleGPSLong 9
  #define teleGPSAlt 10
  #define teleSize 11
  float telemetry[11];
#endif

#ifdef PAYLOAD
  #define teleDeviceID 0
  #define teleDevice 1
  #define teleCount 2
  #define teleBMPAlt 3
  #define teleIMUx 4
  #define teleIMUy 5
  #define teleIMUz 6
  #define teleGPSLat 7
  #define teleGPSLong 8
  #define teleGPSAlt 9
  #define teleHPFront 10
  #define teleHPRight 11
  #define teleHPLeft 12
  #define teleHPBack 13
  #define teleSize 14
  #define teleButton 0 
  float telemetry[14];
#endif

void setup() {
  
  //Serial1.begin(9600);

  //Debug State Function

Serial.begin(9600);

xbee.begin(9600);
 
  #ifdef DEVICE
    telemetry[teleDevice] = 2;
  #endif
  #ifdef PAYLOAD
    telemetry[teleDevice] = 1;
    initAK();
    setupIMU();
  #endif

  telemetry[teleDeviceID] = DeviceID;
//  telemetry[teleDevice] = teleDevice;
  telemetry[teleCount] = 1;
  
  // put your setup code here, to run once:u
  initGlobalVariables();
  pinMode(buttonPin, INPUT);
  //initPayloadIMU();
  setLocationReference();

  teleTime = millis();
   slam();
}

void loop() {

  if (millis() - teleTime < 1000){
    slam();
  } else {

 
  
  #ifdef DEVICE
    checkPanicButton();
    getDeivceBMPData();
    getDeviceIMUDATA();
  #endif


  #ifdef PAYLOAD
  getAKData();
  //getPayloadIMUDATA();
  #endif

  
  getGPSData();
  getBMPData();
  sendRadioData();
  teleTime = millis();

  telemetry[teleCount] = telemetry[teleCount] + 1; //increment the packet counter
  }
}















