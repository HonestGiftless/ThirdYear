#define sensor_pin A0
void setup() { 
  Serial.begin(9600); 
} 
 
int status = 0; 
unsigned long last_millis = 0; 
unsigned long interval = 1000; 
 
void loop() { 
  if (Serial.available()>0 || status == 1){ 
    char message = Serial.read();
    if (message == 's' || status == 1){ 
      if (millis() - last_millis > interval){ 
        last_millis = millis(); 
        int val = analogRead(sensor_pin); 
        Serial.println(val); 
        status = 1; 
      } 
    } 
    else{ 
      Serial.println("Unknown message"); 
    } 
  } 
}
