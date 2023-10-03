
#include "LiquidCrystal_I2C.h"
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
String stringOne = "";
void loop() {
  if (Serial.available()){
    while (Serial.available()>0){ 
      char a=Serial.read();            // Stores current byte
      stringOne += String(a);          // Append current Byte to message String
      delay(5);
    }
    if (stringOne == "#:GR#"){         // if command received = get RA do...
      Serial.print ("00");             //AR: 00h
      Serial.print (":");
      Serial.print ("00");             //AR: 00m
      Serial.print (":");
      Serial.print ("00");             //AR: 00s
      Serial.print ("#");  
      lcd.setCursor(0, 0);
      lcd.print(stringOne);
    }
    if (stringOne == "#:GD#"){         // if command received = get DEC do...
      Serial.print ("+");                  //DEC
      Serial.print ("70");                 //DEC: 45° (grados)
      Serial.print ((char)223);            //°
      Serial.print ("00");                 //DEC: 00' (min)
      Serial.print (":");
      Serial.print ("00");                 //DEC: 00''(sec) 
      Serial.print ("#");
      lcd.setCursor(6, 0);
      lcd.print(stringOne);
    }


    
    stringOne = "";
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
