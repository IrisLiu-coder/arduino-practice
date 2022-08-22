#include <Servo.h>
unsigned long start_time;
int second,minute,hour,angle=0;
Servo myservo; 
void setup() {
  Serial.begin(9600);
   myservo.attach(9);
   minute=0;hour=0;
}

void loop() {
  start_time=micros();
  second=(start_time/1000000)%60;
  minute=(start_time/1000000)/60;
  hour=minute/60;
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
}
