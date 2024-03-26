#define sw1 32
#define sw2 33
#define spk 25
#define spkCh 0
#define volume 2048 // 50%
#define res 12
#define octave 4
#define time_ms 90
#define c 261.63
#define d 293.66
#define e 329.63
#define f 349.23
#define g 392.00
#define a 440.00
#define b 493.88
#define s 0.0
float song[] ={
s,s,s,c,s,c,s,c,s,d,s,e,s,s,s,e,s,e,s,d,s,c,s,d,s,e,s,c,
s,s,s,s,s,s,s,e,s,e,s,e,s,f,s,g,s,s,s,g,s,s,s,f,s,e,s,f,
s,g,s,e,s,s,s,s,s,s,s,c,s,c,s,c,s,d,s,e,s,s,s,e,s,s,s,d,
s,c,s,d,s,e,s,c,s,s,s,s,s,s,s,c,s,c,s,c,s,d,s,e,s,s,s,e,
s,e,s,d,s,c,s,d,s,e,s,c,s,s,s,s 
};
int song_len = 0;
int idx = 0;
int instruments = 0; 
int adcValue;
void setup() {
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode( spk, OUTPUT );
  song_len = sizeof(song) / sizeof(float);
  ledcSetup( spkCh, 1, res );
  ledcAttachPin( spk, spkCh );
  ledcWrite( spkCh, 0 );
}
void playSine() {
  if (song[idx] > 0.00) {
    ledcChangeFrequency(spkCh,
                        (uint32_t)song[idx],res);
    for (int i = 0; i < time_ms; i++) {
        float angle=sin(2*PI*
                        ((float)i/(float)time_ms);
        int sValue=volume+(volume-1)*angle* 
                        (1000000/song[idx]));

        ledcWrite(spkCh, sValue);
        delay(1);
    }
    ledcWrite( spkCh, 0 );
  } else {
        ledcWrite( spkCh, 0 );
        delay(time_ms);
  }
}
void playSaw() {
  if (song[idx] > 0.0) {
    ledcChangeFrequency(spkCh,
                        (uint32_t)song[idx], res);
    for (int i = 1; i <= time_ms; i++) {
      ledcWrite( spkCh, 
                 (int)(volume * (time_ms / i)));
      delay(1);
    }
    ledcWrite( spkCh, 0 );
  } else {
    ledcWrite( spkCh, 0 );
    delay(time_ms);
  }
}
void playTriangle() {
  if (song[idx] > 0.0) {
    ledcChangeFrequency(spkCh,
                       (uint32_t)song[idx], res);
    for (int i = 1; i <= time_ms / 2; i++) {
      ledcWrite(spkCh,(int)(volume*
                      ((time_ms/2)/i)));
      delay(1);
    }
    float val = (float)(time_ms/2.0);
    for (int i = 1; i <= time_ms / 2; i++) {
     ledcWrite(spkCh,volume-(int)(volume*(val/i)));
     delay(1);
    }

    ledcWrite( spkCh, 0 );
  } else {
    ledcWrite( spkCh, 0 );
    delay(time_ms);
  }
}
void playSquare() {
  if (song[idx] > 0.0) {
    ledcChangeFrequency(spkCh,
                       (uint32_t)song[idx],res);
    ledcWrite( spkCh, volume );
    delay(time_ms);
  } else {
    ledcWrite( spkCh, 0 );
    delay(time_ms);
  }
}
void loop() {
  if (digitalRead(sw1)) { // change instrument
    instruments++;
    if (instruments > 3) {
      instruments = 0;
    }
    delay(250);
  }
  if (digitalRead(sw2)) { // Play
    for (idx = 0; idx < song_len; idx++) {
      switch (instruments) {
        case 0: playSquare(); break;
        case 1: playSaw(); break;
        case 2: playTriangle(); break;
        case 3: playSine(); break;
      }
    }
  }
}
