#include <esp_task_wdt.h>
#define WDT_TIMEOUT 5
void setup() {
  Serial.begin(115200);
  esp_task_wdt_init(WDT_TIMEOUT, true);  
  esp_task_wdt_add(NULL); 
}
int loop_counter = 0;

void loop() {
  esp_task_wdt_reset();
  loop_counter++;
  Serial.println(loop_counter);
  delay(loop_counter*1000);
}
