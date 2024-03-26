#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <ToneESP32.h>  
#define IR 15
#define Piezo 12
#define CH 0
IRrecv irRecv(IR);
decode_results results;
ToneESP32 piezo( Piezo ,CH);
int channel = 0;
int i;
unsigned long keyCode ,last = millis();
unsigned long numberCodes[] = {
  0xFF6897,0xFF30CF,0xFF18E7,0xFF7A85,0xFF10EF, 
  0xFF38C7,0xFF5AA5,0xFF42BD,0xFF4AB5,0xFF52AD
};
void beep(int note, int duration){                   
    piezo.tone(note, duration);       
    delay(duration*0.25);
}
void nooMalee(){
    beep(NOTE_E4, 333);
    beep(NOTE_D4, 166);
    beep(NOTE_C4, 250);
    beep(NOTE_D4, 250);
    beep(NOTE_E4, 250);
    beep(NOTE_E4, 250);
    beep(NOTE_E4, 500);
    beep(NOTE_D4, 250);
    beep(NOTE_D4, 250);
    beep(NOTE_D4, 500);
    beep(NOTE_E4, 250);
    beep(NOTE_G4, 250);
    beep(NOTE_G4, 500);
    beep(NOTE_E4, 333);
    beep(NOTE_D4, 166);
    beep(NOTE_C4, 250);
    beep(NOTE_D4, 250);
    beep(NOTE_E4, 250);
    beep(NOTE_E4, 250);
    beep(NOTE_E4, 500);
    beep(NOTE_D4, 250);
    beep(NOTE_D4, 250);
    beep(NOTE_E4, 333);
    beep(NOTE_D4, 333);
    beep(NOTE_C4, 1000);
}
void chang(){
  beep(NOTE_C5, 200);
  beep(NOTE_C5, 200);
  beep(NOTE_C5, 200);
  beep(NOTE_C5, 200);
  beep(NOTE_C5, 400);
  beep(NOTE_C5, 200);
  beep(NOTE_A4, 200);
  beep(NOTE_G4, 200);
  beep(NOTE_A4, 200);
  beep(NOTE_C5, 200);
  beep(NOTE_F4, 400);
  beep(NOTE_C5, 200);
  beep(NOTE_A4, 200);
  beep(NOTE_G4, 200);
  beep(NOTE_A4, 200);
  beep(NOTE_F4, 200);
  beep(NOTE_G4, 300);
  beep(NOTE_F4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_F4, 200);
  beep(NOTE_F4, 200);
  beep(NOTE_C4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_F4, 400);
  beep(NOTE_F4, 200);
  beep(NOTE_D4, 300);
  beep(NOTE_F4, 200);
  beep(NOTE_F4, 300);
  beep(NOTE_C4, 200);
  beep(NOTE_D4, 300);
  beep(NOTE_F4, 400);
  beep(NOTE_C5, 300);
  beep(NOTE_D4, 300);
  beep(NOTE_C5, 300);
  beep(NOTE_A4, 300);
  beep(NOTE_G4, 400);
  beep(NOTE_F4, 500);
}
void thatSpider(){
  beep(NOTE_C4, 200);
  beep(NOTE_C4, 200);
  beep(NOTE_C4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_E4, 300);
  beep(NOTE_E4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_C4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_C4, 500);
  beep(NOTE_D4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_F4, 200);
  beep(NOTE_G4, 300);
  beep(NOTE_G4, 400);
  beep(NOTE_F4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_F4, 200);
  beep(NOTE_G4, 200);
  beep(NOTE_E4, 400);
  beep(NOTE_C4, 200);
  beep(NOTE_C4, 200);
  beep(NOTE_C4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_E4, 400);
  beep(NOTE_E4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_C4, 200);
  beep(NOTE_D4, 200);
  beep(NOTE_E4, 400);
  beep(NOTE_C4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_F4, 400);
  beep(NOTE_G4, 400);
  beep(NOTE_G4, 200);
  beep(NOTE_F4, 200);
  beep(NOTE_E4, 200);
  beep(NOTE_F4, 200);
  beep(NOTE_G4, 200);
  beep(NOTE_E4, 400);
}
void setup(){
  irRecv.enableIRIn();
}
void loop(){
  if(irRecv.decode(&results)){
     if(millis() - last > 250){
      keyCode = results.value;
      for(i = 0; i < 10; i++){
        if(keyCode == numberCodes[i]){
          channel = i;
          break;
        }
      }
      switch (channel){
        case 0 : nooMalee(); break;
        case 1 : chang(); break;
        case 2 : thatSpider(); break;
        default : break;
      }
     }
     last = millis();
     irRecv.resume();
  }
  delay(50);
}
