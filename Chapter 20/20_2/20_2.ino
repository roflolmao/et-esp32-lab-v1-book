#include <TFT_eSPI.h>
#define button1 16
#define button2 17
#define button3 21
TFT_eSPI tft = TFT_eSPI();
int choice = 3;
void home(){
  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.setTextSize(3);
  tft.setCursor(85,30);
  tft.println("Menu");
  tft.setTextSize(2);
  tft.setCursor(60, 100);
  tft.println("1. Program");
  tft.setCursor(60, 120);
  tft.println("2. Credit");
}
void program(){
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.setCursor(45, 100);
  tft.println("Hello World!!");
  tft.setCursor(25, 120);
  tft.println("3. Back to Home");
}
void credit(){
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLUE, TFT_WHITE);
  tft.setCursor(90, 100);
  tft.println("ETT!");
  tft.setCursor(25, 120);
  tft.println("3. Back to Home");
  delay(100);
  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.setCursor(90, 100);
  tft.println("ETT!");
  delay(100);
}
void setup(void){
  Serial.begin(115200);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button2, INPUT);
  tft.begin();
  tft.fillScreen(TFT_BLUE);
  home();
}
void loop(){
  if(!digitalRead(button1)){
    tft.fillScreen(TFT_BLUE);
    choice = 1;
    delay(300);
  }
  if(!digitalRead(button2)){
    tft.fillScreen(TFT_BLUE);
    choice = 2;
    delay(300);
  }
  if(!digitalRead(button3)){
    tft.fillScreen(TFT_BLUE);
    choice = 3;
    delay(300);
  }
  if(choice == 1){
    program();
  }else if(choice == 2){
    credit();
  }else{
    home();
  }
}
