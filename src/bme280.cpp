#include <bme280.h>

unsigned long delayTime;

 Adafruit_BME280* bme280_setup(byte address, TwoWire* wire) {
  Adafruit_BME280* bme = new Adafruit_BME280();
  bool status = bme->begin(0x76, wire);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
    Serial.print("SensorID was: 0x"); Serial.println(bme->sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    delete bme;
    return NULL;
  }    
  Serial.println("-- Default Test --");
  delayTime = 1000;
  Serial.println();
  return bme;
}


void bme280_print(Adafruit_BME280*  bme) {
    if (bme == NULL) return;
    Serial.print("Temperature = ");
    Serial.print(bme->readTemperature());
    Serial.println(" °C");

    Serial.print("Pressure = ");

    Serial.print(bme->readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme->readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme->readHumidity());
    Serial.println(" %");

    Serial.println();
}
