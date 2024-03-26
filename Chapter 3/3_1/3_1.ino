int LEDs[] = {0, 2, 12, 15, 5, 18, 19, 23 };
int i;
int counter = 1;
void setup() {
  for(i = 0; i < 8; i ++){
    pinMode(LEDs[i], OUTPUT);
  }
}
