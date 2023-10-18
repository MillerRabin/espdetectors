#ifndef bme_280_h
#define bme_280_h

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280* bme280_setup(byte address, TwoWire* wire);
void bme280_print(Adafruit_BME280* bme);

#endif