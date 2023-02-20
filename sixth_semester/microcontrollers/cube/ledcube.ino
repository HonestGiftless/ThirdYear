#define led_pin1 7
#define led_pin2 2
#define led_pin3 3
#define led_pin4 4
#define led_pin5 5
#define led_pin6 6

void setup() {
  Serial.begin(9600);
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
}

void loop() {
  String led_num = Serial.readString();
  choice(led_num);
}

void choice(String led) {
  if (led == "1") {
    digitalWrite(led_pin1, 1);
    digitalWrite(led_pin2, 0);
    digitalWrite(led_pin3, 0);
    digitalWrite(led_pin4, 0);
    digitalWrite(led_pin5, 0);
    digitalWrite(led_pin6, 1);
    delay(1500);
  } else if (led == "2") {
    digitalWrite(led_pin1, 0);
    digitalWrite(led_pin2, 1);
    digitalWrite(led_pin3, 0);
    digitalWrite(led_pin4, 0);
    digitalWrite(led_pin5, 0);
    digitalWrite(led_pin6, 1);
  } else if (led == "3") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "4") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "5") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "6") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "7") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "8") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "12") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "14") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "15") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 0);
  } else if (led == "123") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "1234") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "12345678") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 0);
  } else if (led == "23") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "26") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 0);
  } else if (led == "34") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 1);
  } else if (led == "56") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "58") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "67") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "78") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "37") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 0);
  } else if (led == "48") {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 0);
  } else if (led == "567") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "5678") {
      digitalWrite(led_pin1, 1);
      digitalWrite(led_pin2, 1);
      digitalWrite(led_pin3, 1);
      digitalWrite(led_pin4, 1);
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin6, 0);
  } else if (led == "diagonal") {
      int dtime= 100;
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin2, 1);
      delay(dtime);

      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin2, 0);
      delay(dtime);

      // 1
      digitalWrite(led_pin6, 1);
      digitalWrite(led_pin3, 1);
      delay(dtime);

      digitalWrite(led_pin6, 0);
      digitalWrite(led_pin3, 0);
      delay(dtime);

      //2
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin4, 1);
      delay(dtime);

      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin4, 0);

      //3
      digitalWrite(led_pin6, 1);
      digitalWrite(led_pin1, 1);
      delay(dtime);

      digitalWrite(led_pin6, 0);
      digitalWrite(led_pin1, 0);
      delay(dtime);
      
      // 0
      digitalWrite(led_pin6, 1);
      digitalWrite(led_pin2, 1);
      delay(dtime);

      digitalWrite(led_pin6, 1);
      digitalWrite(led_pin2, 1);
      delay(dtime);
      // 1
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin3, 1);
      delay(dtime);
      
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin3, 0);
      delay(dtime);

      // 2
      digitalWrite(led_pin6, 1);
      digitalWrite(led_pin4, 1);
      delay(dtime);
      
      digitalWrite(led_pin6, 0);
      digitalWrite(led_pin4, 0);
      delay(dtime);
      
      // 3
      digitalWrite(led_pin5, 1);
      digitalWrite(led_pin1, 1);
      delay(dtime);
      // 4
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin1, 0);
  } else {
      digitalWrite(led_pin1, 0);
      digitalWrite(led_pin2, 0);
      digitalWrite(led_pin3, 0);
      digitalWrite(led_pin4, 0);
      digitalWrite(led_pin5, 0);
      digitalWrite(led_pin6, 0);
      Serial.println('Unknown value');
  }
}
