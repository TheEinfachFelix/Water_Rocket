#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
//in “20, 4” ändern wenn 20x04 benutzt wird

void setup() {
lcd.init();
lcd.backlight();
delay(250);
lcd.noBacklight();
delay(1000);
lcd.backlight();
delay(1000);
}

void loop() {
lcd.setCursor(0, 0);
lcd.print("AZ-Delivery");
lcd.setCursor(0, 1);
lcd.print(millis() / 1000);
delay(100);
}
