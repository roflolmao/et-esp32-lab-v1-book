#include <FS.h>
#include <SPI.h>
#include <SD.h>

extern "C" {
  uint8_t temprature_sens_read();
}

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;
  if (!SD.begin()) {
    Serial.println("Error : Card mount failed!");
    while (1);
  }
}

void loop() {
  for (int i=0; i<5; i++) {
    uint8_t temp_c=(temprature_sens_read()-32)/1.8;
    File o_file = SD.open("/ett_log.txt", FILE_APPEND);
    if (!o_file) {
      o_file = SD.open("/ett_log.txt", FILE_WRITE);
    }
    o_file.write(temp_c);
    o_file.close();
    delay(5000);
  }
  File i_file = SD.open("/ett_log.txt", FILE_READ);
  int i=0;
  while (i_file.available()) {
    uint8_t data = i_file.read();
      Serial.print(++i);
      Serial.print("=");
      Serial.print(data);
      Serial.println("C");
    
  }
  
  i_file.close();
  SD.remove("/ett_log.txt");

  while(1);
}
