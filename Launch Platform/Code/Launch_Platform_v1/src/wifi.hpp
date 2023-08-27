#pragma once

#include <Arduino.h>
//wifi libs
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include "hardware.hpp"


void wifiSetup();
void wifiLoop();
String getIP();
bool getArm();
bool getAutoLaunch();
bool getForceLaunch();
