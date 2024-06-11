#include <AFMotor.h>

// Define motor shield object for motor 1 and motor 2
AF_DCMotor motor1(1); // Motor 1
AF_DCMotor motor2(2); // Motor 2

// Define pin for the external motor connected through motor driver
const int externalMotorPin = 3; // Example pin, change it to your actual pin

void setup() {
  Serial.begin(9600); // Initialize serial communication
  
  // Set up the external motor pin as output
  pinMode(externalMotorPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Read data from sender Arduino
    String data = Serial.readStringUntil('\n');
    int irValue = data.substring(0, data.indexOf(',')).toInt();
    int inductiveValue = data.substring(data.indexOf(',') + 1, data.lastIndexOf(',')).toInt();
    int distance = data.substring(data.lastIndexOf(',') + 1).toInt();
    
    // Print received values on serial monitor
    Serial.print("IR Value: ");
    Serial.println(irValue);
    Serial.print("Inductive Value: ");
    Serial.println(inductiveValue);
    Serial.print("Distance: ");
    Serial.println(distance);

    if (irValue < 500 && distance < 10) {
      
    //return GLASS;
    digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(2000);
   digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);

  } else if (inductiveValue == HIGH) {
    return METAL;
  } else {
    return PLASTIC;
  }

  }
}
