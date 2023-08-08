#include <Servo.h>

Servo servo_1u;  
Servo servo_1d;  

void setup() {
  servo_1u.attach(9);  
  servo_1d.attach(10);  
}

void loop() {    
  servo_1u.write(150);     
  servo_1d.write(150);          
  delay(15);                          
}