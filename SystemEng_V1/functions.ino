void initGlobalVariables() {
  //keeps global variable initializations in one place
  delayTime = 1000; //milliseconds
  g = 9.81; // m/s/s
}

void timeDelay() {
  //Delay time so that data transmission only occurs once per second
  unsigned long currentTime = millis();
  while (millis() - currentTime < 1000) {}
}

void imuTimeDelay() {
  //Delay time so that data transmission only occurs once per second
  unsigned long currentTime = millis();
  while (millis() - currentTime < 100) {}
}



