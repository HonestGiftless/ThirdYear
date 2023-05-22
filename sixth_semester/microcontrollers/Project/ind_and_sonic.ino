#define trigPin 12
#define echoPin 11

const int indPin = 2;
long duration, cm;

bool item = false;
bool hasMetall = false;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(indPin, INPUT);
}
 
void loop() {
  takeObject();
  checkMetall(item);
  if (item && hasMetall) {
    Serial.print('YEEEEP');
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

  delay(250);

  if (cm < 140) { // 140 нужно заменить на значение, исходя из конструкции
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
    } else {
      hasMetall = false;
    }
  } else {
    hasMetall = false;
  }
}
