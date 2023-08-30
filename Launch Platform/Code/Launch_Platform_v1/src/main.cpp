#include "main.hpp"

unsigned long previousMillis = 0; 
const long interval = 4000; 
bool karussell = 0;


unsigned long previousMillisCountdown = 0; 
const long intervalCountdown = 1000; 

const int servo_hold = 180;
const int servo_go = 0;

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
    

    //Launch
    if (getArm()){
        setLCD(1, "Arm", 13);
        // auto Launch
        if (getAutoLaunch()){
            if (getADC(0) >= 4.9){
                if (currentMillis - previousMillisCountdown >= intervalCountdown) { 
                    previousMillisCountdown = currentMillis;
                    if (countdown  == "N/A"){
                        countdown = "6";
                        setTweeter(1);
                    } else if (countdown  == "6"){
                        countdown = "5";
                        setTweeter(0);
                    } else if (countdown  == "5"){
                        countdown = "4";
                        setTweeter(1);
                    } else if (countdown  == "4"){
                        countdown = "3";
                        setTweeter(0);
                    } else if (countdown  == "3"){
                        countdown = "2";
                        setTweeter(1);
                    } else if (countdown  == "2"){
                        countdown = "1";
                        setTweeter(1);
                    } else if (countdown  == "1"){
                        countdown = "0";
                        setTweeter(0);
                        setServo(servo_go);
                    } else if (countdown  == "0"){
                        countdown = "-1";
                    } else if (countdown  == "-1"){
                        countdown = "-2";
                    }
                }
            }         
        }
        
        // forch launch
        if (getForceLaunch()){
                setServo(servo_go);
        }
    } else{
        setServo(servo_hold);
        setLCD(1, "   ", 13);
        setTweeter(0);
    }
}