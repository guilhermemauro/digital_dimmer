//*********************************
//Firmware created by Guilherme Mauro
// guilherme.oferraz@yahoo.com.br
//*********************************

int zerocrossing_sensor = 3;
int trigger = 4;
//potentiometer pin
int pino_potent = A1;
//potentiometer value
int potent = 0;
void setup(){
  pinMode(zerocrossing_sensor, INPUT);
  pinMode(trigger, OUTPUT);
  //pinMode(pino_potent,INPUT);
  digitalWrite(trigger, LOW);
}
void loop(){
  //wait for passage of zerocrossing
  if(digitalRead(zerocrossing_sensor) != 0){
    potent = analogRead(pino_potent);
    potent =  map(potent, 0, 1023, 0, 111);
    //expected time to turn on the MOC3021
    delayMicroseconds(65*potent);
    digitalWrite(trigger, HIGH);
    //expected time to turn off the MOC3021
    delayMicroseconds(50);
    digitalWrite(trigger, LOW);
  }
}


