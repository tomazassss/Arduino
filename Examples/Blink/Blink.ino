/*
  PART1 ARDUINO START Blink 
  Turns on LED for one second, then off for one second, repeatedly.
  Get the code from: Arduino IDE->File->Example->Basics->Blink
  Pin 13 has an LED connected on most Arduino boards.
 */
int led = 13;
  // the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}
 
// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(led, HIGH);    
  delay(1000);
  
  digitalWrite(led, LOW);
  delay(100);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
}
