#include <RCWL_1X05.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
#define button1 16
bool status = true;
Adafruit_SH1106 display(SDA, SCL );
RCWL_1X05 ultrasonic1;
void setup(){
  pinMode(button1, INPUT);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  Wire.begin();
  if(not ultrasonic1.begin()){
    display.println("Sensor not found!");
    display.display();
    while (true) {;}
  } 
  else{  
    display.println();
    display.println("Sensor ready!");
    display.println();
    delay(1000);
  }
  display.println("Display in Continuous mode\n\n");
  ultrasonic1.setFilter(true);
  ultrasonic1.setTimeout(50);
  ultrasonic1.setMode(RCWL_1X05::continuous);  
  display.display();
  delay(2000);
}
void loop(){
  float cm ; 
  bool data ;
  int press;
  press = digitalRead(button1);
  if(press == LOW){
    status = !status;
    delay(300);
  }
  if(status){
    data = ultrasonic1.update();
    if(data){
      cm = ultrasonic1.read();
      cm = cm/10;
      display.clearDisplay();
      display.setCursor(0,25);
      display.print("Distance = ");
      display.print(cm,1);
      display.println(" cm.");
      display.display(); 
    }
  }else{
    display.clearDisplay();
    display.setCursor(0,25);
    display.println("Off");
    display.display(); 
  }
}
