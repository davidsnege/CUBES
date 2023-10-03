// Watch video here: https://www.youtube.com/watch?v=U0hJBc1Ppv4

/*Usos y descripción
* Usar para controlar las superficies de control aerodinãmicas del cohete en un primer momento.
* Usar para controlar el empuje vectorizado del motor del cohete.
* Usar para controlar motores en modo giroscopio para el satelite en el objectivo final.
* Copilar datos de testeos, verificar el uso del componente en 0G o huir a una alternativa viable.
*/


/*
Accelerometer connection pins (I2C) to Arduino are shown below:

Arduino     Accelerometer ADXL345
  A5            SCL
  A4            SDA
  3.3V          CS
  3.3V          VCC
  GND           GND
  
Arduino     Servo No. 1
  5V          5V  (Red Wire)
  GND         GND (Black Wire)
  D5          (last wire for control - might be white color)
  
Arduino     Servo No. 2
  5V          5V  (Red Wire)
  GND         GND (Black Wire)
  D6          (last wire for control - might be white color)
*/


/*The first way to controll rockets and parachutes command*/

#include <Wire.h>
#include <ADXL345.h>

#include <Servo.h>

Servo servoX;  // create servo object to control a servo
Servo servoY;
Servo servoZ;

ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

int x, y, z;
int rawX, rawY, rawZ;
int mappedRawX, mappedRawY, mappedRawZ;

void setup() {
  Serial.begin(9600);
  adxl.powerOn();
  servoX.attach(11);
  servoY.attach(10);
  servoZ.attach(9);
  servoZ.write(0);
}

void loop() {
  adxl.readAccel(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z

  rawX = x ;
  rawY = y ;
  rawZ = z ;
 
  if (rawX < -255) rawX = -255; else if (rawX > 255) rawX = 255;
  if (rawY < -255) rawY = -255; else if (rawY > 255) rawY = 255;
  if (rawZ < -255) rawZ = -255; else if (rawZ > 255) rawZ = 255;

//  Serial.print(" rawX = "); Serial.print(rawX); // raw data with offset
//  Serial.print(" rawY = "); Serial.print(rawY); // raw data with offset
//  Serial.print(" rawZ = "); Serial.println(rawZ); // raw data with offset
   
  mappedRawX = map(rawX, -255, 255, 0, 90) + 54;
  mappedRawY = map(rawY, -255, 255, 0, 180) + 22;
  mappedRawZ = map(rawZ, -255, 255, -100, 100) -94;

//    Serial.print(" mappedRawX = "); Serial.println(mappedRawX); // trate data with offset
//    Serial.print(" mappedRawY = "); Serial.println(mappedRawY); // trate data with offset
//    Serial.print(" mappedRawZ = "); Serial.println(mappedRawZ); // trate data with offset

//    Serial.print(" ServoX = ");Serial.println(servoX.read());
//    Serial.print(" ServoY = ");Serial.println(servoY.read());
  
  servoX.write(180 - mappedRawX);
  servoY.write(180 - mappedRawY);
  delay(300);

// SECURE PARACHUTE SYSTEM (remove else for prod)
  if(servoY.read() > 120 || servoY.read() < 25){
    servoZ.write(180);
  }else{
    servoZ.write(0);
  }
  
  Serial.print(" mappedRawX = "); Serial.print(mappedRawX); // raw data with offset
  Serial.print(" mappedRawY = "); Serial.println(mappedRawY); // raw data with offset
}
