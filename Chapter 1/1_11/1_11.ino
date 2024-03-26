#define THRESHOLD 100
String s[] = {
  "T0/P4","T1/P0","T2/P2","T3/P15","T4/P13",
  "T5/P12","T6/P14","T7/P27","T8/P33","T9/P32"};
void touch_stat() {
  touch_pad_t touch_pin =
       esp_sleep_get_touchpad_wakeup_status(); 
  Serial.println(s[touch_pin]);
}
void setup() {
  Serial.begin(115200);
  touch_stat();
  esp_sleep_enable_touchpad_wakeup();
  touchSleepWakeUpEnable(T3,THRESHOLD);
  Serial.flush();
  delay(1000);
  esp_deep_sleep_start();
}
void loop() {
}
