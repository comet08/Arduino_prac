 #define LED1 30 
 #define LED2 31

byte rcvmsg[2]; 
byte led[3][3];
void setup(){   
  pinMode(LED1, OUTPUT);     
  pinMode(LED2, OUTPUT);     
  Serial.begin(9600); 
} 
void loop(){   
  if( Serial.available() > 0 ){   
    int len = Serial.readBytes(rcvmsg, sizeof(rcvmsg)); 
    if( len > 1 ){   
      led[rcvmsg[0]][1] = rcvmsg[1]; /*0 turnoff 1 steady 2  blinking*/
     Serial.println("");    
     }
  }
     if(led[1][1] == 2 && led[2][1]==2){
         digitalWrite(LED1, HIGH);
         digitalWrite(LED2, HIGH);
         delay(500);
         digitalWrite(LED1,LOW);
         digitalWrite(LED2,LOW);
         delay(500);
       }
      else{
     for(int i = 1;i<3; i++){
       if(led[i][1] == 0)
        digitalWrite(i+29, LOW);
       else if(led[i][1] == 1)
          digitalWrite(i+29, HIGH);
       else if(led[i][1] == 2)
       {
          digitalWrite(i+29, HIGH);
         delay(500);
         digitalWrite(i+29,LOW);
         delay(500);
        }
     }

}
}
