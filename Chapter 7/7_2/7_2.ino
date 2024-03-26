#define sw1 32
#define sw2 33
#define spk 25
#define spkCh 0
#define volume 2048 // 50%
#define res 12
#define octave 4
#define time_ms 200
note_t notes[] = {
  NOTE_C, NOTE_D, NOTE_E, NOTE_F, 
  NOTE_G, NOTE_A, NOTE_B
};
float notes_freq[] = {
  261.63,293.66,329.63,349.23,392.00,440.00,493.88
};
int idx = 0;
int instruments = 0; // 0-square, 1-saw, 2-triangle, 3-sine
int sinePWMValue(float freq);
void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode( spk, OUTPUT );
  ledcSetup( spkCh, 1, res );
  ledcAttachPin( spk, spkCh );
  ledcWrite( spkCh, 0 );
}
void playSine() {
  ledcChangeFrequency(spkCh,
    (uint32_t)notes_freq[idx], res);
  for (int i = 0; i < time_ms; i++) {
    float angle=sin(2*PI*((float)i/
                (float)time_ms);
    int sValue = 2048+2047*angle*
                 (1000000/notes_freq[idx]));
    ledcWrite(spkCh, sValue);
    delay(1);
  }
}
void playSaw() {
  ledcChangeFrequency(spkCh,
      (uint32_t)notes_freq[idx], res);
  for (int i = 1; i <= time_ms; i++) {
    ledcWrite( spkCh,
              (int)(volume*(time_ms/i)));
    delay(1);
  }
}
void playTriangle() {
  ledcChangeFrequency(spkCh,
    (uint32_t)notes_freq[idx], res);
  for (int i = 1; i <= time_ms / 2; i++) {
    ledcWrite(spkCh(int)(volume*
              ((time_ms/2)/i)));
    delay(1);
  }
  for (int i = 1; i <= time_ms / 2; i++) {
    ledcWrite(spkCh,volume-
              (int)(volume*
              ((time_ms/2)/i)));
    delay(1);
  }
}
void playSquare() {
  ledcWriteNote( spkCh, notes[idx], octave);
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
    for (idx = 0; idx < 7; idx++) {
      switch (instruments) {
        case 0: playSquare(); 
                delay(time_ms); break;
        case 1: playSaw(); break;
        case 2: playTriangle(); break;
        case 3: playSine(); break;
      }
    }
    ledcWrite( spkCh, 0 );
  }
}
