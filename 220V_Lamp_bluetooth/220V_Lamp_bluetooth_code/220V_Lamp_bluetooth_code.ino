#include <SoftwareSerial.h>

// Define software serial for Bluetooth communication
SoftwareSerial BTSerial(10, 11); // (RX, TX) - Arduino's RX on 10, TX on 11

#define RELAY_PIN 5  // Pin controlling the transistor

char receivedChar;

void setup() {
    Serial.begin(9600);  // Serial Monitor
    BTSerial.begin(9600); // Bluetooth HC-05 communication
    pinMode(RELAY_PIN, OUTPUT);
    
    digitalWrite(RELAY_PIN, LOW); // Relay OFF initially
}

void loop() {
    if (BTSerial.available()) { // Check if Bluetooth data is received
        receivedChar = BTSerial.read(); // Read the received character
        
        if (receivedChar == '1') { // Turn ON the lamp
            digitalWrite(RELAY_PIN, HIGH);
            
            Serial.println("Lamp ON");
        }
        else if (receivedChar == '0') { // Turn OFF the lamp
            digitalWrite(RELAY_PIN, LOW);
            
            Serial.println("Lamp OFF");
        }
    }
}
