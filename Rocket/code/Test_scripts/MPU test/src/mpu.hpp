#pragma once


#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

struct Vector
{
    float ax;
    float ay;
    float az;
    float gx;
    float gy;
    float gz;
};


bool mpuSetup();
Vector getGyro();

