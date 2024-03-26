#include <ESP32Servo.h>
#define servo 2 
#define button_b 17
Servo servo1; 
int position = 180;
int stage = 1;
bool rotate = true;
void setup() 
{         
  pinMode(button_b, INPUT);
  servo1.attach(servo);
}
void loop() 
 {
  if(digitalRead(button_b) == LOW){
    rotate = !rotate;
    delay(300);
  }
  if(rotate){
    if(stage == 1 && position < 180){
      servo1.write(position);
      position++;
      delay(5);
    }else if(stage == 2 && position > 0){
      servo1.write(position);
      position--;
      delay(5);
    }
  }
  if(position == 180){
    stage = 2;
  }else if(position == 0){
    stage = 1;
  }
  if(position == 90){
    delay(500);
  }
 }
