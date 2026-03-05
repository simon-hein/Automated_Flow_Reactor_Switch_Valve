// Stepper motor control via serial communication
// ----------------------------------------------
// This program receives commands via the serial connection and rotates a stepper 
// motor either +60° or -60° with a speed of 40 RPM depending on the received value.
// '1' -> rotate clockwise
// '0' -> rotate counterclockwise


// Include the Arduino_RouterBridge library to enable serial communication via Monitor
#include <Arduino_RouterBridge.h>


// Pin connections for the stepper motor driver
const int dirPin = 2;  // Direction pin
const int stepPin = 3;  // Step pin

int val;  // Variable for storing the received command


void setup() {

  // Configure motor control pins
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  // Set direction of rotation to clockwise
  digitalWrite(dirPin, HIGH);

  // Initialize serial communication with the computer
  Monitor.begin(19200);  // Must match to baudrate used in python script
  Monitor.flush();

}


void loop() {

  // Check if data is available from the serial connection
  if(Monitor.available() > 0) {

    // Read incoming character and convert it to an integer (0 or 1)
    val = char(Monitor.read())-'0';


    // Rotate motor clockwise (+60°)
    // -----------------------------
    if(val == 1) {

      Monitor.println("Rotation +");

      // Perform required number of steps: 33 * 1.8° ≈ 60°
      // Time per step: 7.5 ms
      for(int i = 0; i < 33; i++) {
        
        digitalWrite(dirPin, HIGH);  // Set clockwise direction
        
        digitalWrite(stepPin, HIGH);  // Make one step (1.8°)
        delayMicroseconds(3750);

        digitalWrite(stepPin, LOW);  // Pause before taking next step (total delay: 7.5 ms)
        delayMicroseconds(3750);
      }
    }

    
    // Rotate motor counterclockwise (-60°)
    // ------------------------------------
    if(val == 0) {

      Monitor.println("Rotation -");

      // Perform required number of steps: 33 * -1.8° ≈ -60°
      // Time per step: 7.5 ms
      for(int i = 0; i < 33; i++) {
        
        digitalWrite(dirPin, LOW);  // Set counterclockwise direction
        
        digitalWrite(stepPin, HIGH);  // Make one step (1.8°)
        delayMicroseconds(3750);
        
        digitalWrite(stepPin, LOW);  // Pause before taking next step (total delay: 7.5 ms)
        delayMicroseconds(3750);
      }
    }

  }

}