#include <DHT20.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
float temp, humid;
int status;
Adafruit_SH1106 display(SDA, SCL);
DHT20 dht;
void setup(){
  dht.begin();
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);       
  display.clearDisplay();
  display.display();
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}
void loop(){
  display.clearDisplay();
  display.setCursor(0, 0);
  status = dht.read();
  if(status != DHT20_OK){
    display.print("Error");
    display.display();
    return;
  }
  humid = dht.getHumidity();
  temp = dht.getTemperature();
  display.println("");
  display.print("Humidity = ");
  display.print(humid, 1);
  display.print(" %");
  display.println("");
  display.println("");
  display.println("");
  display.print("Temperature = ");
  display.print(temp, 1);
  display.println(" ^C");
  display.println("");
  display.drawRect(10, 20, 100, 10, WHITE);
  display.fillRect(10, 20, humid, 10, WHITE);
  display.drawRect(10, 50, 100, 10, WHITE);
  display.fillRect(10, 50, temp, 10, WHITE);
  display.display();
  delay(1000);
}


 
