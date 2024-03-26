#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
#define ADC0 34
#define ADC1 35
Adafruit_SH1106 display(SDA, SCL);
float inputVoltage = 3.3;
float lowBound = 0.8;
float highBound = 2.0;
int ADCIn0,ADCIn1;
float VA0,VA1;
void setup(){
   display.begin(SH1106_SWITCHCAPVCC, 0x3C);    
   display.clearDisplay();
   display.display();
   delay(100);
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,0);
   pinMode(ADC0,INPUT);
   pinMode(ADC1,INPUT);
}
void loop(){
  display.clearDisplay();
  display.setCursor(0,0);
  ADCIn0 = analogRead(ADC0);
  ADCIn1 = analogRead(ADC1);
  delay(500);
  VA0 = float((ADCIn0 * inputVoltage) / 4095);
  VA1 = float((ADCIn1 * inputVoltage) / 4095);  
  display.print("TTL of A0  = ");
  if(VA0 < lowBound){
    display.println("LOW");
  }else if(VA0 > highBound){
    display.println("HIGH");
  }else{
    display.println("Unknown");
  }
  display.print("TTL of A1  = ");
  if(VA1 < lowBound){
    display.println("LOW");
  }else if(VA1 > highBound){
    display.println("HIGH");
  }else{
    display.println("Unknown");
  }
  display.display();
  delay(1000);
 }