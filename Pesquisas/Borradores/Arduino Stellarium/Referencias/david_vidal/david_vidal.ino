
#include "LiquidCrystal_I2C.h"
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);

char datos[30];  //Datos leidos por el puerto serie

//Coordenadas del telescopio y del objetivo
char RA_telescopio[9];
char DEC_telescopio[10];
char RA_objetivo[9];
char DEC_objetivo[10];

long DEC_dd, DEC_mm, DEC_ss;
long RA_hh, RA_mm, RA_ss;

long RA_tel, DEC_tel, RA_obj, DEC_obj;

void setup() {
  // Testando I2C LCD
   if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  
  // put your setup code here, to run once:
  Serial.begin(9600);                                     // Puerto Serie a 9600 bps
  Serial.println("ArduGoTo v0.1");                        //Publicidad XD
  //Esto hay que modificarlo, las coordenadas iniciales tienen que venir dadas
  RA_obj=RA_tel=(long(2)*long(60))+long(15899);             
  DEC_obj=DEC_tel=long(41)*long(3600)+long(38879)*long(60);

  RA_obj=RA_tel=(long(41)*long(60))+long(23);             
  DEC_obj=DEC_tel=long(2)*long(3600)+long(9)*long(60);

  lcd.init();  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("STELLARDU");
  delay(5000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    leer_datos_serie();
  }
  comparar_coordenadas();
}

void incrementar_ra(){
  RA_tel++;
  if(RA_tel>=long(86400)){
    RA_tel=RA_tel-long(86400);
  }
}

void decrementar_ra(){
  RA_tel--;
  if(RA_tel<long(0)){
    RA_tel=RA_tel+long(86400);
//  RA_tel=long(86400)+RA_tel;
  }
}

void incrementar_dec(){
  DEC_tel++;
  if(DEC_tel>long(324000)){
    DEC_tel=long(324000);
  }
}

void decrementar_dec(){
  DEC_tel--;
  if(DEC_tel<long(-324000)){
    DEC_tel=long(-324000);
  }
}

void comparar_coordenadas(){
    if(RA_tel<RA_obj){
      incrementar_ra();  
    }
    if(RA_tel>RA_obj){
      decrementar_ra();
    }
    if(DEC_tel<DEC_obj){
      incrementar_dec();
    }
    if(DEC_tel>DEC_obj){
       decrementar_dec();
    } 
}

void leer_datos_serie(){
  int i=0;
  datos[i++]=Serial.read();
  delay(5);
  while((datos[i++]=Serial.read())!='#'){       //Leo hasta el final del comando, que es un simbolo #
    delay(5);                                   //Espero 5ms por si aun no esta disponbile el siguiente dato
  }
  datos[i]='\0';                                //Completo la cadena con el simbolo de fin de cadena, cosas del C
  parsear_datos();                              //Llamo a la funcion que interpreta los datos recibidos
}

void parsear_datos(){

  // #:GR#  -> Obtener posicion RA del telecopio
  if(datos[1]==':' && datos[2]=='G' && datos[3]=='R' && datos[4]=='#'){
    RA_hh=RA_tel/long(3600);
    RA_mm=(RA_tel-(RA_hh*long(3600)))/long(60);
    RA_ss=RA_tel-(RA_hh*long(3600))-(RA_mm*long(60));
    sprintf(RA_telescopio, "%02d:%02d:%02d", int(RA_hh), int(RA_mm), int(RA_ss));
    Serial.print(RA_telescopio);
    Serial.print("#");
    lcd.setCursor(8, 0);
    lcd.print(RA_telescopio);
  }

  // #:GD#  -> Obtener posicion DEC del telescopio
  if(datos[1]==':' && datos[2]=='G' && datos[3]=='D' && datos[4]=='#'){
    DEC_dd=DEC_tel/long(3600);   //148560 -> 41 16
    DEC_mm=(DEC_tel-(DEC_dd*long(3600)))/long(60);
    DEC_ss=DEC_tel-(DEC_dd*long(3600))-(DEC_mm*long(60));
    sprintf(DEC_telescopio, "%+03d:%02d:%02d", int(DEC_dd), int(DEC_mm), int(DEC_ss));
    Serial.print(DEC_telescopio);
    Serial.print("#"); 
    lcd.setCursor(8, 1);
    lcd.print(DEC_telescopio); 
  }

  // #:Q#   -> Detener el telescopio
  if(datos[1]==':' && datos[2]=='Q' && datos[3]=='#'){
  }                                                                        // <<<---- Esto hay que dejarlo bien

  // :Sr HH:MM:SS#  -> Direccion RA del objetivo
  if(datos[0]==':' && datos[1]=='S' && datos[2]=='r'){
    for(int i=0;i<8;i++)
      RA_objetivo[i]=datos[i+4];                                    
    Serial.print("1");
    RA_obj=long(atoi(datos+4))*long(3600)+long(atoi(datos+7))*long(60)+long(atoi(datos+10));
    lcd.setCursor(0, 0);
    lcd.print(RA_objetivo);
  }
  
  // :Sd sDD*MM:SS# ->Direccion DEC del objetivo
  if(datos[0]==':' && datos[1]=='S' && datos[2]=='d'){
    for(int i=0;i<9;i++)
      DEC_objetivo[i]=datos[i+4];                                        
    Serial.print("1");
    DEC_obj=long(atoi(datos+4))*long(3600)+long(atoi(datos+8))*long(60)+long(atoi(datos+11));
    lcd.setCursor(0, 1);
    lcd.print(DEC_objetivo);
  }
  
  // :MS# -> Comenzar slew
  if(datos[0]==':' && datos[1]=='M' && datos[2]=='S' && datos[3]=='#'){
    Serial.print("0");                                                     // <<<---- Esto hay que dejarlo bien
  }
}

// I2C Address TEST 
bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) {
    return true;
  }
  return false;
}
