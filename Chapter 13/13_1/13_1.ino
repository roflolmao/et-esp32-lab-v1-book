#define IRF 36
int adc;
float volt;
float voltInput = 3.3;
void setup(){      
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);   
  display.clearDisplay();
  display.display();
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  pinMode(IRF, INPUT); 
}
void loop(){
  display.clearDisplay();
  display.setCursor(0, 0);
  adc   = analogRead(IRF);
  volt = float((adc * voltInput) / 4095);
  delay(100);
  display.print("ADC = ");
  display.println(adc);
  display.print("Volt = ");
  display.print(volt, 1);
  display.println(" V");
  display.display();
  delay(1000);
}



 


 
