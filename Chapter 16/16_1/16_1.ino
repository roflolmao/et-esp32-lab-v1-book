#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
String words = "Hello World! \nWe are ETT!!";
Adafruit_SH1106 display(SDA, SCL);
void setup(){
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);    
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(words);
  display.drawRect(10, 50, 100, 10, WHITE);
  display.fillRect(12, 52, 96, 6, WHITE);
  display.display();
}
void loop(){}
