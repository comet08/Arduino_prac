#define speakerOut 49
#define c4 3830 // 261 Hz
#define d4 3400 // 294 Hz
#define e4 3038 // 329 Hz
#define f4 2864 // 349 Hz
#define g4 2550 // 392 Hz
#define a4 2272 // 440 Hz
#define b4 2028 // 493 Hz
#define c5 1912 // 523 Hz
int tone_ = e4;
void setup(){
 pinMode(speakerOut, OUTPUT);
}
void loop(){
 digitalWrite(speakerOut,HIGH);
 delayMicroseconds(tone_ / 2);
 digitalWrite(speakerOut,LOW);
 delayMicroseconds(tone_ / 2);
}
