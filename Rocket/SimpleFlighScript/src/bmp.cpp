#include "bmp.hpp"

void bmp_setup(){ 
    if (!bmp180.begin()) {
        Serial.println("Could not find a valid BMP085 sensor,check wiring!");
        while (1) {}
    }
}

float get_bpm_temperature(){
    return bmp180.readTemperature();
}

int32_t get_bpm_pressure(){
    return bmp180.readPressure();
}

int32_t get_bpm_SealevelPressure(float altitude_meters){
    return bmp180.readSealevelPressure(altitude_meters);
}

float get_bpm_altitude(float sealevelPressure){
    return bmp180.readAltitude(sealevelPressure);
}

uint16_t get_bmp_raw_temperature(){
    return bmp180.readRawTemperature();
}

uint32_t get_bpm_raw_pressure(){
    return bmp180.readRawPressure();
}