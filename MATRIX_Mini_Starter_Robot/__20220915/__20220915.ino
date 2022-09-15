#include <Arduino.h>
#include "MatrixMini/MatrixMini.h"

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) {
      ;
  };
}
void setup() {
  Mini.begin(7.4,0,115200);
  Mini.M1.set(100); // Speed Range: 100 ~ -100
  Mini.M2.set(100); // Speed Range: 100 ~ -100
  _delay(1.1);
  Mini.M1.set(-100); // Speed Range: 100 ~ -100
  Mini.M2.set(100); // Speed Range: 100 ~ -100
  _delay(0.25);
  Mini.M1.set(0); // Speed Range: 100 ~ -100
  Mini.M2.set(0); // Speed Range: 100 ~ -100
  _delay(0.25);
  Mini.M1.set(-100); // Speed Range: 100 ~ -100
  Mini.M2.set(-100); // Speed Range: 100 ~ -100
  _delay(0.8);
  Mini.M1.set(0); // Speed Range: 100 ~ -100
  Mini.M2.set(0); // Speed Range: 100 ~ -100

}

void _loop() {
}

void loop() {
  _loop();
}
