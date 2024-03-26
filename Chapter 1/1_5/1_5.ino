#define PIN_SW 34
#define PIN_LED 21
uint8_t statusLED = 1;
void IRAM_ATTR toggleLED( ) {
  if (statusLED) statusLED = 0;
  else statusLED = 1;
  Serial.println(">> toggleLED() <<");
}
void setup() {
  Serial.begin(115200);
  pinMode( PIN_SW, INPUT_PULLUP );
  pinMode( PIN_LED, OUTPUT );
  attachInterrupt( PIN_SW, toggleLED, FALLING );
}
void loop() {
  Serial.println("loop.");
  delay(1000);
}
