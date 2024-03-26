void setup() {
  Serial.begin(115200);
  esp_sleep_enable_ext0_wakeup( GPIO_NUM_32, 0 );
  Serial.println("Wakeup!");
  Serial.flush();
  delay(1000);
  Serial.println("Start sleep. [wait EXT0/P32]");
  Serial.flush();
  esp_deep_sleep_start();
}
void loop() {
}
