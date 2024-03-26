void setup() {
  Serial.begin(115200);
  while (!Serial); 
}
void loop() {
  Serial.println(9.87654321, 0);
  Serial.println(9.87654321, 1);
  Serial.println(9.87654321, 2);
  Serial.println(9.87654321, 3);
  delay(5000)
}
