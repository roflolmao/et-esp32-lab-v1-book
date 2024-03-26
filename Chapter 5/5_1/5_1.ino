#include <uRTCLib.h> 
#define relay1 16
#define OLED_SDA 21
#define OLED_SCL 22
uRTCLib rtc(0x68,URTCLIB_MODEL_DS3231);
int hour   = 12;  //0-23
int minute = 0;  //0-59
int sec    = 0;  //0-59
int day   = 5; // 1(sun) - 7(Sat)
int date  = 1; // 1-31
int month = 2; // 1(Jan)-12(Dec)
int year  = 24; //0-99 คศ
void SetTimeDate()
{
  URTCLIB_WIRE.begin(); 
  rtc.set(sec,minute,hour,day,date,month,year);
}
void setup() {
  pinMode(relay1, OUTPUT);
  SetTimeDate();
}
void loop() {
  rtc.refresh() ;
  if(rtc.second() % 5 != 0){
    digitalWrite(relay1, HIGH);
  }else{
    digitalWrite(relay1, LOW);
  }
}
