#ifndef bme_280_h
#define bme_280_h

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

bool bme280_setup(byte address);
void bme280_print();

#endif