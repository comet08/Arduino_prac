#include <ctype.h> 
#include "Arduino.h" 
#include "telegraph.h" 
 const char* LETTERS[] = {  
 ".-", "-...", "-.-.", "-..", ".",      // A-E  
 "..-.", "--.", "....", "..", ".---",   // F-J   
"-.-", ".-..", "--", "-.", "---",      // K-O   
".--.", "--.-", ".-.", "...", "-.--",  // P-T   
"..-", "...-", ".--", "-..-", "-.--",  // U-Y   "--.." 
}; 
 const char* DIGITS[] = {   
"-----", ".----", "..---", "...--",    // 0-3  
 "....-", ".....", "-....", "--...",    // 4-7  
 "---..", "----." 
}; 

 Telegraph::Telegraph(const int output_pin, const int dit_length) {  
 _output_pin = output_pin;   
_dit_length = dit_length;   
_dah_length = dit_length * 3;   
pinMode(_output_pin, OUTPUT); 
} 

 void Telegraph::output_code(const char* code){
for (int i = 0; i < strlen(code); i++) {    
 if (code[i] == '.')     
  dit();    
 else      
 dah();   
} 
  Serial.print(" "); 
} 
 void Telegraph::dit(){   
Serial.print(".");   
output_symbol(_dit_length); 
} 
 void Telegraph::dah(){  
 Serial.print("-");  
 output_symbol(_dah_length); 
} 

 void Telegraph::output_symbol(const int length){  
 digitalWrite(_output_pin, HIGH);   
delay(length);   
digitalWrite(_output_pin, LOW);  
 delay(_dit_length); 
} 

 void Telegraph::send_message(const char* message){  
 Serial.println(message);  
 for (int i = 0; i < strlen(message); i++) {  
   const char current_char = toupper(message[i]);   
  if (isalpha(current_char)) {      
 output_code(LETTERS[current_char - 'A']);  
     delay(_dah_length);    
 } else if (isdigit(current_char)) {    
   output_code(DIGITS[current_char - '0']);  
     delay(_dah_length);  
   } else if (current_char == ' ') {     
  Serial.print(" ");     
  delay(_dit_length); 
}   
}   
Serial.println(); 
}