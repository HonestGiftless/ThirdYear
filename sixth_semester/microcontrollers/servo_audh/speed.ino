#define motor_pin 10

void setup() {
  pinMode(motor_pin, OUTPUT);
}

void loop() {
  for(int vel=0; vel <= 255; vel++) {
    analogWrite(motor_pin, vel);
    delay(10);
  }
}
