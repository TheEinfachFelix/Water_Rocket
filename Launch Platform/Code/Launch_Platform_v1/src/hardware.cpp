#include "hardware.hpp"

const int Tweeter = 15;

// ADC
Adafruit_ADS1115 adc;

// Display
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

// Servo 
Servo myservo;

void hardwareSetup(){
    // ADC
        adc.setGain(GAIN_TWOTHIRDS);
        adc.begin();
    // Display
        lcd.init();
        lcd.backlight();
    // Servo
       myservo.attach(0); 

    // tweeter
    pinMode(Tweeter, OUTPUT);

    // für Karusell
    setLCD(0, String(dns_adresse) + ".local");
    setLCD(1, "Bar: ");
}

void setServo(int n){
    myservo.write(n);
}

float getADC(int n){
    return (float(2*adc.readADC_SingleEnded(n))/10000);
}

void setLCD(int line, String text, int cursor){
    lcd.setCursor(cursor, line);
    lcd.print(text);
}

void setTweeter(bool b){
    digitalWrite(Tweeter, b);
}