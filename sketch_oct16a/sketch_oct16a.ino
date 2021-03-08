
#define LED1 46
#define LED2 47
#define LED3 48
#define LED4 49
volatile unsigned long last_int_time = 0;
volatile unsigned long int_time;
volatile unsigned long last_int_time2 = 0;
volatile unsigned long int_time2;
volatile int debounceGuard = 500;
volatile int state = LOW;
int d = 2000;

void setup(){
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(LED4, OUTPUT);
 Serial.begin(9600);
 attachInterrupt(0,Serialinput, RISING);
}
void loop(){

}
long n =0;
void Serialinput(){
  int_time = millis();
  if(int_time - last_int_time > debounceGuard){
  while(!Serial.available());
  n =Serial.parseInt();
  Serial.println(n);
  state = !state;
  if(state == 1){
    detachInterrupt(0);
    attachInterrupt(0, led, RISING);
   }
  last_int_time = int_time;
  }
 
 }


void led(){
  int_time = millis();
  if(int_time2 - last_int_time2 > debounceGuard){
  int lednum, w;
  int count=0;
  int c=0;
  long k=n;
    while(k >0)
    {
      k = k/10;
      count++;
     }
  int seq[count];
  for(int i = 0; i< count; i++){
     w = n%10;
     n = n/10;
    seq[i] = w;
  }
  for(int i = sizeof(seq)/2 -1; i >=0 ; i--){
    w = seq[i];
    if(w==1)
      lednum = 48;
    else if(w==2)
      lednum = 49;
    /*else if(w==3)
      lednum = 48;
    else if(w==4)
      lednum = 49;*/
    else
      continue;
    Serial.println(w);
    ledon(lednum);
  }  last_int_time2 = int_time2;
  n=0;
}}

void ledon(int lednum){
  digitalWrite(lednum, HIGH);
  delay(d);
  digitalWrite(lednum, LOW);
  }
