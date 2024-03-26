nt LEDs[] = {0, 2, 12, 15, 5, 18, 19, 23};
int i;
int counter = 0;
void setup() {
  for(i = 0; i < 8; i ++){
    pinMode(LEDs[i], OUTPUT);
  }
}
void loop() {
  for(i = 0; i < 8; i ++){
    if(i == counter){
      digitalWrite(LEDs[i], LOW);
    } else {
      digitalWrite(LEDs[i], HIGH);
    }
  }
  counter++;
  if(counter == 8){
    counter = 0;
  }
  delay(500);
}
