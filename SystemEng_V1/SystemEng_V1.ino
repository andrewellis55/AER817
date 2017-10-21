//Libraries

#define DEBUG

//Global Variable Declarations
int delayTime;
int buttonPin;
int buttonState;

//Telemetry packet
#define teleCount 0
#define teleButton 1
#define teleIMUx 2
#define teleIMUy 3
#define teleIMUz 4
float telemetry[5];

void setup() {

  Serial1.begin(9600);

  //Debug State Function
  #ifdef DEBUG
    Serial.begin(9600);
  #endif

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
  getRadioData();
  sendRadioData();
  timeDelay();

  telemetry[teleCount] = telemetry[teleCount] + 1; //increment the packet counter

}















