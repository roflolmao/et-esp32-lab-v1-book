void setup() {
  pinMode(25, OUTPUT);
  ledcSetup(0, 50, 12);
  ledcAttachPin(25, 0);
  ledcWrite(0, (uint32_t)(4096 / 2));
}
void loop() {
}
