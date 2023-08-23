// ADC
  #include <Wire.h>
  #include <Adafruit_ADS1X15.h>
  Adafruit_ADS1115 ads;

// Display
  //#include <Wire.h>
  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

// Servo 
  #include <Servo.h>
  Servo myservo;

void setup() {
  // ADC
    ads.setGain(GAIN_TWOTHIRDS);
    ads.begin();
  // Display
    lcd.init();
    lcd.backlight();
  // Servo
    myservo.attach(2); 
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(float(2*ads.readADC_SingleEnded(0))/10000);
  
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
}
