#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.print("Internal temp. = ");
  Serial.print(temperature_sens_read());
  Serial.println("F.");
  delay(1000);
}
