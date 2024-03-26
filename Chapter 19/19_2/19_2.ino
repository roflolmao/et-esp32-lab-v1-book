#include <DHT20.h>
#include <ESP32_Servo.h>
#include <ToneESP32.h>
#define peizo 12
#define SDA 21
#define SCL 22
#define ch 0
float humid, temp;
int status;
DHT20 dht;
ToneESP32 piezo1(peizo, ch);
void beep(int note, int duration){                   
  piezo1.tone(note, duration);       
  delay(duration*0.25);
}
void setup(){
  Wire.begin(SDA, SCL);   
  dht.begin();
}
void loop(){
  status = dht.read();
  if(status != DHT20_OK){
    delay(100);
    return;
  }
  humid = dht.getHumidity();
  temp = dht.getTemperature();
  Serial.println(temp);
  if(temp > 25){
    beep(NOTE_C4, 250);
  }
  delay(1000);
}