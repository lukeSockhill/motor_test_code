//yolo
#include <AFMotor.h>
#include <Servo.h> 

// DC motor on M2
AF_DCMotor motor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  // turn on motor #2
  motor.setSpeed(200);
  motor.run(RELEASE);
}

int i;

// Test the DC motor
void loop() {
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(3);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(3);
 }
 
  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(3);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(3);
 }
}
