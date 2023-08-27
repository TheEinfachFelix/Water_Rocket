#pragma once

#include <Arduino.h>
    // ADC
    #include <Wire.h>
    #include <Adafruit_ADS1X15.h>

    // Display
    //#include <Wire.h>
    #include <LiquidCrystal_I2C.h>

    // Servo 
    #include <Servo.h>

    extern const char* dns_adresse;

void hardwareSetup();
void setServo(int n);
float getADC(int n);
void setLCD(int line, String text, int cursor = 0);
void setTweeter(bool b);