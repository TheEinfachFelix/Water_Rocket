
#include "mpu.hpp"
Adafruit_MPU6050 mpu;
Vector helper;
sensors_event_t a, g, temp;


bool mpuSetup(){
  ///////////////////////////////// start coms /////////////////////////////////
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    return false;
  }
  Serial.println("MPU6050 Found!");

  ///////////////////////////////// config mpu /////////////////////////////////
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
    case MPU6050_RANGE_2_G:
      Serial.println("+-2G");
      break;
    case MPU6050_RANGE_4_G:
      Serial.println("+-4G");
      break;
    case MPU6050_RANGE_8_G:
      Serial.println("+-8G");
      break;
    case MPU6050_RANGE_16_G:
      Serial.println("+-16G");
      break;
  }
  /////////////////////////////////
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
    case MPU6050_RANGE_250_DEG:
      Serial.println("+- 250 deg/s");
      break;
    case MPU6050_RANGE_500_DEG:
      Serial.println("+- 500 deg/s");
      break;
    case MPU6050_RANGE_1000_DEG:
      Serial.println("+- 1000 deg/s");
      break;
    case MPU6050_RANGE_2000_DEG:
      Serial.println("+- 2000 deg/s");
      break;
  }
  /////////////////////////////////
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
    case MPU6050_BAND_260_HZ:
      Serial.println("260 Hz");
      break;
    case MPU6050_BAND_184_HZ:
      Serial.println("184 Hz");
      break;
    case MPU6050_BAND_94_HZ:
      Serial.println("94 Hz");
      break;
    case MPU6050_BAND_44_HZ:
      Serial.println("44 Hz");
      break;
    case MPU6050_BAND_21_HZ:
      Serial.println("21 Hz");
      break;
    case MPU6050_BAND_10_HZ:
      Serial.println("10 Hz");
      break;
    case MPU6050_BAND_5_HZ:
      Serial.println("5 Hz");
      break;
  }
  /////////////////////////////////
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);	// Keep it latched.  Will turn off when reinitialized.
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);

  Serial.println("");
  return true;
}

Vector getGyro(){
  // get new Data
    mpu.getEvent(&a, &g, &temp);
  // put data into the vector
    helper.ax = (a.acceleration.x);
    helper.ay = (a.acceleration.y);
    helper.az = (a.acceleration.z);
    helper.gx = (g.gyro.x);
    helper.gy = (g.gyro.y);
    helper.gz = (g.gyro.z);
    return helper;
}

/*
Pitch and roll calc

    double x = a.acceleration.x;
    double y = a.acceleration.y;
    double z = a.acceleration.z;
    pitch = atan(x / sqrt((y * y) + (z * z)));
    roll = atan(y / sqrt((x * x) + (z * z)));
    pitch = pitch * (180.0 / 3.14);
    roll = roll * (180.0 / 3.14) ;
*/