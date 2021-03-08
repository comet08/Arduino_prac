#define light 0
#define thermistor 1
#include "LimitedLogQueue.h"

int qsize = 10;
int more = 0;
LimitedLogQueue<int> lightque("Light Sensor",qsize);
LimitedLogQueue<int> thermistorque("Thermistor", qsize);
unsigned long ltime=0;
volatile int state = LOW; 
volatile unsigned long last_int_time = 0; 
volatile unsigned long int_time; 

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(0, statePrint, RISING);
}

void loop(){
  
  state = digitalRead(2);
  if(state==HIGH)
  {
      lightque.print();
    Serial.print("Average: ");
    Serial.println(lightque.getAverage());
    thermistorque.print();
    Serial.print("Average: ");
    Serial.println(thermistorque.getAverage());
    state=LOW;
  }

  if(ltime+100 <=millis()){
    int l = analogRead(0);
    int t = analogRead(1);
    lightque.add(l);
    thermistorque.add(t);
    
    if(lightque.getAverage() < 150)
    {
      Serial.println("I Need More Sunshine");
      more = 1;
    }
    if((more==1)&&(lightque.getAverage() > 400)){
      Serial.println("I Love Sunshine");
      more=0;
    }
    ltime = millis();
  }
}

void statePrint(){
   int_time = millis();   
   if( int_time - last_int_time > 500 ){     
    state = HIGH;   
}}
