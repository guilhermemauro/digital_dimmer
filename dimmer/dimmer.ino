int zerocrossing_sensor = 7;
int trigger = 6;
void setup(){
  pinMode(zerocrossing_sensor, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
  digitalWrite(trigger, HIGH);
}
void loop(){
  //wait for passage of zerocrossing
  if(digitalRead(zerocrossing_sensor) != 0){
  //expected time to turn on the MOC3021
  delayMicroseconds(65*110);
  digitalWrite(trigger, HIGH);
  //expected time to turn off the MOC3021
  delayMicroseconds(50);
  digitalWrite(trigger, LOW);
  }
}

