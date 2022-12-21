#define photo_pin A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int val_l = analogRead(photo_pin);
  Serial.print(val_l);
}
