

void initAK() {
  Wire.begin();
  if (movementSensor.begin() == false) {
#ifdef DEBUG
    Serial.println("Device not found. Check wiring.");
#endif
  }
}

void getAKData() {

  if (movementSensor.available())
  {
    telemetry[teleHPBack] = movementSensor.getIR1(); //Lower
    telemetry[teleHPLeft] = movementSensor.getIR2(); //Left
    telemetry[teleHPFront] = movementSensor.getIR3(); //Upper
    telemetry[teleHPRight] = movementSensor.getIR4(); //Right


    movementSensor.refresh();


  }

}


