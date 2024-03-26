
/*************************************************************************************************
 *                              DEMO-LAB22:IR-Reflex(ITR9908)-ADC                                *
 *************************************************************************************************
 *                                                                                               *
 * Target Board      : ESP32 Dev Module , Freq. cpu 240MHz/Freq Flash 80Mhz/Flash Size 4 MB      *
 * Target MCU        : ESP-WROOM-32 Development Board Type-C                                     *                                                                                                
 * Editor            : Arduino 1.8.19                                                            *
 *                                                                                               * 
 * Add Library       :  -Adafruit-GFX-Library-master.zip                                         *
 *                      -esp32-sh1106-oled-master.zip                                            *                                                                         
 *                                                                                               *
 *                                                                                               *
 * Pin  Interface    :  Block(04)-(ESP32)     Connect    Block(02)-OLED,ADC-IRreflex             *
 *                      -----------------               ---------------------------------        *
 *    OLED-I2C-3V3   :   P21                                 SDA                                 *
 *                       P22                                 SCL                                 *                            
 *                       I2C Address 0x3C                                                        *
 *                                                                                               *                                                                                       
 *     ADC IR-Reflex : P36(ADC)             Connect          AO                                  *                       
 *                                                                                               *
 *                                                                                               *
 * Operation         : -                                                                         *                                                                                                            
 *                                                                                               *
 * Create By         : Mr. Sittiphol Yooyod (WWW.ETT.CO.TH)                                      *
 * Last Update       : 24/October/2023                                                           *
 *                                                                                               *
 *************************************************************************************************/
 


#include <Adafruit_GFX.h>     //LAB02-OLED 
#include <Adafruit_SH1106.h>  //LAB02-OLED 128x64 I2C




//-----------------Define I2C Pin OLED ------------

#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SH1106 dsp(OLED_SDA,OLED_SCL );


//-----------------IrPin IR Reflex ------------
#define IrfPin    36 


int IR_ADC      ;
float IR_Volte  ;


//++++++++++++++++++++++++++++ Sub-Program ++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++ Function-IR-REFLEX [ADC] ++++++++++++++++++++++++++++
//    -Read Value ADC to Display OLED [0-4096 12-bit] at VCC=3.3V  

void Demo_IrReflex(void)  
{
 
   IR_ADC   = analogRead(IrfPin)         ;    // Read Vale ADC 0-4096 from IR.at Vcc=3.3V(ADC 12Bit)
   IR_Volte = float((IR_ADC*3.3)/4095)  ;    //Convert value ADC to voltage
   delay(100);

   dsp.println();
   dsp.print(">IR ADC   = ")  ; //Show value ADC to OLED
   dsp.println(IR_ADC)        ;
   dsp.println();
      
   dsp.print(">IR Volte = ")  ; //Show value Volte to OLED
   dsp.print(IR_Volte,1)      ; //Point 1 position
   dsp.println(" V")          ;
   dsp.println("")            ;  

   dsp.display()              ;  // 
   
 
}


/*****************************************************************
 **                          Loop Setup                         **
 *****************************************************************/  
 
void setup() 
{         
  //--------Set OLED -----------
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  
   dsp.begin(SH1106_SWITCHCAPVCC, 0x3C)  ;  // initialize with the I2C addr 0x3C (for the 128x64)          
   dsp.clearDisplay()                    ;  // Clear the buffer.
   dsp.display()                         ;  // 
   delay(100)                            ;

   //Set Text for OLED
   dsp.setTextSize(1)       ;
   dsp.setTextColor(WHITE)  ;
   dsp.setCursor(0,0)       ;
   

  //----------- Set Pin Read Analog Signal Ir-Reflex to Input ------------- 
   pinMode(IrfPin,INPUT)     ; 

}
 

/*************************************************************************
 **         Loop Main function runs over and over again forever         **
 *************************************************************************/         

void loop() 
 {

    dsp.clearDisplay()       ;  // Clear the buffer OLED.
    dsp.setCursor(0,0)       ;
  
    Demo_IrReflex();; //Read Distance start min 25Cm-300Cm
    delay(1000);
   
 }//end loop



 


 
