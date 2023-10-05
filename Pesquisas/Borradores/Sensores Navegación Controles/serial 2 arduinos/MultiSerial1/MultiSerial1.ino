/*
Comunicación de 2 arduinos por puerto I2C (Serial) interno de Arduino.
*/

/*El Setup Inicializa la Serial*/
void setup() {
  Serial.begin(9600);
}

/*El Bucle*/
void loop() {

  /*No hay secretos, si la Serial esta iniciada, es como enviar algo con write*/

  if(Serial.available()){
    
    /*Escribimos Ola*/
    Serial.write("Ola");
  }

  /*El tiempo Delay no es necesário pero prudente*/
  delay(500);


}
