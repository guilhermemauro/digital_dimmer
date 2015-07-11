int zerocrossing_sensor = 7;
int trigger = 6;
int tempo = 0;
int trash;
void setup(){
  pinMode(zerocrossing_sensor, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  //wait for passage of zero crossing
  if(digitalRead(zerocrossing_sensor) == 0){}
  trash = millis() - tempo;
  tempo = millis();
  Serial.println(trash);
  delayMicroseconds(100);
}

