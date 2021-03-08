#define LED 40
int val1 =0, val2=0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
 val1 = analogRead(0);
 val2 = analogRead(1);

 digitalWrite(LED, HIGH);
 delay(val1+ val2);
 digitalWrite(LED, LOW);
 delay(val1+ val2);

}
