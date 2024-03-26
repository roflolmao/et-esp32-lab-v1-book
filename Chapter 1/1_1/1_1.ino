#include <ESP.h>
void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.println("\n\n>>-----RAM/HEAP-----<<");
  Serial.print("Size ........: ");
  Serial.println(ESP.getHeapSize());
  Serial.print("Free ........: ");
  Serial.println(ESP.getFreeHeap());
  Serial.print("Min Free ....: ");
  Serial.println(ESP.getMinFreeHeap());
  Serial.print("Max Alloc ...: ");
  Serial.println(ESP.getMaxAllocHeap());
  Serial.println(">>------PSRAM-------<<");
  Serial.print("Size ........: ");
  Serial.println(ESP.getPsramSize());
  Serial.print("Free ........: ");
  Serial.println(ESP.getFreePsram());
  Serial.print("Min Free ....: ");
  Serial.println(ESP.getMinFreePsram());
  Serial.print("Max Alloc ...: ");
  Serial.println(ESP.getMaxAllocPsram());
  delay(5000);
}
