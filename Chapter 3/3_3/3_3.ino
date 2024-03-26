int LEDs[] = {0, 2, 12, 15, 5, 18, 19, 23};
int i;
int front = 0;
int rear = 7;
void setup() {
  for(i = 0; i < 8; i ++){
    pinMode(LEDs[i], OUTPUT);
  }
}
void loop() {
  for(i = 0; i < 8; i++){
    if(i == front || i == rear){
      digitalWrite(LEDs[i], LOW);
    }else{
      digitalWrite(LEDs[i], HIGH);
    }
  }
  front++;
  rear--;
  if(front == 4){
    front = 0;
  }
  if(rear == 3){
    rear = 7;
  }
  delay(500);
}
