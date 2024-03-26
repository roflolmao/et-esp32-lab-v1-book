#include <WiFi.h>
#include <time.h>
#include <uRTCLib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#define SDA 21
#define SCL 22
const char* ssid = "ชื่อ SSID";
const char* password = "รหัสผ่าน";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 7 * 3600;
const int daylightOffset_sec = 7 * 3600;
struct tm timeinfo;
String Str_Day[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
String Str_Month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
Adafruit_SH1106 display(SDA, SCL);
uRTCLib rtc(0x68, URTCLIB_MODEL_DS3231);
int hour, minute, sec, day, date, month, year;
void updateTime(){
 hour = rtc.hour();
 if(hour < 10){
   display.print("0");
 }  
 display.print(hour);
 display.print(":");
 minute = rtc.minute();
 if(minute < 10){
   display.print("0");
 }    
 display.print(minute);
 display.print(":");
 sec = rtc.second();
 if(sec < 10){
   display.print("0");
 }                          
 display.print(sec);
}
void updateDate(){
 day = rtc.dayOfWeek();
 display.print(Str_Day[day - 1]);
 display.print(",");
 date = rtc.day();
 if(date < 10){
   display.print("0");
 }    
 display.print(date);
 display.print(" ");
 month = rtc.month();
 display.print(Str_Month[month - 1]);
 display.print(" ");
 year = rtc.year();
 display.print("20");
 if(year < 10){
   display.print("0");
 }
 display.print(year);
}
void setup(){
 display.begin(SH1106_SWITCHCAPVCC, 0x3C);      
 display.clearDisplay();
 display.display();
 delay(100);
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(0, 0);
 display.println("Connecting to Wifi");
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   display.print(".");
   display.display();
 }
 display.clearDisplay();
 display.setCursor(0, 0);
 display.print("Connect Success");
 display.display();
 delay(3000);
 configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 URTCLIB_WIRE.begin();  
 printLocalTime();
 WiFi.disconnect(true);
 WiFi.mode(WIFI_OFF);
}
void loop(){
 rtc.refresh();
 display.clearDisplay();
 display.setTextSize(2);
 display.setCursor(15, 10);
 updateTime();
 display.println("");
 display.println("");
 display.setTextSize(1);
 display.setCursor(15, display.getCursorY());
 updateDate();
 display.display();
}
void printLocalTime(){
 display.clearDisplay();
 display.setCursor(0, 0);
 display.println("Retrieving Time from Internet");
 display.display();
 if(!getLocalTime(&timeinfo)){
   display.print(".");
   display.display();
   delay(500);
 }
 display.clearDisplay();
 display.setCursor(0, 0);
 display.print("Retrieve Success");
 display.display();
 delay(3000);
 rtc.set(timeinfo.tm_sec, timeinfo.tm_min, timeinfo.tm_hour, timeinfo.tm_wday + 1,
   timeinfo.tm_mday, timeinfo.tm_mon, timeinfo.tm_year - 100
 );
}