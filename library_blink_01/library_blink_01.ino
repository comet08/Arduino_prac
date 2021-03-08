#include "blinking_led.h" 

#define LED1 30 
volatile int state = HIGH; 
volatile unsigned long last_int_time = 0; 
volatile unsigned long int_time; 
volatile int debounceGuard = 500; 

void toggleFunction(){   
  int_time = millis();   
  if( int_time - last_int_time > debounceGuard ){ 
    state = !state;   
    last_int_time = int_time;   
    } 
} 
void setup(){   
  pinMode(LED1, OUTPUT);      
  attachInterrupt(0, toggleFunction, RISING); 
} 

void loop(){   
  if( state == HIGH )  
    blink_led(LED1, 100); 
  else 
    blink_led(LED1,500); 
 } 
