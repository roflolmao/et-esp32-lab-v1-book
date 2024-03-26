#ifdef __cplusplus
  extern "C" {
#endif
  uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
#define USEC_TO_SEC 1000000
#define TIME_OUT 10
void setup() {
  Serial.begin(115200);
  esp_sleep_enable_timer_wakeup( 
      USEC_TO_SEC*TIME_OUT );
  Serial.print(temprature_sens_read());
  Serial.println("F");
  Serial.flush();
  delay(1000);
  esp_deep_sleep_start();
}
void loop() {
}
