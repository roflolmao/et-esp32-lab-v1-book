#include <ESP.h>
String sFlashMode[] = {
  "FM_QIO", "FM_QOUT", "FM_DIO", "FM_DOUT", 
  "FM_FAST_READ", "FM_SLOW_READ", "FM_UNKNOWN" };
void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.print("FlashChipSize (Byte).....: ");
  Serial.println(ESP.magicFlashChipSize(
      ESP.getFlashChipSize()));
  Serial.print("FlashChipSpeed (Hz)......: ");
  Serial.println(ESP.magicFlashChipSpeed(
      ESP.getFlashChipSpeed()));
  Serial.print("FlashChipMode ...........: ");

  Serial.println(sFlashMode[
    ESP.magicFlashChipMode(
    ESP.getFlashChipMode())]);
  Serial.println("----------");
  delay(5000);
}
