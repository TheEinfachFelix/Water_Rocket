#include "main.hpp"


void setup() {
    Serial.begin(115200);

    wifiSetup();
}

void loop() {
    wifiLoop();
    
}
