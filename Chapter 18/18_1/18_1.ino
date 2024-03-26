#include <PCF8574.h>
PCF8574 pcf8574(0x20);
int LEDs[] = {P0, P1, P2, P3};
int buttons[] = {P4, P5, P6, P7};
int i;
int pushedButton = 0;
void setup() 
{
  for(i = 0; i < 4; i ++){
    pcf8574.pinMode(LEDs[i], OUTPUT);
  }
  for(i = 0; i < 4; i ++){
    pcf8574.pinMode(buttons[i], INPUT);
  }
  pcf8574.begin();
}
void loop(){
  for(i = 0; i < 4; i ++){
    if(!pcf8574.digitalRead(buttons[i])){
      pushedButton = i;
      break;
    }
  }
  for(i = 0; i < 4; i ++){
    if(i == pushedButton){
      pcf8574.digitalWrite(LEDs[i], LOW);
    }else{
      pcf8574.digitalWrite(LEDs[i], HIGH);
    }
  }
  delay(100);
}