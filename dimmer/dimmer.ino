int zerocrossing_sensor = 7;
int trigger = 6;
void setup(){
  pinMode(zerocrossing_sensor, INPUT);
  pinMode(trigger, OUTPUT);
}
void loop(){
  while(digitalRead(zerocrossing_sensor) != 0){}
  
  
}

