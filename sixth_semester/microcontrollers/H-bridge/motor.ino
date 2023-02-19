#define pin_9 9
#define pin_10 10

void setup() {
  Serial.begin(9600);
  pinMode(pin_9, OUTPUT);
  pinMode(pin_10, OUTPUT);
}

void check_ds(char d, int s) {
  if (d == 'r' && s >= 0 && s <= 255) {
    analogWrite(pin_9, s);
    digitalWrite(pin_9, 0);
    digitalWrite(pin_10, 1);
    delay(2000);
  } else if (d == 'l' && s >= 0 && s <= 255) {
    analogWrite(pin_10, s);
    digitalWrite(pin_9, 1);
    digitalWrite(pin_10, 0);
    delay(2000);
  } else if (d == 's' || s < 0 || s > 255) {
    analogWrite(pin_9, 0);
    analogWrite(pin_10, 0);
    digitalWrite(pin_9, 1);
    digitalWrite(pin_10, 1);
    delay(2000);
  }
}

void loop() {
  check_ds('r', 255);
  check_ds('l', -2);
  check_ds('l', 100);
  check_ds('s', 0);
}