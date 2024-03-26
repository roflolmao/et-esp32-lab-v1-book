#include <ToneESP32.h>
#define peizo 12
#define ch 0
ToneESP32 piezo1(peizo, ch);
void beep(int note, int duration) 
{                   
  piezo1.tone(note, duration);       
  delay(duration*0.25);
}
void setup() 
{
}
void loop() 
{
  beep(NOTE_C4, 250);
  beep(NOTE_D4, 250);
  beep(NOTE_E4, 250);
  beep(NOTE_F4, 250);
  beep(NOTE_G4, 250);
  beep(NOTE_A4, 250);
  beep(NOTE_B4, 250);
  beep(NOTE_A5, 1000);
  delay(1000);  
}
