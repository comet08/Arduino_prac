#define BUTTON 34
int light = 0;
int valb = 0;
int old_valb = 0;
int state = 0;
void setup() {
  Serial.begin(9600);
  for(int i = 40; i < 46; i++)
    pinMode(i, OUTPUT);
}

void loop() {
 valb = digitalRead(BUTTON);
 if((valb==HIGH) && (old_valb==LOW))  //press button
 {
   state = 1-state;
   Serial.print("state = ");
   Serial.println(state);
   for(int i = 5; i >=0; i--)
     Serial.print(bitRead(light, i));
   Serial.println("");
 }
 old_valb = valb;
 if(state == 0){         
     light = analogRead(0);
     light = light/16;
     led(light); delay(500);
 }
 else
 {
    led(light);
 }
  
}

void led(int light){
      for(int i = 0; i < 6; i++)
      {
        if(bitRead(light, i)==1)
          digitalWrite(40+i, HIGH);
        else
          digitalWrite(40+i, LOW);
      }  
}
