#include "HX711.h"
HX711 scale;

#define DT  2
#define SCK 3

float weight_of_standard = 20;
float units = 0.035274;
float calibration_factor = 0;

void setup() {
  Serial.begin(57600);
  scale.begin(DT, SCK);
  scale.set_scale();
  scale.tare();
  Serial.println("You have 10 seconds to set your known load");
  delay(10000);
  Serial.print("calibration factor: ");
  calibration_factor = scale.get_units(10) / (weight_of_standard / units);
  Serial.println(calibration_factor);
}

void loop() {
}

// calibration factor: -1.07
