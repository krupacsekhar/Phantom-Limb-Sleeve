#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
long timer = 0;
float minLim = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(LED_BUILTIN, OUTPUT);

  float min = 0;
  float max = 0;

  // goal here is to record min and max values over a set period of time (can change up if too long)
  // for (int curr = 0; curr < 10000; curr++) {
  //   mpu6050.update();
  //   float gyroX = mpu6050.getGyroX();
  //   if (gyroX < min) {
  //     min = gyroX;
  //   }
  //   if(gyroX > max){
  //     max = gyroX;
  //   }
  //   delay(1);
  // } 

  // minLim = max - .25*max;
}
//
void loop() {
  mpu6050.update();
  // right now, only testing GyroX but can change around parameters 
  if (millis() - timer > 1) {
    float gyroX = mpu6050.getGyroX();
    Serial.println(gyroX);
    // program LED to flash if at max value (can change to min for same effect)
    // right now saying flash is in 25% of max value
    // if (gyroX > minLim) {
    //   //digitalWrite(LED_BUILTIN, HIGH);
    //   Serial.print("LED");
    //   delay(100);
    //   //digitalWrite(LED_BUILTIN, LOW);
    // }
    timer = millis();
  }
}
