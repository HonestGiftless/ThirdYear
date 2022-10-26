#define PLUS_BUTTON   2
#define MINUS_BUTTON  4

int brightness = 100;
boolean plusUp = true;
boolean minusUp = true;
 
void setup() {
   pinMode(10, OUTPUT);
   pinMode(PLUS_BUTTON, INPUT_PULLUP);
   pinMode(MINUS_BUTTON, INPUT_PULLUP);
}
 
void loop() {
   analogWrite(10, brightness);
  
   plusUp = handleClick(PLUS_BUTTON, plusUp, +10);
   minusUp = handleClick(MINUS_BUTTON, minusUp, -40);
}

boolean handleClick(int buttonPin, boolean wasUp, int delta) {
   boolean isUp = digitalRead(buttonPin);
   if (wasUp && !isUp) {
      isUp = digitalRead(buttonPin);
      // если был клик кнопки, меняем яркость в пределах от 0 до 255
      if (!isUp)
         brightness = constrain(brightness + delta, 0, 255);
   }
   return isUp;
}
