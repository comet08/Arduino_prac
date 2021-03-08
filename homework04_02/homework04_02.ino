#define speakerOut 49
#define c4 3830 // 261 Hz
#define d4 3400 // 294 Hz
#define e4 3038 // 329 Hz
#define f4 2864 // 349 Hz
#define g4 2550 // 392 Hz
#define a4 2272 // 440 Hz
#define b4 2028 // 493 Hz
#define c5 1912 // 523 Hz
int melody[] = {c4, d4, e4, f4, g4, a4, b4, c5};
int tone_ = c4;
long duration = 200000;
long pause = 10;
void setup(){
 pinMode(speakerOut, OUTPUT);
}
void loop(){
 long elapsed_time = 0;
 for( int i = 0; i < 8; i++ ){
 tone_ = melody[i];
 elapsed_time = 0;
 while( elapsed_time < duration ){
 if( elapsed_time + tone_ <= duration ){
 digitalWrite(speakerOut,HIGH);
 delayMicroseconds(tone_ / 2);
 digitalWrite(speakerOut,LOW);
 delayMicroseconds(tone_ / 2);
 }
 elapsed_time += tone_;
 }
 delay(pause);
 }
}
