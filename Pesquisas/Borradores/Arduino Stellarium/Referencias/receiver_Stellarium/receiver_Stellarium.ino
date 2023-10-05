
#include "LiquidCrystal_I2C.h"
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);

String inputString = "";                   //dichiaro una stringa vuota per memorizzare i dati in entrata

char input[20];
char txAR[10];
char txDEC[11];

String POSARC;
String POSDEC;

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

void loop() {
    // IN CHAR  -----------------
    while (Serial.available()>0){         // ottiene byte in entrata
      char inChar = Serial.read();         // legge il byte e lo memorizza nella variabile inChar
      inputString += String(inChar);       // aggiunge il byte corrente a inputString
      delay(5);
    }
    
    // GR AR -------------------
    if (inputString == "#:GR#"){           // se il comando ricevuto da stellarium è #:GR# (coordinata di AR)
      Serial.print ("00");                 // invia a stellarium il valore della coordinata AR: 00h
      Serial.print (":");
      Serial.print ("00");                 // invia a stellarium il valore della coordinata AR: 00m
      Serial.print (":");
      Serial.print ("00");                 // invia a stellarium il valore della coordinata AR: 00s
      Serial.print ("#");
      // POS -----
       int iA = 0;
        delay(5);
        while (iA < 20) {
          input[iA++] = Serial.read();
          delay(5);
          if(input[iA] != 0){
            POSARC = input[iA];
          }
          iA++;
        }      
      // POS -----
      lcd.setCursor(0, 1);
      lcd.print(inputString);
      lcd.setCursor(6, 1);
      lcd.print(POSARC);
      delay(500);
      iA = 0;
      inputString = "";   
    }
    // GD DEC ------------------
    if (inputString == "#:GD#"){           // se il comando ricevuto da stellarium è #:GD# (coordinata di DEC)   
      Serial.print ("+");                  // invia a stellarium il segno della coordinata DEC
      Serial.print ("45");                 // invia a stellarium il valore della coordinata DEC: 45°
      Serial.print ((char)223);            // char(223) si usa al posto di * per indicare il grado ° altrimenti ci sarà un errore nel file di log.
      Serial.print ("00");                 // invia a stellarium il valore della coordinata DEC: 00'
      Serial.print (":");
      Serial.print ("00");                 // invia a stellarium il valore della coordinata DEC: 00''
      Serial.print ("#");
      // POS -----
       int iD = 0;
        delay(5);
        while (iD < 20) {
          input[iD++] = Serial.read();
          delay(5);
          if(input[iD] != 0){
            POSDEC = input[iD];
          }
          iD++;
        }
      // POS -----
      lcd.setCursor(0, 0);
      lcd.print(inputString);
      lcd.setCursor(6, 0);
      lcd.print(POSDEC);
      delay(500);      
      iD = 0;
      inputString = "";                    // cancella la stringa
    }
    // Reset CURSOR  ----------
     lcd.setCursor(0, 1);
     lcd.print("");

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
