#include <Servo.h>

Servo azimutServo;
Servo elevacionServo;

void setup() {
  azimutServo.attach(9); // Pin para el servo de azimut
  elevacionServo.attach(10); // Pin para el servo de elevación
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int azimut = Serial.parseInt();
    int elevacion = Serial.parseInt();
    
    azimutServo.write(azimut); // Mover servo de azimut
    elevacionServo.write(elevacion); // Mover servo de elevación
  }
}




-----------------------------------------------------------------

#include <Servo.h>

Servo azimutServo;
Servo elevacionServo;

void setup() {
  azimutServo.attach(9); // Pin para el servo de azimut
  elevacionServo.attach(10); // Pin para el servo de elevación
  Serial.begin(9600); // Iniciar comunicación serial a 9600 baudios
}

void loop() {
  if (Serial.available() > 0) {
    String mensaje = Serial.readStringUntil('\n'); // Leer el mensaje hasta encontrar un salto de línea
    
    // Dividir el mensaje en las partes de azimut y altitud
    int separadorIndex = mensaje.indexOf(',');
    if (separadorIndex != -1) {
      String azimutStr = mensaje.substring(0, separadorIndex);
      String elevacionStr = mensaje.substring(separadorIndex + 1);
      
      // Convertir las cadenas en números
      int azimut = azimutStr.toInt();
      int elevacion = elevacionStr.toInt();
      
      // Mover los servo motores a las posiciones recibidas
      azimutServo.write(azimut);
      elevacionServo.write(elevacion);
    }
  }
}

Conversiones
--------------------------------------------------------------
Az = arctan(sin(HA) / (cos(HA) * sin(Lat) - tan(DEC) * cos(Lat)))

// Donde:

//     HA es la hora angular (en radianes).
//     Lat es la latitud del lugar de observación (en radianes).
//     DEC es la declinación (en radianes).

// Altitud (Alt): Es el ángulo vertical que mide la elevación del objeto sobre el horizonte y se calcula mediante la fórmula:

Alt = arcsin(sin(Lat) * sin(DEC) + cos(Lat) * cos(DEC) * cos(HA))

// La hora angular (HA) se refiere al ángulo horario, que cambia con el tiempo y la ubicación. Para calcularla, puedes usar la hora local y la ascensión recta (RA) del objeto astronómico:

HA = LST - RA

// Donde:

//     LST es el tiempo sidéreo local, que depende de la hora local y la longitud del lugar de observación.
//     RA es la ascensión recta (en radianes).

// Convertir horas a radianes:

// Para realizar los cálculos anteriores, es importante convertir las horas en radianes. Utiliza la siguiente fórmula:

Radianes = Horas * (π / 12)

//     Donde π (pi) es aproximadamente 3.14159265359.

// Ten en cuenta que estos cálculos son simplificados y no tienen en cuenta factores como la precesión de los equinoccios, la refracción atmosférica, etc. Además, Stellarium podría proporcionar valores en grados, por lo que es importante convertirlos a radianes antes de realizar estos cálculos.

// Este es un proceso bastante matemático y requiere un conocimiento sólido de trigonometría y astronomía. También, debes asegurarte de que las unidades de medida (grados o radianes) sean consistentes en todo el proceso de cálculo. Si no te sientes cómodo con estas conversiones, podría ser útil buscar recursos adicionales o consultar con alguien con experiencia en astronomía o matemáticas aplicadas.
