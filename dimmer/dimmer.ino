int zerocrossing_sensor = 7;
int trigger = 6;
//potentiometer pin
int pino_potent = A0;
//potentiometer value
int potent = 0;
void setup(){
  pinMode(zerocrossing_sensor, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
  digitalWrite(trigger, HIGH);
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

