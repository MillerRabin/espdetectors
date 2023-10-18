#ifndef mpu9250_h
#define mpu9250_h

#include <MPU9250_WE.h>
#include <Wire.h>
#define MPU9250_ADDR 0x68

void mpu9250_setup();
void mpu9250_print();

#endif