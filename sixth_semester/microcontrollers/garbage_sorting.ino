#include <Servo.h>

const int iPin = 2;

int trigPin = 9;
int echoPin = 8;

int duration, cm;

bool hasMtl;

Servo capServo;
Servo sepServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(iPin, INPUT);
  capServo.attach(13);
  sepServo.attach(12);
  capServo.write(0);
  sepServo.write(0);
}

void loop() {
  hasObject();

  if (cm < 7) {
    hasMetall();
    if (hasMtl) {
      delay(1000);
      Serial.println("Metall");
      sepServo.write(90);
      delay(2500);
      capServo.write(180);
    } else {
      delay(1000);
      Serial.println("Other");
      sepServo.write(0);
      delay(2500);
      capServo.write(180);
    }
  } else {
    Serial.println("No object");
    delay(3000);
    capServo.write(0);
  }
}

void hasObject() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = duration / 58;
  delay(1000);
  return cm;
}

void hasMetall() {
  int sensVal = digitalRead(iPin);

  if (sensVal == HIGH) {
    hasMtl = false;
  } else {
    hasMtl = true;
  }

  return hasMtl;
}
