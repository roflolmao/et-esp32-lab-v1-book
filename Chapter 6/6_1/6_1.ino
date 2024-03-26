#include <ESP32Servo.h>
#include <RCWL_1X05.h>
#define servo 2 
Servo servo1; 
RCWL_1X05 ultrasonic1;
int position = 90;
void setup() 
{         
  Wire.begin();
  ultrasonic1.begin();
  ultrasonic1.setFilter(true);
  ultrasonic1.setTimeout(50);
  ultrasonic1.setMode(RCWL_1X05::continuous);  
  servo1.attach(servo);
  servo1.write(90);
}
void loop() 
{
  float cm ; 
  bool data ;
  data = ultrasonic1.update();
  if(data)
  {
    cm = ultrasonic1.read();
    cm = cm/10; 
    if(cm < 30){
      servo1.write(0);
    }else{
      servo1.write(180);
    }
  }
}
