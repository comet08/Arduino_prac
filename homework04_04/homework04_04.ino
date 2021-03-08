#define buttonIn 47
#define ledOut 45
#define speakerOut 49
#define c3 7692 // 130 Hz
#define d3 6802 // 147 Hz
#define e3 6060 // 165 Hz
#define f3 5714 // 175 Hz
#define g3 5102 // 196 Hz
#define a3 4545 // 220 Hz
#define b3 4048 // 247 Hz
#define c4 3830 // 261 Hz
#define d4 3400 // 294 Hz
#define e4 3038 // 329 Hz
#define f4 2864 // 349 Hz
#define g4 2550 // 392 Hz
#define a4 2272 // 440 Hz
#define b4 2028 // 493 Hz
#define c5 1912 // 523 Hz
#define r1 0
int melody[] = {c4, c4, e4, e4, a3, a3, c4, e4, d4, d4, f4, f4, g3, g3, b3, b3, r1};
int beats[] = {22, 10, 22, 10, 22, 10, 24, 8, 22, 10, 22, 10, 22, 10, 22, 10, 16};
int MAX_MELODY = sizeof(melody)/2;
long tempo = 15000;
int pause = 10;
int tone_ = c4;
int beat = 0;
long duration = 0;
void play_tone(){
 long elapsed_time = 0;
 if( tone_ > 0 ){
 while( elapsed_time < duration ){
 if( elapsed_time + tone_ <= duration ){
 digitalWrite(speakerOut,HIGH);
 digitalWrite(ledOut,HIGH);
 delayMicroseconds(tone_ / 2);
 digitalWrite(speakerOut,LOW);
 digitalWrite(ledOut,LOW);
 delayMicroseconds(tone_ / 2);
 }
 elapsed_time += tone_;
 }
 }
 else{
 delayMicroseconds(duration);
 }
 delay(pause);
}
void setup(){
 pinMode(buttonIn, INPUT);
 pinMode(ledOut, OUTPUT);
 pinMode(speakerOut, OUTPUT);
}
int val;
void loop(){
 val = digitalRead(buttonIn);
 if (val == HIGH) {
 for(int i = 0; i < MAX_MELODY ; i++ ){
 tone_ = melody[i];
 beat = beats[i];

 duration = beat * tempo;
 play_tone();
 }
 }
 else{
 digitalWrite(ledOut,LOW);
 delay(100);
 }

}
