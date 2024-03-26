#include <FS.h>
#include <SPI.h>
#include <SD.h>

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;
  if (!SD.begin()) {
    Serial.println("Error : Card mount failed!");
    while (1);
  }
  show_card_info();
}

void show_card_info() {
  uint8_t card_type = SD.cardType();
  uint32_t mb_base =  (1024*1024);
  
  if (card_type == CARD_NONE) {
    Serial.println("Error: Card not attatched!");
    while (1);
  }
  Serial.print("Found : ");
  switch (card_type) {
    case CARD_MMC:
    Serial.print("MMC (");
    break;
    case CARD_SD:
    Serial.print("SD (");
    break;
    case CARD_SDHC:
    Serial.print("SDHC (");
    break;
    default:
    Serial.print("Unkown! (");
  }
    Serial.print(SD.cardSize()/mb_base);
    Serial.println("MB.)");
    Serial.print("Usage : ");
    Serial.print(SD.usedBytes()/mb_base);
    Serial.print("/");
    Serial.print(SD.totalBytes()/mb_base);
    Serial.println("MB.");
}

void loop() {
}
