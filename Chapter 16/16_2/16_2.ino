#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
int charPos = 10;
String words = "Hello World! \nWe are ETT!!";
String textToWrite = "Progressing";
int progress = 0;
bool showText = true;
Adafruit_SH1106 dsp(SDA, SCL);
void setup(){
  dsp.begin(SH1106_SWITCHCAPVCC, 0x3C);    
  dsp.clearDisplay();
  dsp.setTextSize(1);
  dsp.setTextColor(WHITE);
  dsp.setCursor(0,0);
  dsp.display();
}
void loop() {
  dsp.clearDisplay();
  dsp.println(words);
  if(showText){
    charPos = 10;
    for(int i = 0; i < 11; i++){
      dsp.drawChar(charPos, 40, textToWrite[i], BLACK, WHITE, 1);
      charPos += 5; 
    }
  }
  showText = !showText;
  dsp.drawRect(10, 50, 100, 10, WHITE);
  dsp.fillRect(10, 50, progress, 10, WHITE);
  progress += 10; 
  if(progress > 100){
    progress = 0;
  }
  dsp.setCursor(0,0);
  dsp.display();
  delay(1000);
}
