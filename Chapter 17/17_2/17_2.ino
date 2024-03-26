#include <WiFi.h>
#include <time.h>
#include <uRTCLib.h>
#define SDA 21
#define SCL 22
#define led1 4
const char* ssid = "ชื่อ SSID";
const char* password = "รหัสผ่าน";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 7 * 3600;
const int daylightOffset_sec = 7 * 3600;
struct tm timeinfo;
int sec;
uRTCLib rtc(0x68, URTCLIB_MODEL_DS3231);
int ledStatus = LOW;
void setup(){
 pinMode(led1, OUTPUT);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
 }
 delay(1000);
 configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 URTCLIB_WIRE.begin();
 setLocalTime();
 WiFi.disconnect(true);
 WiFi.mode(WIFI_OFF);
}
void loop(){
 rtc.refresh();
 if(rtc.second() % 10 == 0 && sec != rtc.second()){    
   digitalWrite(led1, ledStatus);
   if(ledStatus == HIGH){      
     ledStatus = LOW;
   }else{
     ledStatus = HIGH;
   }
   sec = rtc.second();
 }
}
void setLocalTime(){
 while(!getLocalTime(&timeinfo)){
   delay(500);
 }
 rtc.set(timeinfo.tm_sec, timeinfo.tm_min, timeinfo.tm_hour, timeinfo.tm_wday + 1,
   timeinfo.tm_mday, timeinfo.tm_mon, timeinfo.tm_year - 100
 );
}