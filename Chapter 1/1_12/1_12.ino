#include <ESP.h>
#include "esp32/rom/rtc.h"
void print_wakeup_reason() {
  switch (esp_sleep_get_wakeup_cause()) {
    case ESP_SLEEP_WAKEUP_EXT0: 
      Serial.println("RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1: 
      Serial.println("RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER: 
      Serial.println("Timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD: 
      Serial.println("Touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP: 
      Serial.println("ULP"); break;
    default: Serial.println("???");
  }
}
void print_reset_reason(int cpu) {
  switch (rtc_get_reset_reason(cpu)) {
    case 1: Serial.println("POWERON_RESET"); 
            break;
    case 3: Serial.println("SW_RESET"); break;
    case 4: Serial.println("OWDT_RESET"); break;
    case 5: Serial.println("DEEPSLEEP_RESET"); 
            break;
    case 6: Serial.println("SDIO_RESET"); break;
    case 7: Serial.println("TG0WDT_SYS_RESET");
            break;
    case 8: Serial.println("TG1WDT_SYS_RESET");
            break;
    case 9: Serial.println("RTCWDT_SYS_RESET"); 
            break;
    case 10: Serial.println("INTRUSION_RESET"); 
            break;
    case 11: Serial.println("TGWDT_CPU_RESET");
             break;
    case 12: Serial.println("SW_CPU_RESET");
             break;
    case 13: Serial.println("RTCWDT_CPU_RESET");
             break;
   case 14: Serial.println("EXT_CPU_RESET"); 
            break;
    case 15: 
        Serial.println("RTCWDT_BROWN_OUT_RESET"); 
        break;
    case 16: Serial.println("RTCWDT_RTC_RESET");
        break;
    default: Serial.println("NO_MEAN");
  }
}
void setup() {
  Serial.begin(115200);
  Serial.println("----WAKEUP?");
  print_wakeup_reason();
  Serial.println("----CPU0/PRO_CPU reset?");
  print_reset_reason(0);
  Serial.println("----CPU1/APP_CPU reset?");
  print_reset_reason(1);
  Serial.println("reset in 10seconds...");
  Serial.flush();
  delay(10000);
  ESP.restart();
}
void loop() {
}
