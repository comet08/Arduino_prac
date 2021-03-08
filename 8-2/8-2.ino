#include <SoftwareSerial.h>

#define buttona 39
#define buttonb 40
#define buttonc 41
#define servo 8
#define ENB 5
#define IN4 6 
#define IN3 7 

int blueTx=13; 
int blueRx=12; 
SoftwareSerial mySerial(blueTx, blueRx); 


const int force = A0;
const int flex = A1;
int pulseWidth; 
int state = 0;
int dcturn = 0, olddc =0, dcstate=0;
int dcpower =0, olddcp = 0,power = 1;
int servoturn = 0, oldservo = 0, servostate=0;
int current =0;
String my ="";

void setup(){   
   pinMode(servo,OUTPUT); 
   pinMode(buttona,INPUT);  
   pinMode(buttonb,INPUT); 
    pinMode(buttonc,INPUT);  
     pinMode(IN4, OUTPUT);  
    pinMode(IN3, OUTPUT);  
    pinMode(ENB, OUTPUT);  
   Serial.begin(9600);
   mySerial.begin(9600); 
} 
  
void loop(){ 
  if(mySerial.available())
  {
    char myChar = (char)mySerial.read();
    my += myChar;
    delay(10);
  }
  readA();
  readB();
  readC();
}

void readA(){
  dcturn = digitalRead(buttona);
  if(my == "don"){
    dcstate = HIGH;
    my = "";
   Serial.println("dc on");
  }
  if(my == "doff"){
    dcstate = LOW;
    my = "";
    Serial.println("dc off");
  }
  if(dcturn == HIGH && olddc == LOW){
    dcstate = !dcstate;
     Serial.println("button A");
  }
  olddc = dcturn;
   delay(100); 
}

void readB(){
  dcpower = digitalRead(buttonb);
  if(my == "pup"){
    power+=1;
    my = "";
    Serial.println("power up!!");
  }
  if(dcpower == HIGH && olddcp == LOW){
    power +=1;
    Serial.println(power*63);
    Serial.println("button B == power up");
  }
  if(power > 4)
    power = 1;
  olddcp = dcpower;
  
  if(dcstate == LOW){
   digitalWrite(ENB, dcstate);     
   digitalWrite(IN4, dcstate);     
   digitalWrite(IN3, dcstate);  
  }
  else{
     digitalWrite(ENB, power*63);     
     digitalWrite(IN4, dcstate);     
     digitalWrite(IN3, !dcstate);   
  }
}

void readC(){
  servoturn = digitalRead(buttonc);
  if(my == "son"){
    servostate = HIGH;
    Serial.println("servo on");
    my = "";
  }
  if(my == "soff"){
    servostate = LOW;
    Serial.println("servo off");
    my = "";
  }
  if(servoturn == HIGH && oldservo == LOW){
    Serial.println("button C");
    servostate = !servostate;
  }

  if(servostate == HIGH){
    current +=1;
    if(current>180)
      current = 0;
    servoPulse(current);
  }
  
  oldservo = servoturn;
}


void servoPulse(int angle) { 
  pulseWidth = (angle * 11) + 700;   
  digitalWrite(servo, HIGH);   
  delayMicroseconds(pulseWidth);   
  digitalWrite(servo, LOW);   
  delay(20 - pulseWidth / 1000); 
}
   
 
