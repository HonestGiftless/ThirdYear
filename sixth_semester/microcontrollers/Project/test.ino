#include <Servo.h>

#define trigPin 12
#define echoPin 11

const int indPin = 2;
long duration, cm;

bool item = false;
bool hasMetall = false;

Servo cap;
Servo separator;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(indPin, INPUT);

  cap.attach(4);
  separator.attach(5);

  cap.write(90); // определить состояние, в котором будет мотор крышки
  separator.write(45); // определить состояние, в котором будет мотор разделения мусора
}
 
void loop() {
  takeObject();
  checkMetall(item);

  if (item && separator) {
    cap.write(0);
  }
}

void takeObject() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 2) / 29.1;

  Serial.print(cm);

  delay(250);

  if (cm < 140) {
    item = true;
  } else {
    item = false;
  }
}

void checkMetall(bool itm) {
  int sensorValue = digitalRead(indPin);

  if (itm) {
    if (sensorValue==LOW) {
      hasMetall = true;
      separator.write(90);
    } else {
      hasMetall = false;
      separator.write(0);
    }
  } else {
    hasMetall = false;
  }
}