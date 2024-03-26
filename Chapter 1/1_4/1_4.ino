void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Hall Effect = ");
  Serial.println(hallRead());
  delay(1000);
}
