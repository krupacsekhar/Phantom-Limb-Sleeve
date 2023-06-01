#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
long timer = 0;
int vpin = 4;
float gyroXPrevious = 0.0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();  
  float gyroXCurrent = mpu6050.getGyroX();
  Serial.println(gyroX);

  if (gyroXCurrent * gyroXPrevious < 0) {
    digitalWrite(vpin, HIGH);
    delay(2000);
    digitalWrite(vpin, LOW);
  }
  
  gyroXPrevious = gyroXCurrent;
  delay(10);
}