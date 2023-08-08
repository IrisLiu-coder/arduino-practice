#include <Servo.h>

Servo servo_1;  

void setup() {
  servo_1.attach(9); 
}

void loop() {
  servo_1.write(180);    
  servo_2.write(180);
  delay(1000);
  servo_1.write(0); 
  servo_2.write(0);   
  delay(1000);     
}
