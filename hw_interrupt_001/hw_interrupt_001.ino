
#define LED1 46
#define LED2 47
#define LED3 48
#define LED4 49
int d = 1000;

void setup(){
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(LED4, OUTPUT);
 Serial.begin(9600);
}
long n;
int state=0, c=0;
int var = 0, old_var = 0;

void loop(){
var = digitalRead(2);
if(var == HIGH && old_var == LOW){
  state++;
  Serial.print("state =");
  Serial.println(state);
}
if(state==1){
  Serialinput();
}
if(state==2)
  led();
  old_var= var;
}
int seq[1000], count=0, old_count=0;
void Serialinput(){
  if(Serial.available()){
     n =Serial.parseInt();
     Serial.println(n);  
     que(n);
  }
}
void que(int n){
  long k=n, count=0;
    while(k >0)
    {
      k = k/10;
      count++;
    }
    int arr[count];
     for(int i = 0; i< count; i++){
       arr[i] = n%10;
       n = n/10;
    }
    for(int i = count-1; i>=0 ; i--)
      for(int j = 1; j<5; j++)
        if(arr[i] == j){
          seq[c] = arr[i];
          c++; break;
        }
}

void led(){
  int lednum; int w;
  for(int i = 0; i < c ; i++){
    w = seq[i];
    if(w==1)
     lednum = 46;
    else if(w==2)
      lednum = 47;
    else if(w==3)
      lednum = 48;
    else if(w==4)
      lednum = 49;
    else
      continue;
    Serial.println(w);
   ledon(lednum);
  }
  state = 0;
  c=0;
}


void ledon(int lednum){
  digitalWrite(lednum, HIGH);
  delay(d);
  digitalWrite(lednum, LOW);
}
