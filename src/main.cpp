#include <Arduino.h>
#include <Servo.h>

Servo indexFinger;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  indexFinger.attach(9);
  indexFinger.write(0); // Attach the servo to pin 9 and move it to 0 degrees
}
void loop() {
 if (Serial.available() > 0) { // Check if data is available to read
    char incomingChar = Serial.read(); // Read the incoming byte
    if (incomingChar == '1') {
      indexFinger.write(180); // Move the servo to 180 degrees
      delay(1000); // Wait for 1 second
      indexFinger.write(0); // Move the servo back to 0 degrees
    }
  }
}