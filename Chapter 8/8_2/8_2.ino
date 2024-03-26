#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
#define IR 15
IRrecv irRecv(IR);
decode_results results;
int channel = 0;
int i;
unsigned long keyCode ,last = millis();
unsigned long firstChannel = 0xFFE01F;
unsigned long lastChannel = 0xFF906F;
unsigned long plusChannel = 0xFF02FD;
unsigned long minusChannel = 0xFF9867;
unsigned long numberCodes[] = {
  0xFF6897,0xFF30CF,0xFF18E7,0xFF7A85,0xFF10EF, 
  0xFF38C7,0xFF5AA5,0xFF42BD,0xFF4AB5,0xFF52AD
};
Adafruit_SH1106 display(SDA, SCL);
void setup(){
  irRecv.enableIRIn();
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Current Channel : ");
  display.print(channel);
  display.display();
  Wire.begin();
}
void loop(){
  if(irRecv.decode(&results)){
     if(millis() - last > 250){
      keyCode = results.value;
      if(keyCode == firstChannel){
        channel = 0;
      }else if(keyCode == lastChannel){
        channel = 9;
      }else if(keyCode == plusChannel){
        channel += 1;
        if(channel > 9){
          channel = 0;
        }
      }else if(keyCode == minusChannel){
        channel -= 1;
        if(channel < 0){
          channel = 9;
        }
      }
      for(i = 0; i < 10; i++){
        if(keyCode == numberCodes[i]){
          channel = i;
        }
      }
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Current Channel : ");
      display.print(channel);
      display.display();
     }
     last = millis();
     irRecv.resume();
  }
  delay(50);
}
