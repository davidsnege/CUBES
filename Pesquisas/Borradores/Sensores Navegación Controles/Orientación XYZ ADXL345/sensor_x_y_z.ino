/*

Usos y descripción:

  Usar para controlar las superficies de control aerodinãmicas del cohete en un primer momento.
  Usar para controlar el empuje vectorizado del motor del cohete.
  Usar para controlar motores en modo giroscopio para el satelite en el objectivo final.
  Copilar datos de testeos, verificar el uso del componente en 0G o huir a una alternativa viable.

*/


/*Conexiones de pines I2C de ADXL345 para Arduino

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


/*Incluimos las librerias que vamos a utilizar*/
#include <Wire.h>
#include <ADXL345.h>
#include <Servo.h>

/*Creamos los obtectos de controle para los servos en cada eje instanciados de la libreria Servo*/
Servo servoX;
Servo servoY;
Servo servoZ;

/*Creamos el objecto del sensor de ejes instanciados de la libreria adxl*/
ADXL345 adxl;

/*Creamos las variables que vamos usar para los controles*/
int x, y, z;
int rawX, rawY, rawZ;
int mappedRawX, mappedRawY, mappedRawZ;

/*En el setup inicializamos la serial, encendemos el sensor, atachamos los pines de los servos*/
void setup() {
  Serial.begin(9600);
  adxl.powerOn();
  servoX.attach(11);
  servoY.attach(10);
  servoZ.attach(9);
  servoZ.write(0);
}

/*Iniciamos nuestro blucle*/
void loop() {
  /*Empezamos leyendo los datos del acelerometro en todos ejes y armazenando en las variables*/
  adxl.readAccel(&x, &y, &z);
  
  /*Redefinimos valores para variables Raw y asi los podemos tratar sin cambiar el valor incial*/
  rawX = x ;
  rawY = y ;
  rawZ = z ;
 
  /*Hacemos unas conversiones llevando en consideración que nuestro acelerometro debe estar en 0,0,0 recto*/
  if (rawX < -255) rawX = -255; else if (rawX > 255) rawX = 255;
  if (rawY < -255) rawY = -255; else if (rawY > 255) rawY = 255;
  if (rawZ < -255) rawZ = -255; else if (rawZ > 255) rawZ = 255;

  /*Si nececitamos la lectura por serial usamos esto*/
//  Serial.print(" rawX = "); Serial.print(rawX);
//  Serial.print(" rawY = "); Serial.print(rawY);
//  Serial.print(" rawZ = "); Serial.println(rawZ);

  /*Hacemos el map para convertir en movimientos y limitar los angulos de los servos*/ 
  mappedRawX = map(rawX, -255, 255, 0, 90) + 54;
  mappedRawY = map(rawY, -255, 255, 0, 180) + 22;
  mappedRawZ = map(rawZ, -255, 255, -100, 100) -94;

  /*Si nececitamos la lectura por serial usamos esto*/
//    Serial.print(" mappedRawX = "); Serial.println(mappedRawX); // trate data with offset
//    Serial.print(" mappedRawY = "); Serial.println(mappedRawY); // trate data with offset
//    Serial.print(" mappedRawZ = "); Serial.println(mappedRawZ); // trate data with offset
//    Serial.print(" ServoX = ");Serial.println(servoX.read());
//    Serial.print(" ServoY = ");Serial.println(servoY.read());

  /*Movemos los servos a las posiciones mapeadas constantemente por el bucle*/  
  servoX.write(180 - mappedRawX);
  servoY.write(180 - mappedRawY);

  /*Este tiempo puede ser cambiado dependiendo de la respuesta del sensor y de la mecanica necesária*/
  delay(300);

  /*Aqui definimos que nuestro eje Z va ser el que abre el sistema de paracaidas
    Si detecta que se inclino el eje Y por ejemplo y podemos añadir que si detecta una 
    fuerza G negativo en el eje Z se activa 
    (para uso en producción se remove el else o se cambia las condiciones) 
  */
  if(servoY.read() > 120 || servoY.read() < 25){
    servoZ.write(180);
  }else{
    servoZ.write(0);
  }
  
  /*Usamos para debug de graficos en el monitor de arduino*/
  Serial.print(" mappedRawX = "); Serial.print(mappedRawX);
  Serial.print(" mappedRawY = "); Serial.println(mappedRawY);
}

/* 

Lo mas complicadod de usar esto es hasta el momento la mecánica de partes 
por no poseer herramientas adequadas o recursos para aquisición de los 
materiales correctos esto se ha podido testear en un modo muy precario hasta
este momento, si en el futuro tenemos otras posibilidades remover este comentário.

*/