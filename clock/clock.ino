#include <Servo.h>
int Time_second;
int Time_minute;
int Time_hour;
long Time_hour_setting=3600000;
long Time_minute_setting=360000;
long Time_second_setting=1000;
unsigned long start_time;
int second,minute,hour,angle=0;
Servo myservo; 
void setup() {
  Serial.begin(9600);
   myservo.attach(9);
   minute=0;hour=0;
}

void loop() {
  start_time=millis();
  Time_hour=start_time/Time_hour_setting;
  Time_minute=(start_time%Time_hour_setting)/Time_minute_setting;
  Time_second=((start_time%Time_hour_setting)%Time_minute_setting)/Time_second_setting;
  second=Time_second%60;
  minute=Time_second/60;
  hour=minute/60;
  if(minute%2==1){
    angle=60-second;
  }else{
    angle=second;
  }
  myservo.write(angle);
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
}
