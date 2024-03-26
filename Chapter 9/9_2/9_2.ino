#define pinSpk 26
#define pinMic 36
int adcValue;
void setup() {
  pinMode( pinSpk, OUTPUT);
  pinMode( pinMic, INPUT);
  Serial.begin(115200);
  analogReadResolution(12);
}
void loop() {
  for (int i = 0; i < 255; i++) {
    dacWrite( pinSpk, i );
    adcValue = analogRead(pinMic);
    Serial.println(adcValue);
  }
}
