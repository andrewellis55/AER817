//Libraries

#define DEBUG

#define PAYLOAD

//Global Variable Declarations
int delayTime;
int buttonPin;
int buttonState;
int DeviceID = 1234;

//Telemetry packet
#ifdef PERSON
  #define teleDeviceID 0
  #define teleDevice 1
  #define teleCount 2
  #define teleButton 3
  #define teleBMPAlt 4
  #define teleIMULat 5
  #define teleIMULong 6
  #define teleIMUAlt 7
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
  #define teleButton 3
  #define teleBMPAlt 4
  #define teleIMULat 5
  #define teleIMULong 6
  #define teleIMUAlt 7
  #define teleGPSLat 8
  #define teleGPSLong 9
  #define teleGPSAlt 10
  #define teleHPFront 11
  #define teleHPRight 12
  #define teleHPLeft 13
  #define teleHPBack 14
  #define teleSize 15
  float telemetry[15];
#endif

void setup() {
  
  Serial1.begin(9600);

  //Debug State Function
  #ifdef DEBUG
    Serial.begin(9600);
  #endif

  #ifdef PERSON
    teleDevice == "PERSON";
  #endif
   #ifdef PAYLOAD
    teleDevice == "PAYLOAD";
  #endif

  telemetry[teleDeviceID] = DeviceID;
  telemetry[teleDevice] = teleDevice;

  MPU9250 myIMU;
  
  // put your setup code here, to run once:
  initGlobalVariables();
  pinMode(buttonPin, INPUT);
  initIMU();
  setLocationReference();
}

void loop() {
  // put your main code here, to run repeatedly:

  updateLocation();
  checkPanicButton();
//  getRadioData();
  getGPSData();
  getBMPData();
  sendRadioData();
  timeDelay();

  telemetry[teleCount] = telemetry[teleCount] + 1; //increment the packet counter

}














