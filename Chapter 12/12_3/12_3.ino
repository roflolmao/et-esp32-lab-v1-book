#include <arduinoFFT.h>

#define L1 50
#define L2 100
#define L3 150
#define L4 200
#define MIC_PIN 36
#define SAMPLES 64
#define SAMPLING_RATE 2000  // Hz

float rValue[SAMPLES];
float iValue[SAMPLES];

void setup() {
  pinMode(MIC_PIN, INPUT);
  Serial.begin(115200);
}

void do_sampling() {
  unsigned int period;
  unsigned long usec;
  usec = micros();
  for (int i = 0; i < SAMPLES; i++) {
    rValue[i] = (float)analogRead(MIC_PIN);
    iValue[i] = 0.0f;
    while (micros() - usec < period);
    usec += period;
  }
}

void do_report() {
  int last = SAMPLES / 2;
  for (int i = 0; i < last; i++) {
    float hz = (float)i * SAMPLING_RATE / SAMPLES;
    float counter = 0.0;
    if (hz >= 60) {
      if (hz <= 250) {
        counter += rValue[i];
      }
    }
    if (counter > L4) {
      Serial.println(">>>>");
    } else if (counter > L3) {
      Serial.println(">>>");
    } else if (counter > L2) {
      Serial.println(">>");
    } else if (counter > L1) {
      Serial.println(">");
    }
  }
}

void loop() {
  // รับค่า
  do_sampling();
  // แปลง
  ArduinoFFT<float> FFT = ArduinoFFT<float>(rValue, iValue, SAMPLES, SAMPLING_RATE);
  FFT.dcRemoval();
  FFT.windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.compute(FFT_FORWARD);
  FFT.complexToMagnitude();
  // แสดงผลความถี่
  do_report();
  delay(1);
}
