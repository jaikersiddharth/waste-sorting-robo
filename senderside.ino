#include <Wire.h>
#include <AFMotor.h>

// Pin Definitions
const int irSensorPin = A1;            // IR sensor pin
const int triggerPin = 9;              // Ultrasonic sensor trigger pin
const int echoPin = 10;                // Ultrasonic sensor echo pin
const int inductiveSensorPin = 3;      // Inductive proximity sensor pin
const int motorPin1 = 5; // Connect to input 1 of the motor driver
const int motorPin2 = 6; 
const int motorPin3=;
const int motorPin4=;

// Object Types
enum ObjectType { METAL, GLASS, PLASTIC, UNKNOWN };

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(inductiveSensorPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

}

void loop() {
  // Read sensor data
  int irSensorValue = analogRead(irSensorPin);
  int inductiveSensorValue = digitalRead(inductiveSensorPin);
  int distance = measureDistance();

  // Send sensor data to receiver Arduino
  

  delay(1000); 
  
  // Adjust delay as needed
}

// Function to measure distance using ultrasonic sensor
int measureDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

// Function to determine object type based on sensor readings
ObjectType determineObjectType(int irValue, int inductiveValue, int distance) {
  if (irValue < 500 && distance < 10) {
    
    return PLASTIC;
  delay(2000);
   

  } else if (inductiveValue == LOW) {
     return METAL;
    
  }else {
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    delay(2000);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin2,HIGH);
    delay(2000);



   
  //}
}
