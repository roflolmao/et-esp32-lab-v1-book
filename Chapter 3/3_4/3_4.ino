#include <Adafruit_NeoPixel.h> 
#define RGB 33
int allRGB = 8;
int brightness = 50;
int waitTime = 200;
int currentColor = 0;
Adafruit_NeoPixel rgbs = Adafruit_NeoPixel(
              allRGB, RGB, NEO_GRB + NEO_KHZ800);

uint32_t colors[] = {
  rgbs.Color(255, 0, 0),
  rgbs.Color(0, 255, 0),
  rgbs.Color(0, 0, 255),
  rgbs.Color(255, 255, 255),
  rgbs.Color(0, 0, 0)
};
void RGB_Spinning(long color, int wait) 
{
  for(int rgb=0; rgb < allRGB/2; rgb++) 
  { 
    rgbs.setPixelColor(rgb,color);
    rgbs.setPixelColor(rgb+4,color);
    rgbs.show();
    delay(wait);
  }
}
void setup() 
{
    rgbs.begin();
    rgbs.show();
    rgbs.setBrightness(brightness); 
}
void loop() 
{
  RGB_Spinning(colors[currentColor], waitTime);
  currentColor++;
  if(currentColor > 4){
    currentColor = 0;
  }
  rgbs.setBrightness(brightness); 
  brightness = brightness + 50;
  if(brightness > 255){
    brightness = 50;
  }
}
