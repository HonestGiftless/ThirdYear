#include <Servo.h>

int trig_pin = 7;
int echo_pin = 6;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;


void setup() {
  Serial.begin (9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  myservo1.attach(8);
  myservo2.attach(9);
  myservo3.attach(10);
  myservo4.attach(11);
  
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);
  myservo4.write(0);
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
  

  // if (distance < 10) { // Пластик
  //   myservo4.write(0);
  //   myservo3.write(0);
  //   myservo2.write(0);
  //   myservo1.write(0);
  // }

  // if (distance < 10) { // Стекло
  //   myservo4.write(180);
  //   myservo3.write(0);
  //   myservo2.write(0);
  //   myservo1.write(0);
  // }

  // if (distance < 10) { // Металл
  //   myservo3.write(180);
  //   myservo2.write(0);
  //   myservo1.write(0);
  // }

}