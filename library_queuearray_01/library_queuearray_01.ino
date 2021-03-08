#include <QueueArray.h> 
 #define LightSensor 0 
 QueueArray <int> queue; 
 void setup(){   
  Serial.begin(9600); 
 } 
 int l_count_max=500; 
 int l_count = 0; 
 int p_count = 0; 
 void loop(){   
  if( l_count == l_count_max ){     
    int val1 = analogRead(LightSensor);     
    queue.push(val1);          
    l_count = 0;   }   
  else 
    l_count++;     
  if( p_count == 2000 ){     
    Serial.println("LightSensor Values");     
    int i = 1;     
    float average = 0;     
    while( !queue.isEmpty() ){       
      Serial.print(i++);       
      Serial.print(":");       
      int item = queue.pop();       
      average += item;       
      Serial.println(item);          
   }     
   average /= (i-1);     
   Serial.print("Average:");     
   Serial.println(average,2);          
   p_count = 0;   
   }   
 else p_count ++;      
 delay(1); 
 }
