
#define LED1 49
#define LED2 48
volatile unsigned long last_int_time = 0;
volatile unsigned long int_time;
volatile int debounceGuard = 500;
volatile int state = LOW;
int d = 1000;
void setup(){
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 attachInterrupt(0, ledToggle, RISING);
}
void loop(){
 led2Blink();
}
void led2Blink(){
 digitalWrite(LED1, HIGH);
 delay(d);
 digitalWrite(LED1, LOW);
 delay(d);
}
void ledToggle(){
 int_time = millis();
 if( int_time - last_int_time > debounceGuard ){
 state = !state;
 digitalWrite(LED2,state);

 last_int_time = int_time;
 }
}
