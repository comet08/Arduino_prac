#define LED 2 // LED connected to digital pin 2
 
void setup() {  
  pinMode(LED, OUTPUT); // sets the digital pin as output
} 
 
void loop() {  
  digitalWrite(LED, HIGH); // turns the LED on  
  delay(1000);    // waits for a second 
  digitalWrite(LED, LOW); // turns the LED off  
  delay(1000);    // waits for a second 
} 
