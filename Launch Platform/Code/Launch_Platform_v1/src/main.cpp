#include "main.hpp"

unsigned long previousMillis = 0; 
const long interval = 4000; 
bool karussell = 0;

void setup() {
    Serial.begin(115200);
    hardwareSetup();
    wifiSetup();
    
}

void loop() {
    wifiLoop();
    // lcd stuff
        // lcd ip karusell
        unsigned long currentMillis = millis(); 
        if (currentMillis - previousMillis >= interval) { 
            previousMillis = currentMillis; 
            if (karussell){
                setLCD(0, "                ");
                setLCD(0, String(dns_adresse) + ".local");
                
            }else {
                setLCD(0, "                ");
                setLCD(0, getIP());
            }
            karussell = !karussell;
        }
        //bar anzeigen
        setLCD(1, String(getADC(0)), 5);
    
    

    

    //setServo(5);
    
    
}