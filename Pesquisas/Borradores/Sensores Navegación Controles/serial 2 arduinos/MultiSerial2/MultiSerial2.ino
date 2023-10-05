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
    
    /*Se puede tratar de muchos modos lo que recibimos este es uno de ellos 
    armazenando en una variable tipo char lo que se lee en la Serial y después
    escribindo en la propria serial, en este caso poderiamos contestar con otra
    cosa o un retorno de función*/
    char data_received = Serial.read();
    Serial.write(data_received);
  }

  /*El tiempo Delay no es necesário pero prudente*/  
  delay(500);


}
