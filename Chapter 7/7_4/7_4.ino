#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
int btn[] = {26, 27, 32, 33, 34, 35, 36, 39};
int i; 
Adafruit_SH1106 display(SDA, SCL);
void setup(){
  for(i = 0; i < 8; i++){
    pinMode(btn[i], INPUT);
  }
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  Wire.begin();
  display.println("Ready!");
  delay(1000);
}
void loop(){
  for(i = 0; i < 8; i++){
    if(digitalRead(btn[i]) == LOW){
      display.clearDisplay();
      display.setCursor(0,25);
      display.print("You pressed button ");
      display.print(i);
      display.display(); 
      break;
    }
  }
}
