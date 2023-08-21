// ADC
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads;

// Display
//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


void setup() {
  // ADC
    ads.setGain(GAIN_TWOTHIRDS);
    ads.begin();
  // Display
  lcd.init();
  lcd.backlight();
    
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print((2*ads.readADC_SingleEnded(0))*0.936329588);
  delay(100);
}
