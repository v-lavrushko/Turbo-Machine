#include <AFMotor.h>
double duration;
int distance;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  // turn on motor
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}

void loop() {
  void forward() {  
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  void stap() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  delayMicroseconds(1);
  duration = pulseIn(8, HIGH);
  distance = duration * 0.034 / 2;
  if ( distance < 5) {
    stap()
  }
  else {
    forward()
  }
}
