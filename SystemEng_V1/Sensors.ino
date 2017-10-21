void initIMU(){
  //initialization code for IMU
}


void checkPanicButton(){
  //Checks if panic button has been pressed
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH){
    telemetry[teleButton] = 0;
  }
  else if (buttonState == LOW){
    telemetry[teleButton] = 1;
  }
}
