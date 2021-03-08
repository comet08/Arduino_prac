#define LED1 2
#define LED2 38
#define LED3 41
#define buttonA 43
#define buttonB 42
int va=0, vb=0;
int ova=0, ovb=0;
int s1=0, s2=0, s3=0;
int c1, c2, c3;
unsigned long stime= 0;
unsigned long interval = 100;

void setup() {
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(buttonA, INPUT);  pinMode(buttonB, INPUT);
}

void loop() {
  va=digitalRead(buttonA);
  vb=digitalRead(buttonB);

  if(((va==HIGH)&&(ova==LOW)) ||((vb==HIGH)&&(ovb==LOW))){
    stime = millis();
    if(va==HIGH)
      c1++;
    if(vb==HIGH)
      c2++;
  }
  ova = va; ovb = vb;
  if(stime+interval < millis()){
    if((c1+c2)==2){
      s3 = 1-s3;
      if(s3==1){
        digitalWrite(LED3, HIGH);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
      }
      else
        digitalWrite(LED3, LOW);
    }
    else if(c1==1)
    { s1 = 1-s1;
      if(s1==1){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        stime=0;
      }
      else
       digitalWrite(LED1, LOW);}
     else if(c2==1)
    { s2 = 1-s2;
      if(s2==1){
      digitalWrite(LED2, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED3, LOW);
      stime=0;
      }
    else
       digitalWrite(LED2, LOW); 
    }
    c1=0, c2=0;
}
 
}
