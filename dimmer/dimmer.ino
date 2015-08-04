//*********************************
//Firmware created by Guilherme Mauro
// guilherme.oferraz@yahoo.com.br
//*********************************

// physical pin 6 in Attiny85
int zerocrossing_sensor = 1;
//physical pin 3 in Attiny85
int trigger = 4;
//potentiometer pin (pyshical pin 2 in Attiny85)
int pino_potent = 3;
//potentiometer value
int potent = 0;
void setup(){
  pinMode(zerocrossing_sensor, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(pino_potent,INPUT);
  digitalWrite(trigger, LOW);
}
void loop(){

  //wait for passage of zerocrossing
  if(digitalRead(zerocrossing_sensor) != 0){
    potent = analogRead(pino_potent);
    potent =  map(potent, 0, 1023, 114, 5);
    //expected time to turn on the MOC3021
    delayMicroseconds(65*potent);
    digitalWrite(trigger, HIGH);
    //expected time to turn off the MOC3021
    delayMicroseconds(50);
    digitalWrite(trigger, LOW);
  }
}


