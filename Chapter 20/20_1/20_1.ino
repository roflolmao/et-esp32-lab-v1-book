#include <TFT_eSPI.h>
#define button1 34
#define button2 35
#define button3 36
TFT_eSPI tft = TFT_eSPI();
void home(){
  tft.fillScreen(TFT_BLUE);
  tft.setTextColor(TFT_WHITE, TFT_BLUE) ; // Set the font colour to be WHITE with a BLUE background, set text size multiplier to 1
  tft.setTextSize(3)                    ; // Set character size multiplier (this increases pixel size)
  tft.setCursor(85,30)                  ; // Set "cursor" at top left corner of display (85,30)
  tft.println("Menu")                   ; // We can now plot text on screen using the "print" class
  tft.setTextSize(1);
  tft.setCursor(90, 100);
  tft.println("1. First Program");
  tft.setCursor(90, 120);
  tft.println("2. Credit");
}
void firstProgram(){
  tft.fillScreen(TFT_BLUE);
  tft.setTextColor(TFT_WHITE, TFT_BLUE) ; // Set the font colour to be WHITE with a BLUE background, set text size multiplier to 1
  tft.setTextSize(3);
  tft.println("Hello World!!");
}
void credit(){
  tft.fillScreen(TFT_BLUE);
  tft.setTextColor(TFT_WHITE, TFT_BLUE) ; // Set the font colour to be WHITE with a BLUE background, set text size multiplier to 1
  tft.setTextSize(3);
  tft.println("ETT");
}
void setup(void){
  Serial.begin(115200);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button2, INPUT);
  tft.begin();
  home();
}
void loop(){
  if(!digitalRead(button1)){
    firstProgram();
    delay(300);
  }
  if(!digitalRead(button2)){
    credit();
    delay(300);
  }
  if(!digitalRead(button3)){
    home();
    delay(300);
  }
  Serial.print(digitalRead(button1));
  Serial.print(digitalRead(button2));
  Serial.println(digitalRead(button3));
}
