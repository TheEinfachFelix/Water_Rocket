#include "main.hpp"

//float Gravitation = 9.80665;
//Vector out;
//double * AngleOut;
//int32_t altimeter_ofset;
uint32_t Door_Time = 0;
uint32_t Door_Delay = 1000;

void setup() {
    Serial.begin(115200);
    pinMode(13, INPUT_PULLUP);
    Landing_Gear.attach(16); // 16 is Servo Pin

    //setupGyro();
    //bmp_setup();
    
   // altimeter_ofset = get_bpm_SealevelPressure();

    Landing_Gear.write(180);
}

void loop() {
    //mpu.getEvent(&a, &g, &temp);
    //out = getGyro();
    //AngleOut = getAngle();
      if(digitalRead(13) == 1){
        // delay setup
        if(Door_Time == 0){
            Door_Time = int(millis());
        }
        // set Servo
        if(millis() < (Door_Time + Door_Delay)){
            Landing_Gear.write(180);
        } else {
            Landing_Gear.write(0);  
        }
    } else {
        // reset values
        Door_Time = 0;
        Landing_Gear.write(180);
    }
    delay(15);
    Serial.println(millis() > (Door_Time + Door_Delay));
}