#define SERVO_PIN 8
#define BUTTON1 40 

 int angle = 0; 
 int current_angle = 0; 
 int pulseWidth; 
 int d_angle = 1; 
 int val = LOW; 
 int old_val = LOW; 
 int val2 = LOW; 
 int old_val2 = LOW; 
 void setup() {   
  pinMode(SERVO_PIN, OUTPUT);   
  pinMode(BUTTON1, INPUT);   

  Serial.begin(9600);   
 } 
 void loop(){   
  button1();   

  servoPulse(SERVO_PIN, current_angle);   
  delay(100); 
 } 
 void button1(){     
  val = digitalRead(BUTTON1);     
  if((val == HIGH) && (old_val == LOW)){       
    Serial.println("Button1 pressed");       
    angle = current_angle + 60;       
    if (angle >= 180) angle = 180;       
    for (; current_angle <= angle; current_angle += d_angle) {    
      servoPulse(SERVO_PIN, current_angle);      
    }      
    current_angle = angle;     
  }     
  old_val = val;    
  
  } 
  
 void servoPulse(int servoPin, int angle) { 
  pulseWidth = (angle * 11) + 700;   
  digitalWrite(servoPin, HIGH);   
  delayMicroseconds(pulseWidth);  
  digitalWrite(servoPin, LOW);  
  delay(20 - pulseWidth / 1000);
 } 
