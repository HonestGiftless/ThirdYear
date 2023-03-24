#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);

#define lm_fb 4 // вперед назад
#define lm_s 5 // скорость
#define rm_fb 7 // вперед назад
#define rm_s 6 // скорость

bool fd = false;
bool rt = false;
bool lt = false;
bool st = false;

char direction = 's';

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);

  pinMode(lm_fb, OUTPUT);
  pinMode(lm_s, OUTPUT);
  pinMode(rm_fb, OUTPUT);
  pinMode(rm_s, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    change_condition(incomingChar);
    direct();
  }
}

void change_condition(char incomingChar) {
  if (mySerial.available() > 0) {
  }
  if (incomingChar == 'f') {
    fd = true;

    rt = false;
    lt = false;
    st = false;
  } else if (incomingChar == 'l') {
    lt = true;

    fd = false;
    rt = false;
    st = false;
  } else if (incomingChar == 'r') {
    rt = true;

    fd = false;
    lt = false;
    st = false;
  } else if (incomingChar == 's') {
    st = true;

    fd = false;
    rt = false;
    lt = false;
  }
}

void direct() {
  if (fd) {
    digitalWrite(lm_fb, 1);
    digitalWrite(rm_fb, 0);
    analogWrite(lm_s, 200);
    analogWrite(rm_s, 250);
  }
  if (lt) {
    digitalWrite(lm_fb, 0);
    digitalWrite(rm_fb, 0);
    analogWrite(lm_s, 200);
    analogWrite(rm_s, 250);
  }
  if (rt) {
    digitalWrite(lm_fb, 1);
    digitalWrite(rm_fb, 1);
    analogWrite(lm_s, 250);
    analogWrite(rm_s, 200);
  }
  if (st) {
    digitalWrite(lm_fb, 0);
    digitalWrite(rm_fb, 0);
    analogWrite(lm_s, 0);
    analogWrite(rm_s, 0);
  }
}
