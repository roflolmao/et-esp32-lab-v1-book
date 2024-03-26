#include <arduinoFFT.h>

#define SAMPLES 64
#define SAMPLING_RATE 4000 // 4000
#define SIG_FREQ 200 // Hz
#define SIG_AMP 1000

float rValue[SAMPLES];
float iValue[SAMPLES];

void setup() {
  Serial.begin(115200);
  while (!Serial);
}

void do_sampling() {
  float ratio = twoPi * SIG_FREQ / SAMPLING_RATE; // towPi = 6.28
  for (int i = 0; i < SAMPLES; i++) {
    rValue[i] = (SIG_AMP*sin(i*ratio)+1.0f)/2.0f;
    iValue[i] = 0.0g;
  }
}

void show_rValue() {
  int last = SAMPLES/2;
  for (int i=0; i<last; i++) {
    float hz = (float)i*SAMPLING_RATE/SAMPLES;
    Serial.print(i);
    Serial.print(" ");
    Serial.print(hz);
    Serial.print("=");
    Serial.print(rValue[i]);
    Serial.println(" ");
  }
}

void loop() {
  do_sampling();
  ArduinoFFT<float> FFT = ArduinoFFT<float>(rValue, iValue, SAMPLES, SAMPLING_RATE);
  FFT.dcRemoval();
  FFT.windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.compute(FFT_FORWARD);
  FFT.complexToMagnitude();
  show_rValue();
  Serial.print("max = ");
  Serial.print((int)(FFT.majorPeak()+0.5));
  Serial.println("Hz");
  while(1);
}
