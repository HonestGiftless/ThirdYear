#define data_pin    13 // пин данных (англ. data)
#define latch_pin   12 // пин строба (англ. latch)
#define clocks_pin   11 // пин такта (англ. clock)
#define button_pin  10
 
int clicks = 0;
boolean buttonWasUp = true;
byte segments[10] = {
  0b01111101, 0b00100100, 0b01111010, 0b01110110, 0b00100111, 
  0b01010111, 0b01011111, 0b01100100, 0b01111111, 0b01110111
};
 
void setup()
{
  pinMode(data_pin, OUTPUT);
  pinMode(clocks_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
}
 
void loop()
{
  if (buttonWasUp && !digitalRead(button_pin)) {
    delay(10);
    if (!digitalRead(button_pin))
      clicks = (clicks + 1) % 10;
  }
  buttonWasUp = digitalRead(button_pin);
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clocks_pin, LSBFIRST, segments[clicks]);
  digitalWrite(latch_pin, HIGH);
}