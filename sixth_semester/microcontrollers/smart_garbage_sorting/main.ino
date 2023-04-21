#include <Servo.h>

int trig_pin = 7;
int echo_pin = 6;
Servo myservo1;
Servo myservo2;
Servo myservo3;

bool opened_lid = false;

void setup() {
  Serial.begin (9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
}

void loop() {
  int duration, distance;
  digitalWrite(trig_pin, 0);
  delayMicroseconds(2);

  digitalWrite(trig_pin, 1);
  delayMicroseconds(10);

  digitalWrite(trig_pin, 0);
  duration = pulseIn(echo_pin, HIGH);

  distance = duration / 58;

  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);

  if (distance < 10) {
    myservo1.write(0);
  } else {
    myservo1.write(90);
  }
}
