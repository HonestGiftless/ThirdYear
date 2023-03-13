#define trig 12
#define echo 11

#define lm_fb 4 // вперед назад
#define lm_s 5 // скорость
#define rm_fb 7 // вперед назад
#define rm_s 6 // скорость

const int side_sensor = A0; // левый датчик
long duration;
int cm;

bool fd = false;
bool bd = false;
bool rt = false;
bool lt = false;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);

  pinMode(lm_fb, OUTPUT);
  pinMode(lm_s, OUTPUT);
  pinMode(rm_fb, OUTPUT);
  pinMode(rm_s, OUTPUT);
}

void loop() {
  direct();
}

int check_fdist() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = duration / 58;

  return cm;
}

float check_ldist() {
  float volts = analogRead(side_sensor)*0.0048828125;
  float cm = 65*pow(volts, -1.10);

  return cm;
}

void change_condition() {
  int fd_cm = check_fdist();
  float lt_cm = check_ldist();

  if (fd_cm > 20) {
    fd = true;

    bd = false;
    rt = false;
    lt = false;
  } else if (fd_cm <= 20 && lt_cm > 22) {
    lt = true;

    fd = false;
    bd = false;
    rt = false;
  } else if (fd_cm <= 20 && lt_cm <= 22) {
    rt = true;

    fd = false;
    bd = false;
    lt = false;
  }
}

void stop() {
  digitalWrite(lm_fb, 0);
  digitalWrite(rm_fb, 0);
  analogWrite(lm_s, 0);
  analogWrite(rm_s, 0);
}

void direct() {
  if (fd) {
    digitalWrite(lm_fb, 0);
    digitalWrite(rm_fb, 0);
    analogWrite(lm_s, 200);
    analogWrite(rm_s, 250);
    delay(150);
    stop();
    delay(150);
  }
  if (lt) {
    digitalWrite(lm_fb, 1);
    digitalWrite(rm_fb, 0);
    analogWrite(lm_s, 200);
    analogWrite(rm_s, 250);
    delay(150);
    stop();
    delay(150);
  }
  if (rt) {
    digitalWrite(lm_fb, 0);
    digitalWrite(rm_fb, 1);
    analogWrite(lm_s, 200);
    analogWrite(rm_s, 250);
    delay(150);
    stop();
    delay(150);
  }
}
