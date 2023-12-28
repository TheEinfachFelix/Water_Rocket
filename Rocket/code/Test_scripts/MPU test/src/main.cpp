#include "main.hpp"

Vector out;

void setup(void) {
  Serial.begin(115200);

  mpuSetup();
}

void loop() {


out = getGyro();


    // Print out the values /
    Serial.print("AccelX: ");
    Serial.print(out.ax);
    Serial.print(",");
    Serial.print("AccelY: ");
    Serial.print(out.ay);
    Serial.print(",");
    Serial.print("AccelZ: ");
    Serial.print(out.az);
    Serial.print("  ,  ");
    Serial.print("GyroX: ");
    Serial.print(out.gx);
    Serial.print(",");
    Serial.print("GyroY: ");
    Serial.print(out.gy);
    Serial.print(",");
    Serial.print("GyroZ: ");
    Serial.print(out.gz);
    Serial.println("");
}