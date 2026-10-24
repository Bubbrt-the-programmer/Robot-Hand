#include <Arduino.h>
#include <Servo.h>

Servo indexFinger;
Servo middleFinger; // Create a servo object to control a servo
Servo ringFinger; // Create a servo object to control a servo
Servo pinkyFinger; // Create a servo object to control a servo
Servo thumb; // Create a servo object to control a servo

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud

  indexFinger.attach(9);
  middleFinger.attach(6); // Attach the servos to pins 9 and 10
  ringFinger.attach(5); // Attach the servo to pin 11
  pinkyFinger.attach(3); // Attach the servo to pin 12
  thumb.attach(11); // Attach the servo to pin 13

  indexFinger.write(0); // Attach the servo to pin 9 and move it to 0 degrees
  middleFinger.write(0); // Attach the servo to pin 10 and move it to 0 degrees
  ringFinger.write(0); // Attach the servo to pin 11 and move it to 0 degrees
  pinkyFinger.write(0); // Attach the servo to pin 12 and move it to 0 degrees
  thumb.write(0); // Attach the servo to pin 13 and move it to 0 degrees

  Serial.println("Servo control ready. Send '1, 2, 3, 4, 0' to move the respective fingers.");
}
void loop() {
 if (Serial.available() > 0) { // Check if data is available to read
    char incomingChar = Serial.read(); // Read the incoming byte

    if (incomingChar == '1') {
      indexFinger.write(180); // Move the servo to 180 degrees
      delay(1000); // Wait for 1 second
      indexFinger.write(0); // Move the servo back to 0 degrees
    }

    else if (incomingChar == '2') {
      middleFinger.write(180); // Move the servo to 180 degrees
      delay(1000); // Wait for 1 second
      middleFinger.write(0); // Move the servo back to 0 degrees
    }

    else if (incomingChar == '3') {
      ringFinger.write(180); // Move the servo to 180 degrees
      delay(1000); // Wait for 1 second
      ringFinger.write(0); // Move the servo back to 0 degrees
    }

    else if (incomingChar == '4') {
      pinkyFinger.write(180); // Move the servo to 180 degrees
      delay(1000); // Wait for 1 second
      pinkyFinger.write(0); // Move the servo back to 0 degrees
    }

    else if (incomingChar == '0') {
      thumb.write(180); // Move the servo to 180 degrees
      delay(1000); // Wait for 1 second
      thumb.write(0); // Move the servo back to 0 degrees
    }
  }
}