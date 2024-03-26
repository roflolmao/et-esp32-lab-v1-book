#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
#define button1 39
#define tempPin 0
Adafruit_SH1106 display(SDA, SCL);
OneWire oneWire(tempPin);
DallasTemperature DS18B20(&oneWire);
unsigned int now = millis();
float temp;
int mode = 1;
char degreeLetter = 'C';
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
void setup(){
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  pinMode(button1, INPUT);
  display.clearDisplay();
  display.display();
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  DS18B20.begin();
}
void loop(){
  if(!digitalRead(button1)){
    mode++;
    if(mode > 3){
      mode = 1;
    }
    delay(300);
  }
  display.clearDisplay();
  display.setCursor(0, 0);
  if(millis() - now > 1000){
    DS18B20.requestTemperatures();
    temp = DS18B20.getTempCByIndex(0);
    now = millis();
    display.print("Temp : ");
    degreeLetter = 'C';
    if(mode == 2){
      temp = 9 / 5 * temp + 32;
      degreeLetter = 'F';
    }else if(mode == 3){
      temp = temp + 273;
      degreeLetter = 'K';
    }
    display.print(temp, 2);
    display.drawBitmap(display.getCursorX(), display.getCursorY(), degree, 8, 8, WHITE);
    display.setCursor(display.getCursorX() + 10, display.getCursorY());
    display.println(degreeLetter);
    display.display();
  }
}


 
