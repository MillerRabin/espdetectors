#include <vl53l0x.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

bool vl53L0x_setup() {
  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    return false;
  }  
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));
  lox.startRangeContinuous();
  return true;
}

bool vl53L0x_print() {
  if (!lox.isRangeComplete()) return false;
  Serial.print("Distance in mm: ");
  Serial.println(lox.readRange());  
  return true;
}