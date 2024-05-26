#pragma once

#include <Arduino.h>
#include <Adafruit_BMP085.h>

extern Adafruit_BMP085 bmp180;

void bmp_setup();
float get_bpm_temperature();
int32_t get_bpm_pressure();
int32_t get_bpm_SealevelPressure(float altitude_meters = 0);
float get_bpm_altitude(float sealevelPressure = 101325);
uint16_t get_bmp_raw_temperature();
uint32_t get_bpm_raw_pressure();