void setup() { 
    // Connect with Arduino by COM use protocol Lx200
    Serial.begin(9600);
}

void loop() {
    // Send command to Arduino
    Serial.println("Gt");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gg");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gd");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gr");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gp");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gm");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gf");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gc");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }

    // Send command to Arduino
    Serial.println("Gk");
    delay(1000);

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);
    }
    
    // Send command to Arduino
    Serial.println("Gv");

    // Read response from Arduino
    while (Serial.available()) {
        char c = Serial.read();
        Serial.print(c);

        // If response is "1" then the telescope is tracking
        if (c == '1') {
            Serial.println("Tracking");
        }
        
        // If response is "0" then the telescope is not tracking
        if (c == '0') {
            Serial.println("Not Tracking");
        }

        // If response is "2" then the telescope is slewing
        if (c == '2') {
            Serial.println("Slewing");
        }

        // If response is "3" then the telescope is not tracking and not slewing
        if (c == '3') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "4" then the telescope is not tracking and not slewing
        if (c == '4') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "5" then the telescope is not tracking and not slewing
        if (c == '5') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "6" then the telescope is not tracking and not slewing
        if (c == '6') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "7" then the telescope is not tracking and not slewing
        if (c == '7') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "8" then the telescope is not tracking and not slewing
        if (c == '8') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "9" then the telescope is not tracking and not slewing
        if (c == '9') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "a" then the telescope is not tracking and not slewing
        if (c == 'a') {
            Serial.println("Not Tracking and Not Slewing");
        }

        // If response is "b" then the telescope is not tracking and not slewing
        if (c == 'b') {
            Serial.println("Not Tracking and Not Slewing");
        }

    }

    // Send command to Arduino
    Serial.println("Gt");
    delay(1000);

    // Read response from Arduino

}