#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int n=0;
int sensor=A0;
int sensorRead=0;
unsigned long start_time,t,time_stop,tt;
int second,minute,hour,secondt,minutet,hourt;
void sleep(){
  if(n==16){
    n=0;
  }else{
    n++;
  }
  lcd.setCursor(n,0);
  lcd.print("zZ");
  lcd.setCursor(0,1);
  lcd.print("(-_-)");
  }
void awake(){
  if(n==16){
    n=0;
  }else{
    n++;
  }
  lcd.setCursor(n,0);
  lcd.print("Hi!");
  lcd.setCursor(0,1);
  lcd.print("(0v0)");
  }
void Using(){
  start_time=micros();
  tt=(start_time/1000000);
  second=tt%60;
  minute=(tt/60)%60;
  hour=tt/3600;
  lcd.setCursor(0,1);
  lcd.print("for "); 
  lcd.print(hour);  
  lcd.print(":");  
  lcd.print(minute);
  lcd.print(":");  
  lcd.print(second);
  if(hour>=1){
    lcd.print(" @n@");
    }else{
    lcd.print(" o_o");  
      } 
  lcd.setCursor(0,0);
  lcd.print("I haven't slept");
  }
void Time(){
  start_time=micros();
  t=start_time-time_stop;
  int s=(t/1000000)-10;
  secondt=s%60;
  minutet=(s/60)%60;
  hourt=s/3600;
  if(s>=0){
    lcd.setCursor(0,0);
    lcd.print(hourt);  
    lcd.print(":");  
    lcd.print(minutet);
    lcd.print(":");  
    lcd.print(secondt);
    }else{
    lcd.setCursor(0,1);
    lcd.print(-s);
    lcd.print("...");
    }
    lcd.setCursor(9,1);
    lcd.print("u0v0P!");
  }
void setup()
{
  Serial.begin(9600);
  lcd.init();                     // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("I'm Chris!");
}
void loop()
{ 
  Serial.println(t);
  lcd.init(); 
  sensorRead=analogRead(sensor);
  if(sensorRead<200){
    time_stop=start_time;
    sleep();
    time_stop=start_time;
    }else if(sensorRead>=200&&sensorRead<400){
    time_stop=start_time;
    awake();  
    time_stop=start_time;
    }else if(sensorRead>=400&&sensorRead<600){
      //time_stop=t;
      Time();
    }else if(sensorRead>=600&&sensorRead<800){
    time_stop=start_time;
    Using();  
    time_stop=start_time;
    }else{
    lcd.setCursor(0,0);
    lcd.print("=U=");   
    lcd.setCursor(0,1);
    lcd.print("nothing here...");   
    time_stop=start_time;
    }
}
