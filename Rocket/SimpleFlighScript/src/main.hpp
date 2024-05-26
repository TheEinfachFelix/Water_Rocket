#pragma once

// mpu libs
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
//general libs
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <math.h> 
#include <Servo.h>

#include "gyro.hpp"
#include "bmp.hpp"

Servo Landing_Gear;
Adafruit_BMP085 bmp180;

extern Vector out;
extern sensors_event_t a, g, temp;
Adafruit_MPU6050 mpu;
