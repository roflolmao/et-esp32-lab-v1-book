
/*************************************************************************************************
 *                           DEMO-LAB02: OLED 128x64 I2C-3V3 (Drive sh1106)                      *
 *************************************************************************************************
 *                                                                                               *
 * Target Board      : ESP32 Dev Module , Freq. cpu 240MHz/Freq Flash 80Mhz/Flash Size 4 MB      *
 * Target MCU        : ESP-WROOM-32 Development Board Type-C                                     *                                                                                                
 * Editor            : Arduino 1.8.19                                                            *
 *                                                                                               * 
 * Library Ext.      : -Adafruit-GFX-Library-master.zip                                          *
 *                     -esp32-sh1106-oled-master.zip                                             *
 *                                                                                               *
 * Pin  Interface    :  Block(04)-(ESP32)     Connect    Block(02)-OLED I2C 128x64               *
 *                      -----------------               --------------------                     *
 *                      P21                                 SDA                                  *
 *                      P22                                 SCL                                  *                                  
 *                                                                                               *
 *                      I2C Address 0x3C                                                         *
 *                                                                                               *
 * Operation         :                                                                           *
 *                                                                                               *
 * Create By         : Mr. Sittiphol Yooyod (WWW.ETT.CO.TH)                                      *
 * Last Update       : 10/October/2023                                                           *
 *                                                                                               *
 *************************************************************************************************/


#include <Adafruit_GFX.h>     //LAB02-OLED 
#include <Adafruit_SH1106.h>  //LAB02-OLED 128x64 I2C


//-----------------Define I2C Pin ------------

#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SH1106 dsp(OLED_SDA,OLED_SCL );


//***************** Sub-Program ********************
//-----------Function Draw Text--------------

void testdrawchar(void) 
 {
   dsp.setTextSize(1);
   dsp.setTextColor(WHITE);
   dsp.setCursor(0,0);

  for(uint8_t i=0; i < 168; i++) 
   {
    if (i == '\n') continue;
      dsp.write(i);
    if ((i > 0) && (i % 21 == 0))
      dsp.println();
  }    
  dsp.display();
  
 }

/*****************************************************************
 **                          Loop Setup                         **
 *****************************************************************/  
 
void setup() 
{
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
   dsp.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)      
     
   dsp.clearDisplay(); // Clear the buffer.
   dsp.display();
   delay(100);

}


/*************************************************************************
 **         Loop Main function runs over and over again forever         **
 *************************************************************************/         

void loop() 
 {
   dsp.invertDisplay(true);//inverst on Black to Blue
   delay(1000); 
   dsp.invertDisplay(false);//inverst OFF bLUE TO black
   delay(500); 

   testdrawchar();
   delay(1000);
   dsp.clearDisplay();
   dsp.display();
  
   
 }


 
