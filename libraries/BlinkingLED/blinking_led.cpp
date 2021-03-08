#include "Arduino.h"
#include "blinking_led.h" 

 void blink_led(int led_pin, int d){  
digitalWrite(led_pin, HIGH);  
delay(d); 
 digitalWrite(led_pin, LOW); 
 delay(d); 
} 