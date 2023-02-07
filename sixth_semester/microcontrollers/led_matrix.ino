#define led_pin3 3
#define led_pin4 4
#define led_pin5 5
#define led_pin6 6

void setup() {
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
}

// обыкновенный копипаст, почему-то не включаются 1и3 и 2и4, пересобрать подключение надо

void loop() {
  // Первый светодиод
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  delay(500);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
  delay(500);

  // второй светодиод
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  delay(500);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
  delay(500);

  // третий светодиод
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  delay(500);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
  delay(500);

  // четвертый светодиод
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  delay(500);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
  delay(500);

  // первый и второй светодиоды
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  delay(500);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
  delay(500);

  // третий и четвертый светодиоды
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  delay(500);
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
  delay(500);
}
