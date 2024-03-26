#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
#define tempPin 0
Adafruit_SH1106 display(SDA, SCL);
OneWire oneWire(tempPin);
DallasTemperature DS18B20(&oneWire);
float tempC;
static const unsigned char PROGMEM degree[] = { 
 0b00000010, 
 0b00000101, 
 0b00000010,
 0b00000000,
 0b00000000,
 0b00000000,
 0b00000000,
 0b00000000
}; 
static const unsigned char PROGMEM smile[] = {
  0b01100110,
  0b10011001,
  0b00000000,
  0b00000000,
  0b10000001,
  0b01000010,
  0b00111100,
  0b00000000
};
static const unsigned char PROGMEM normal[] = {
  0b00000000,
  0b11100111,
  0b00000000,
  0b00000000,
  0b00000000,
  0b01111110,
  0b00000000,
  0b00000000
};
static const unsigned char PROGMEM angry[] = {
  0b10100101,
  0b01000010,
  0b10100101,
  0b00000000,
  0b00000000,
  0b00111100,
  0b01000010,
  0b10000001
};
void setup(){
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  DS18B20.begin();
}
void loop(){
  display.clearDisplay();
  display.setCursor(0, 0);
  DS18B20.requestTemperatures();
  tempC = DS18B20.getTempCByIndex(0);
  display.println("");
  display.print("Temp: ");
  display.print(tempC, 2);
  display.drawBitmap(display.getCursorX(), display.getCursorY(), degree, 8, 8, WHITE);
  display.setCursor(display.getCursorX() + 10, display.getCursorY());
  display.print("C");
  if(tempC < 25){
    display.drawBitmap(50, 36, smile, 8, 8, WHITE);
  }else if(tempC < 30){
    display.drawBitmap(50, 36, normal, 8, 8, WHITE);
  }else{
    display.drawBitmap(50, 36, angry, 8, 8, WHITE);
  }
  display.display();
  delay(500);
  delay(500); 
}


 
