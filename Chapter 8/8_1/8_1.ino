#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
int btn[] = {26, 27, 32, 33, 34, 35, 36, 39};
int randomNumber;
int i;
Adafruit_SH1106 display (SDA, SCL);
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
  randomNumber = rand() % 8;
  display.print("Guess the number 0 - 7");
  delay(1000);
}
void loop(){
  if(i == 8){
    display.clearDisplay();
    display.setCursor(0,25);
    display.print("Guess the number 0 - 7");
    display.display(); 
  }
  for(i = 0; i < 8; i++){
    if(digitalRead(btn[i]) == LOW){
      break;
    }
  }
  if(randomNumber == i){
    display.clearDisplay();
    display.setCursor(0,25);
    display.println("Correct!");
    display.print("Random number = ");
    display.print(randomNumber);
    display.println();
    display.print("Button pressed ");
    display.print(i);
    display.display();
    delay(2000);
  }else if(i != 8){
    display.clearDisplay();
    display.setCursor(0,25);
    display.println("Wrong!");
    display.print("Random number = ");
    display.print(randomNumber);
    display.println();
    display.print("Button pressed ");
    display.print(i);
    display.display();
    delay(2000);
  }
  if(i != 8){
    randomNumber = rand() % 8;
  }
}
