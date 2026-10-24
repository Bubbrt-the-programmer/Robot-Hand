#include <Arduino.h>
#include <Servo.h>

Servo indexFinger;
Servo middleFinger; // Create a servo object to control a servo
Servo ringFinger; // Create a servo object to control a servo
Servo pinkyFinger; // Create a servo object to control a servo
Servo thumb; // Create a servo object to control a servo


struct FingerServo {
  Servo servo;
  int pin;
  char key;
  bool isExtended;
};

FingerServo fingers[] = {
  {Servo(), 9, '1', false},
  {Servo(), 6, '2', false},
  {Servo(), 5, '3', false},
  {Servo(), 3, '4', false},
  {Servo(), 11, '0', false}
};

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud

  int totalFingers = sizeof(fingers) / sizeof(fingers[0]);
  for (int i = 0; i < totalFingers; i++) {
    fingers[i].servo.attach(fingers[i].pin);
    fingers[i].servo.write(0); // Move the servo to 0 degrees 
  }
  Serial.println("Servo control ready. Send '1, 2, 3, 4, 0' to move the respective fingers.");
}

void loop() {
 if (Serial.available() > 0) { // Check if data is available to read
    char incomingChar = Serial.read(); // Read the incoming byte

    int totalFingers = sizeof(fingers) / sizeof(fingers[0]);

    for (int i = 0; i < totalFingers; i++) {
      if (incomingChar == fingers[i].key) {
        fingers[i].isExtended = !fingers[i].isExtended; // Toggle the state of the finger
        if (fingers[i].isExtended) {
          fingers[i].servo.write(180); // Move the servo to 180 degrees
        } else {
          fingers[i].servo.write(0); // Move the servo back to 0 degrees
        }
        break;
      }
    }
  }
}