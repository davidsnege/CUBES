
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
/*INICIAL VARIABLES--------------------------*/
/*-------------------------------------------*/
String stringOne = "";
char datos[30];
char RA_objetivo[9];
char DEC_objetivo[10];
long tele_RA_obj;
long tele_DEC_obj;
/*-------------------------------------------*/
/*SETUP--------------------------------------*/
/*-------------------------------------------*/
void setup() {
  // Testando I2C LCD
   if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  
  Serial.begin(9600);

  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CUBES ARDUSAT");
  delay(5000);
  lcd.clear();
}
/*-------------------------------------------*/
/*LOOP---------------------------------------*/
/*-------------------------------------------*/
void loop() {  
  pos_TELESCOPIO();
  data_STELLARIUM();
}
/*-------------------------------------------*/
/*FUNCIONES----------------------------------*/
/*-------------------------------------------*/
void pos_TELESCOPIO(){
    while (Serial.available()){ 
      char a=Serial.read();            
      stringOne += String(a);          
      delay(5);
    }
    if (stringOne == "#:GR#"){         
      Serial.print("01:54:23#");
      lcd.setCursor(7, 0);
      lcd.print("01:54:23#");
    }
    if (stringOne == "#:GD#"){         
      Serial.print("+63*40#");
      lcd.setCursor(7, 1);
      lcd.print("+63*40#");
    }
    stringOne = "";
}
/*-------------------------------------------*/
/*LER SERIAL DESDE STELLARIUM----------------*/
void data_STELLARIUM(){
    int i=0;
    datos[i++]=Serial.read();
    delay(5);
    while((datos[i++]=Serial.read())!='#'){
      delay(5);                                   
    } 
    datos[i]='\0';
    ra_dec_OBJETIVO();
}
/*-------------------------------------------*/
/*RA DEC OBJETIVO----------------------------*/
/*RA OBJETIVO--:Sr HH:MM:SS#-----------------*/
void ra_dec_OBJETIVO(){
  if(datos[0]==':' && datos[1]=='S' && datos[2]=='r'){
    for(int i=0;i<8;i++)
      RA_objetivo[i]=datos[i+4];                                    
    Serial.print("1");
    tele_RA_obj=long(atoi(datos+4))*long(3600)+long(atoi(datos+7))*long(60)+long(atoi(datos+10));
    lcd.setCursor(0, 0);
    lcd.print(RA_objetivo);
  }
/*DEC OBJETIVO--:Sd sDD*MM:SS#---------------*/  
  if(datos[0]==':' && datos[1]=='S' && datos[2]=='d'){
    for(int i=0;i<9;i++)
      DEC_objetivo[i]=datos[i+4];                                        
    Serial.print("1");
    tele_DEC_obj=long(atoi(datos+4))*long(3600)+long(atoi(datos+8))*long(60)+long(atoi(datos+11));
    lcd.setCursor(0, 1);
    lcd.print(DEC_objetivo);
  }
}
/*-------------------------------------------*/
/*PARAR TELESCOPIO--#:Q#---------------------*/
void parar_TELESCOPIO(){
  if(datos[1]==':' && datos[2]=='Q' && datos[3]=='#'){  
  }
}
/*-------------------------------------------*/
/*COMEÇAR SLEW--:MS#-------------------------*/
void comecar_SLEW(){
  if(datos[0]==':' && datos[1]=='M' && datos[2]=='S' && datos[3]=='#'){
    Serial.print("0");
  }  
}
/*-------------------------------------------*/
/*TEST DE LCD--------------------------------*/
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
