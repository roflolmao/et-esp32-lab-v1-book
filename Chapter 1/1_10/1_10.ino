#ifdef __cplusplus
  extern "C" {
#endif
  uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
#define USEC_TO_SEC 1000000
#define TIME_OUT 10
#define MAX_NUM_TEMP 5
RTC_DATA_ATTR uint8_t counter=0;
RTC_DATA_ATTR uint8_t temps[MAX_NUM_TEMP];
void setup() {
  Serial.begin(115200);
  esp_sleep_enable_timer_wakeup( 
      USEC_TO_SEC*TIME_OUT );
  temps[counter] = temprature_sens_read();
  counter++;
  Serial.print(counter);
  Serial.print(":");
  for (int i=0; i<counter; i++) {
    Serial.print(temps[i]);
    Serial.print("F ");
  }
  Serial.println();
  if (counter == MAX_NUM_TEMP) {
    counter = 0;
    int sum=0;
    for (int i=0; i<MAX_NUM_TEMP; i++) {
      sum += temps[i];
    }
    Serial.print("Average  =");
    Serial.print(sum/MAX_NUM_TEMP);
    Serial.println("F");
  }
  Serial.flush();
  delay(1000);
  esp_deep_sleep_start();
}
void loop() {
}
