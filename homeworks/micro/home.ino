#define sensor_pin A2

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int val = analogRead(sensor_pin);
  Serial.println(val);
  delay(10);
  if (val < 850){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}
