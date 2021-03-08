#include "telegraph.h" 
 #define LED1 30 
 
const unsigned int DIT_LENGTH = 100; 
Telegraph telegraph(LED1, DIT_LENGTH ); 
const unsigned int MAX_MESSAGE_LEN = 255; 
const int LINE_FEED = 10; 
char message_text[MAX_MESSAGE_LEN]; 
int index_t = 0; 
volatile int state = LOW; 
volatile unsigned long last_int_time = 0; 
volatile unsigned long int_time; 
volatile int debounceGuard = 500; 

void sendingHelloMessage(){  
int_time = millis(); 
if( int_time - last_int_time > debounceGuard ){   
  state = HIGH;   
  } 
 } 
void setup(){   
  pinMode(LED1, OUTPUT);   
  attachInterrupt(0, sendingHelloMessage, RISING);   
  Serial.begin(9600); 
}

void loop(){  
  if( Serial.available() > 0 ){
    int command = Serial.read();    
    if( command == LINE_FEED || index_t == MAX_MESSAGE_LEN - 1 ){ 
      message_text[index_t] = 0;       
      index_t = 0;       
      telegraph.send_message(message_text);    
      }    
     else{      
       boolean add_flag = false;   
       if( command >= 'a' && command <= 'z' ) 
          add_flag = true;       
       if( command >= 'A' && command <= 'Z' ) 
          add_flag = true;      
        if( command >= '0' && command <= '9' ) 
          add_flag = true;      
        if( command == ' ' ) 
          add_flag = true;   
        if( add_flag ) message_text[index_t++] = command;
      }   
    }      
    if( state == HIGH ){    
     telegraph.send_message("SOS");   
     state = LOW;   
     } 
   } 
