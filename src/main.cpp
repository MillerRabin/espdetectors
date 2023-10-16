#include <Wire.h>
#include <Arduino.h>
#include <i2cScan.h>
#include <bme280.h>
#include <vl53l0x.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
  bme280_setup(0x76);
  vl53L0x_setup();
}
 
void loop() {
  bme280_print();
  i2c_scan();
  vl53L0x_print();
  delay(5000);
}