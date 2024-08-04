#include "Servo.h"

// Define pin numbers for ultrasonic sensors, motors
#define trigPin1 2
#define echoPin1 3
#define motor1 1
#define trigPin2 6
#define echoPin2 7
#define motor2 8
#define trigPin3 10
#define echoPin3 11
#define motor3 12

Servo bakservo;
signed int pos = 0; // Variable to store the servo position
int degree = 60;
int flag = 0;
long duration, distance, UltraSensor1, UltraSensor2, UltraSensor3;

void setup() {
  bakservo.attach(4);
  bakservo.write(pos);
  delay(1500);
  Serial.begin(9600);

  // Initialize pin modes
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(motor2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(motor3, OUTPUT);

  // Set initial states for motors
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
}

void loop() {
  // Read distances from ultrasonic sensors
  SonarSensor(trigPin1, echoPin1);
  UltraSensor1 = distance;
  SonarSensor(trigPin2, echoPin2);
  UltraSensor2 = distance;
  SonarSensor(trigPin3, echoPin3);
  UltraSensor3 = distance;

  // Control the servo motor's oscillation
  if (pos == degree && flag == 0) {
    flag = 1;
  }
  if (pos <= degree && flag == 0) {
    bakservo.write(pos);
    pos += 2;
    delay(90);
  } else if (flag == 1) {
    if (pos > 0) {
      bakservo.write(pos);
      pos -= 2;
      delay(90);
    } else {
      flag = 0;
    }
  }

  // Control motors based on sensor readings
  if (UltraSensor1 <= 70) {
    digitalWrite(motor1, HIGH);
  } else {
    digitalWrite(motor1, LOW);
  }
  
  if (UltraSensor2 <= 70) {
    digitalWrite(motor2, HIGH);
  } else {
    digitalWrite(motor2, LOW);
  }
  
  if (UltraSensor3 <= 70) {
    digitalWrite(motor3, HIGH);
  } else {
    digitalWrite(motor3, LOW);
  }
}

void SonarSensor(int trigPinSensor, int echoPinSensor) {
  // Send a pulse to the sensor
  digitalWrite(trigPinSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor, LOW);

  // Read the pulse duration
  duration = pulseIn(echoPinSensor, HIGH);

  // Calculate the distance
  distance = (duration / 2) / 29.1;
}
