/*-------------------------------------------*/
/*INCLUDES-----------------------------------*/
/*-------------------------------------------*/
#include "LiquidCrystal_I2C.h"
/*-------------------------------------------*/
/*INICIALIZE LIBS----------------------------*/
/*-------------------------------------------*/
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);
/*-------------------------------------------*/
// -------------------------------------
// -------------------------------------
String stringOne = "";
char a;
String SrPOS = "";
String SdPOS = "";
bool SrOK = false;
bool SdOK = false;
byte grado = (char)223;
// -------------------------------------
// -------------------------------------
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Testando I2C LCD
   if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CUBES ARDUSAT");
  delay(5);
  lcd.clear();
}
// -------------------------------------
void loop() { 
/*-------------------------------------------*/
/*INICIALIZE WHILE---------------------------*/
/*-------------------------------------------*/ 
int i=0;
    while (Serial.available()){
      delay(5);
      char a=Serial.read();            
      stringOne += String(a);                                           
      delay(5);    
    }
/*-------------------------------------------*/
/*END WHILE----------------------------------*/
/*-------------------------------------------*/     
delay(5);
/*-------------------------------------------*/    
/*GET OBJECT POSITION SR---------------------*/
/*-------------------------------------------*/     
    int posSr=stringOne.indexOf("Sr");
    if (posSr>=0) {
        String srTEMP = stringOne;
        srTEMP.remove(15,9);
        srTEMP.remove(0,7); 
        srTEMP += "#";
        lcd.setCursor(0, 0);
        lcd.print(srTEMP);
        SrPOS = srTEMP;               
    }else{
        lcd.setCursor(0, 0);
        lcd.print(SrPOS);      
    }
delay(5); 
/*-------------------------------------------*/    
/*GET OBJECT POSITION SD---------------------*/
/*-------------------------------------------*/ 
    int posSd=stringOne.indexOf("Sd");
    if (posSd>=0) {
        String sdTEMP = stringOne;
        sdTEMP.remove(15,9);
        sdTEMP.remove(0,7); 
        sdTEMP += "#";      
        lcd.setCursor(0, 1);
        lcd.print(posSd);
        SdPOS = sdTEMP;        
    }else{
        lcd.setCursor(11, 0);
        lcd.print("No SdPOS");     
        lcd.setCursor(0, 1);
        lcd.print(stringOne); 
        lcd.print("                ");      
    }
delay(5);    
/*-------------------------------------------*/
/*-------------------------------------------*/
/*-------------------------------------------*/
        lcd.setCursor(11, 1);
        lcd.print(SrOK); 
        lcd.setCursor(14, 1);
        lcd.print(SrOK); 
/*-------------------------------------------*/
/*INICIALIZE POS TELESCOPE-------------------*/
/*-------------------------------------------*/     
    if (stringOne == "#:GR#"){
      if(SrPOS != ""){
        Serial.print(SrPOS);  
        int SrOK = true; 
      }else{
        Serial.print("01:54:23#");
        int SrOK = false;
      }
    }
    if (stringOne == "#:GD#"){   
      if(SdPOS != ""){
        Serial.print(SdPOS);
        int SdOK = true;        
      }else{
        Serial.print ("+");                  //DEC
        Serial.print ("70");                 //DEC: 45° (grados)
        Serial.print ((char)223);            //°
        Serial.print ("00");                 //DEC: 00' (min)
        Serial.print (":");
        Serial.print ("00");                 //DEC: 00''(sec) 
        Serial.print ("#");
        int SdOK = false;        
      }      
    }

    /*--Serial 1 or 0 ------*/
    if(SrOK == true){
      Serial.print(1);
    }
    if(SdOK == true){
      Serial.print(1);
    }
    if(SrOK == true){
      if(SdOK == true){
        Serial.print(0);
        SrOK = false;
        SdOK = false;
      }
    }
    /*---------------------*/

    


    
/*--Clear stringOne--*/    
    stringOne = "";
}
/*--End Loop--*/   
/*-------------------------------------------*/
/*-------------------------------------------*/
/*-------------------------------------------*/

/*-------------------------------------------*/
/*TEST DE LCD--------------------------------*/
/*-------------------------------------------*/
// I2C Address TEST 
bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) {
    return true;
  }
  return false;
}
/*-------------------------------------------*/
