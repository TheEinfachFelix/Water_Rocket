#pragma once

//general libs
#include <Arduino.h>

//Wifi libs
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

//hardware libs
    // ADC
    #include <Wire.h>
    #include <Adafruit_ADS1X15.h>

    // Display
    //#include <Wire.h>
    #include <LiquidCrystal_I2C.h>

    // Servo 
    #include <Servo.h>

#include "wifi.hpp"
#include "hardware.hpp"

extern const char* dns_adresse;