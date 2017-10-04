//Libraries


//Debug State Function
#ifdef DEBUG
#define Debug(x); Serial.println(x);
#else
#define Debug(x); 
#endif

//Global Variable Declarations
int delayTime;


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

  
}
















