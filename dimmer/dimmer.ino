//*********************************
//Firmware created by Guilherme Mauro
// guilherme.oferraz@yahoo.com.br
//*********************************
#include "TinyWireS.h"                  // wrapper class for I2C slave routines

#define I2C_SLAVE_ADDR  0x26            // i2c slave address (38)
// physical pin 6 in Attiny85
int zerocrossing_sensor = 1;
//physical pin 3 in Attiny85
int trigger = 4;
//potentiometer pin (pyshical pin 2 in Attiny85)
int pino_potent = 3;
//potentiometer value
int potent = 0;
//byte value received by i2c
byte value = 0;
//pin to choose the work mode between potentiometer or i2c (physical pin 7)
int pinSwitch =  2;
void setup(){
  pinMode(zerocrossing_sensor, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(pino_potent,INPUT);
  digitalWrite(trigger, LOW);
  TinyWireS.begin(I2C_SLAVE_ADDR);
}
void loop(){
  //wait for passage of zerocrossing
  if(digitalRead(zerocrossing_sensor) != 0){
     if(digitalRead(pinSwitch) == LOW){
      potent = analogRead(pino_potent);
      potent =  map(potent, 0, 1023, 114, 5);
     }
     if(TinyWireS.available()){
      value = TinyWireS.receive();
      potent = map(value, 0, 255, 114, 5);
      value += 10;
      TinyWireS.send(value);
     }
    //expected time to turn on the MOC3021
    delayMicroseconds(65*potent);
    digitalWrite(trigger, HIGH);
    //expected time to turn off the MOC3021
    delayMicroseconds(50);
    digitalWrite(trigger, LOW);
  }
}


