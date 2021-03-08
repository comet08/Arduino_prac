#define button 40
#define servo 8
const int force = A0;
const int flex = A1;
int pulseWidth; 
int state = 0;
void setup(){   
   pinMode(servo,OUTPUT); // Trigger is an output pin   
   pinMode(button,INPUT); // Echo is an input pin   
   Serial.begin(9600); // Serial Output 
 } 
  
void loop(){ 
  buttonread();
  if(state==0)
    forceSen();
  else
    flexSen();

}

int val=0, old_val=0;
void buttonread(){
  val = digitalRead(button);
  if(val==HIGH && old_val==LOW)
    state = 1-state;
  old_val = val;
}
long forcev, flexv;
int current=0;

void forceSen(){
 forcev = analogRead(force);

 forcev = (forcev)%180;
  Serial.println(forcev);
 if(forcev > current)
  for(;current<forcev; current+=1 )
      servoPulse(current);
 else
  for(;current>forcev; current-=1 )
      servoPulse(current);
 current = forcev;
}
void flexSen(){
 flexv = analogRead(flex);
 flexv = (flexv)%180;
  Serial.println(flexv);
 if(flexv <0)
  flexv = 0;
 if(flexv > current)
  for(;current<flexv; current+=1 )
      servoPulse(flexv);
 else
  for(;current>flexv; current-=1 )
      servoPulse(flexv);
 current = flexv;
}
void servoPulse(int angle) { 
  pulseWidth = (angle * 11) + 700;   
  digitalWrite(servo, HIGH);   
  delayMicroseconds(pulseWidth);   
  digitalWrite(servo, LOW);   
  delay(20 - pulseWidth / 1000); 
}
   
 
