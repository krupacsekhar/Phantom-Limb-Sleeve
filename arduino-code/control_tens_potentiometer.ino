#include <MPU6050_tockn.h>
#include <Wire.h>
#include <SPI.h>

MPU6050 mpu6050(Wire);
long timer = 0;
const int chipSelectPin = 10;
int channel = 1; // selected channel
int value = 25; // selected value corresponding to 1k Ohms


void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  pinMode(chipSelectPin, OUTPUT);
  SPI.begin();
}

void loop() {
  mpu6050.update();
  float gyroXPrevious = 1.0;
  if (millis() - timer > 1) {
    float gyroXCurrent = mpu6050.getGyroX();
    Serial.println(gyroX);

    if (gyroXCurrent * gyroXPrevious < 0) {
      digitalPotWrite(channel, value);
    }
   
    gyroXPrevious = gyroXCurrent;
    timer = millis();
  }
}

void digitalPotWrite(int address, int value) {

  // take the SS pin low to select the chip:

  digitalWrite(chipSelectPin, LOW);

  delay(100);

  //  send in the address and value via SPI:

  SPI.transfer(address);

  SPI.transfer(value);

  delay(100);

  // take the SS pin high to de-select the chip:

  digitalWrite(chipSelectPin, HIGH);
}