#pragma once

//mpu libs
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
//general libs
#include <math.h>
#include <Arduino.h>

extern Adafruit_MPU6050 mpu;
struct Vector
{
    float ax;
    float ay;
    float az;
    float gx;
    float gy;
    float gz;
};

void setupGyro();
Vector getGyro();
double * getAngle();