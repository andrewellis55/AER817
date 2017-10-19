//Used to test ground software with random but proper telemetery
#include <Servo.h>
//Telemertery data, They are just random
unsigned int TeamID = 1086; //1. Done
String Glider = "GLIDER"; // 2
unsigned long timer = 0;//3.
unsigned long timer2 = timer;//3.
unsigned long packetID = 0; // 4
float altitude = 110;//5 
float pressure = 101; //6
float pitot_speed = 22.22;//7
float temp = 19.20;//8.
float voltage = 7.5;//9.
float heading = 25; //10
float state = 5; //11
float bonus = 1; //12
float deploy = 0;
//Servo servo1;
void setup() {
  //servo1.attach(8);
  Serial.begin (19200);
}

int counter = 0;

void loop() {
counter = counter +1;
  String test;

  ++packetID;
  if (counter < 11){
  Transmit_data2();
  } else {
    Transmit_data();
  }
  if(Serial.available() > 0){
    test= Serial.readString();
    Serial.println(test);
    packetID = test.toInt();
    }
  //servo1.write(ServoPos);

  delay (1000);

}


void Transmit_data (){
    ++timer;
  String toradio = "";
  toradio += TeamID;
  toradio += ",";
  toradio += Glider;
  toradio += ",";
  toradio += timer;
  toradio += ",";
  toradio += packetID;
  toradio += ",";
  toradio += altitude;
  toradio += ",";
  toradio += pressure;
  toradio += ",";
  toradio += pitot_speed;
  toradio += ",";
  toradio += temp;
  toradio += ",";
  toradio += voltage;
  toradio += ",";
  toradio += heading;
  toradio += ",";
  toradio += state;
  toradio += ",";
  toradio += bonus;
  Serial.println (toradio);


  
}

void Transmit_data2 (){
    ++timer2;
    if (timer2 == 10) {
      deploy =1;
    }
  String toradio = "";
  toradio += TeamID;
  toradio += ",";
  toradio += "CONTAINER";
  toradio += ",";
  toradio += timer2;
  toradio += ",";
  toradio += packetID;
  toradio += ",";
  toradio += altitude;
  toradio += ",";
  toradio += pressure;
  toradio += ",";
  toradio += pitot_speed;
  toradio += ",";
  toradio += temp;
  toradio += ",";
  toradio += deploy;
  toradio += ",";
  toradio += heading;
  toradio += ",";
  toradio += state;
  toradio += ",";
  toradio += bonus;
  Serial.println (toradio);


  
}
