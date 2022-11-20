#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Hello");

  mySerial.begin(9600);
  while (!mySerial) {}
  mySerial.println("World");
}

void loop() {
  if (mySerial.available()){
    Serial.write(mySerial.read());
  }
  if (Serial.available()){
    mySerial.write(Serial.read());
  }
}
