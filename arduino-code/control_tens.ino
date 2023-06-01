#include <MPU6050_tockn.h>
#include <Wire.h>
#include <EEPROM.h>

MPU6050 mpu6050(Wire);
long timer = 0;
int vpin = 4;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // two cases - one where we want min and max, one where we want to identify change in sign 
  // building out skeleton for both
  // creating memory storage for first case 
  // float min = 0;
  // float max = 0;

  // for(int curr = 0; curr < 60000; curr++){
  //   mpu6050.update();
  //   float gyroX = mpu6050.getGyroX()
  //   if(gyroX < min){
  //     min = gyroX
  //   }
  //   if(gyroX > max){
  //     max = gyroX
  //   }
  //   delay(1);
  // } 

  // // assuming maximum value is where we want to send shock
  // float minLim = max - .25*max
  // EEPROM.put(0, minLim);
  
  // for the second case, don't have to save any variables 
  // get current value
  mpu6050.update();
  float curr_sign;
  if(mpu6050.getGyroX() > 0){curr_sign = 1}
  else{curr_sign = 0} 
}

// assuming we go with first approach
// void loop() {
//   mpu6050.update();

//   if(millis() - timer > 1){
//     float gyroX = mpu6050.getGyroX();

//     minLim = EEPROM.read(0);
//     if(gyroX > minLim) {
//       // would change from lighting up LED to sending TENs signal
//       digitalWrite(LED_BUILTIN, HIGH);
//       delay(100);
//       digitalWrite(LED_BUILTIN, LOW);
//     }
//     timer = millis();
//   }
// } 

// assuming we go with second appraoch
void loop () {
  curr_sign = controlTens(curr_sign);
}

int controlTens(prev);
// assuming we go with second approach
    mpu6050.update();
    float new_gyroX = mpu6050.getGyroX();
    int curr;
    if (new_gyroX>0 ) {
      curr = 1;
    }
    else {
      curr = 0;
    }

    if (curr != prev) {
      digitalWrite(vpin, HIGH);
      delay(100);
      digitalWrite(vpin, LOW);

    prev = curr;
    return prev
    }
