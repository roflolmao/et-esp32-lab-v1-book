#define relay1 16
#define switch1 17
bool status = false;
void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(switch1, INPUT);
}
void loop() {
  if(digitalRead(switch1) == LOW){
    status = !status;
    delay(300);
  }
  if(status){
    digitalWrite(relay1, HIGH);
  }else{
    digitalWrite(relay1, LOW);
  }
}
