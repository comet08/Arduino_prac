#define LightSensor 0 
#define Thermistor 1 
void setup(){   Serial.begin(9600); } 
float pad = 270; 
int p_count = 0; 
float convertToCelsius(int RawADC) {   
  long Resistance;     
  float Temp;  // Dual-Purpose variable to save space. 
   Resistance=((1024 * pad / RawADC) - pad);    
   Temp = log(Resistance);   
   Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));   
   Temp = Temp - 273.15;    
   return Temp; 
   } 
 void loop(){   
  if( p_count == 100 ){     
    int val1 = analogRead(LightSensor);    
    int val2 = analogRead(Thermistor);     
    float temp = convertToCelsius(val2);         
    Serial.print("Light Sensor Value : ");     
    Serial.println(val1);     
    Serial.print("Thermistor Value : ");     
    Serial.println(val2);     
    Serial.print("Celsius: ");     
    Serial.println(temp,2);          
    p_count = 0;   
 }   
 else p_count++;   
 delay(10);    
} 
