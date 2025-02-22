/*-------------------------------------------*/
/*README-------------------------------------*/
/*-------------------------------------------*/
/*
 * #:GR#  -> Obtener posicion RA del telecopio - Stellarium/Telescopio/Stellarium
 * --Stelarium nos envia para pedir la posición AR actual del telescopio, y contestamos con
 * el formato "01:54:23#" en la salida.
 * 
 * #:GD#  -> Obtener posicion DEC del telescopio - Stellarium/Telescopio/Stellarium
 * --Stelarium nos envia para pedir la posición DEC actual del telescopio, y contestamos con
 * el formato "00º00:00#" usando para el caracter de grados el formato (char)223 en la salida.
 * 
 * #:Q#   -> Detener el telescopio - Stellarium/Telescopio 
 * --Viene del Stellarium, se envia para parar el movimiento del
 *  telescopio.
 * 
 * :Sr HH:MM:SS#  -> Direccion RA del objetivo - Stellarium/Telescopio 
 * --Viene del Stellarium, se envia para passar la coord AR
 * para el telescopio. 
 * Enviamos Serial.print("1"); para indicar que recibimos.
 *  
 * :Sd sDD*MM:SS# ->Direccion DEC del objetivo
 * --Viene del Stellarium, se envia para passar la coord DEC
 * para el telescopio. 
 * Enviamos Serial.print("1"); para indicar que recibimos.
 *  
 * :MS# -> Comenzar slew - Stellarium/Telescopio
 * --Viene del Stellarium, se envia para indicar que ha comenzado 
 * el movimiento Slew. 
 * Enviamos Serial.print("0"); para indicar que terminamos.
 * 
 * 
*/
/*-------------------------------------------*/
/*INCLUDES-----------------------------------*/
/*-------------------------------------------*/
#include "LiquidCrystal_I2C.h"
/*-------------------------------------------*/
/*Inicializando Librerias--------------------*/
/*-------------------------------------------*/
// Inicializando la libreria del LCD para conexión I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);
/*-------------------------------------------*/
/*Declarando Variables-----------------------*/
/*-------------------------------------------*/
String stringOne = "";
char a;
String SrPOS = "";
String SdPOS = "";
String SrOK = "0";
String SdOK = "0";
byte grado = (char)223;

int CMs;
/*-------------------------------------------*/
/*Executar SETUP-----------------------------*/
/*-------------------------------------------*/
void setup() {
  // El setup
  Serial.begin(9600);
  // Testando I2C LCD
   if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CUBES ARDUSAT");
  delay(500000);
  lcd.clear();
}
/*-------------------------------------------*/
/*Executando Bucle---------------------------*/
/*-------------------------------------------*/
void loop() { 
    /*-------------------------------------------*/
    /*Recibimos datos de STELLARIUM--------------*/
    /*-------------------------------------------*/ 
    delay(5);
        while (Serial.available()){
          delay(5);
          char a=Serial.read();            
          stringOne += String(a);                                           
          delay(5);         
        }
    /*-------------------------------------------*/
    /*Acabamos de recibir datos de STELLARIUM----*/
    /*-------------------------------------------*/     
    /*-------------------------------------------*/
    /*Inicializamos las posiciones de telescopio-*/
    /*-------------------------------------------*/
    /*-------------------------------------------*/    
    /*Cogiendo la Pos ARC SR---------------------*/ /*-- Format input: #:Q#:Sr05:16:42# --*/
    /*-------------------------------------------*/     
        int posSr=stringOne.indexOf("Sr");
        if (posSr>=0) {
          String srTEMP = "";
          SrPOS = "";
            srTEMP = stringOne;
            srTEMP.remove(15,9);
            srTEMP.remove(0,7); 
            srTEMP += "#";
            SrPOS = srTEMP;
            delay(5);            
            SrOK = "1";


            
        }
    delay(5);  
    /*Posición GR TELE----------------------------*/     
        if (stringOne == "#:GR#"){
          if(SrPOS != ""){
            Serial.print(SrPOS);
            lcd.setCursor(5, 0);
            lcd.print(SrPOS);  
          }else{
            Serial.print("00:00:00#");
            lcd.setCursor(0, 0);
            lcd.print("AR");                      
          }
        }
    delay(5);        
    /*-------------------------------------------*/    
    /*Cogiendo la Pos DEC SD---------------------*/ /*-- Format input: :Sd+45ß59:35# --*/
    /*-------------------------------------------*/ 
        int posSd=stringOne.indexOf(":Sd");
        if (posSd>=0) {
          String sdTEMP = "";
          SdPOS = "";
            sdTEMP = stringOne;
            sdTEMP.remove(13,8);
            sdTEMP.remove(0,3);     
            SdPOS = sdTEMP;
            delay(5);          
            SdOK = "1";               
        }
    delay(5);        
    /*Posición GD TELE---------------------------*/      
        if (stringOne == "#:GD#"){   
          if(SdPOS != ""){
            Serial.print(SdPOS);
            lcd.setCursor(4, 1);
            lcd.print(SdPOS);
          }else{
            Serial.print ("+");                  
            Serial.print ("00");                 
            Serial.print ("*");   //"\xC2\xB0" //(char)223        
            Serial.print ("00");                 
            Serial.print (":");
            Serial.print ("00");                  
            Serial.print ("#");
            lcd.setCursor(0, 1);
            lcd.print("DEC");                             
          }      
        }
    delay(5);        
    /*-------------------------------------------*/    
    /*Reseteamos DEBUG---------------------------*/
    /*-------------------------------------------*/  
        /*--Serial 1 or 0 ------*/
        if(SrOK == "1"){
          Serial.print("1#");
          SrOK = "0";
        }
        if(SdOK == "1"){
          Serial.print("1#");
          SdOK = "0"; 
        }        

        int posMS=stringOne.indexOf(":MS#");
        if (posMS>=0) { 
          Serial.print("0"); //0/1/2
          delay(5); 
        }

        int posCM=stringOne.indexOf(":CM#");
        if (posCM>=0) { 
          Serial.print("0"); //0/1/2
          delay(5); 
        }   

    delay(5);        
    /*-------------------------------------------*/
    /*-------------------------------------------*/
    /*-------------------------------------------*/       
    /*--Limpiamos stringOne ---------------------*/    
    stringOne = "";
    delay(5);



    
} 
/*-------------------------------------------*/
/*Se acaba el Bucle--------------------------*/
/*-------------------------------------------*/

/*-------------------------------------------*/
/*Función de testeo LCD----------------------*/
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
/*-------------------------------------------*/
/*-------------------------------------------*/
