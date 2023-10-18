#include <Wire.h>
#include <Arduino.h>
#include <i2cScan.h>
#include <bme280.h>
#include <vl53l0x.h>
#include <mpu9250.h>

#define SECOND_LINE_SDA 5
#define SECOND_LINE_SCL 4 


TwoWire secondLine = TwoWire(1);
Adafruit_BME280* bme;

void setup() {
  Wire.begin();  
  secondLine.begin(SECOND_LINE_SDA, SECOND_LINE_SCL);
  
  Serial.begin(115200);  
  bme = bme280_setup(0x76, &secondLine);
  if (bme == NULL) {
    Serial.println("\nCan't detect bme");    
  }
  vl53L0x_setup();
  mpu9250_setup();
}
 
void loop() {
  bme280_print(bme);
  Serial.println("\nI2C First line scan");
  i2c_scan(&Wire);
  Serial.println("\nI2C Second line scan");
  i2c_scan(&secondLine);
  vl53L0x_print();
  mpu9250_print();
  delay(2000);
}