//Libraries


//Debug State Function
#ifdef DEBUG
#define Debug(x); Serial.println(x);
#else
#define Debug(x); 
#endif

//Global Variable Declarations
int delayTime;
int dataSize = 5;

//Telemetry packet
#define teleCount 0
#define teleButton 1
#define teleIMUx 2
#define teleIMUy 3
#define teleIMUz 4
float telemetry[dataSize];

void setup() {
  // put your setup code here, to run once:
  initGlobalVariables();
  initIMU();
  setLocationReference();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  updateLocation();
  checkPanicButton();
  getRadioData();
  sendRadioData();
  timeDelay();

  telemetry[teleCount] = telemetry[teleCount] + 1; //increment the packet counter
  
}
















