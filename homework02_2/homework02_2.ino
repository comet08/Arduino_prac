#define LED1 39
#define LED2 38
#define buttonA 43
#define buttonB 42
#define buttonC 44
int va=0, vb=0, vc=0;
int ova=0, ovb=0, ovc=0;
int s1=0, s2=0;
int flow[3];

void setup() {
  Serial.begin(9600);
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(buttonA, INPUT);  
 pinMode(buttonB, INPUT);
 pinMode(buttonC, INPUT);
 for(int i = 0; i <3; i++)
  flow[i] = 3;
}

void loop() {
  va=digitalRead(buttonA);
  vb=digitalRead(buttonB);
  vc=digitalRead(buttonC);
  
  if((va==HIGH)&&(ova==LOW)){
     flow[2] = flow[1];
     flow[1] = flow[0];
     flow[0] = 1;
  }
  if((vb==HIGH)&&(ovb==LOW)){
     flow[2] = flow[1];
     flow[1] = flow[0];
     flow[0] = 2;
    }
  if((vc==HIGH)&&(ovc==LOW)){
     flow[2] = flow[1];
     flow[1] = flow[0];
     flow[0] = 3;
  }
  if(flow[2]==1 && flow[1]==2 && flow[0]==3)
  {
    s1 = 1-s1; flow[2]=3;
    if(s1==1)
     digitalWrite(LED1, HIGH);
    else
     digitalWrite(LED1, LOW);
  }
  else if(flow[2]==2 && flow[1]==1 && flow[0]==3)
  {
    s2 = 1-s2; flow[2]=3;
    if(s2==1)
     digitalWrite(LED2, HIGH);
    else
     digitalWrite(LED2, LOW);
  }
  ova=va, ovb=vb, ovc = vc;
}
