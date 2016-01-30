/*part2  USE BUTTON CONTROL LED
  Press the button, led lights, then press the button led is off*/
int led = 5;// The 5 pin,driving LED
int button = A0;// The A0 pin,read the button
void setup() {
  pinMode(led, OUTPUT);// initialize the LED pin as an output.
  pinMode(button, INPUT_PULLUP);// initialize the BUTTON pin as an input.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  if(digitalRead(button)==LOW){ 
  delay(200);// wait for 200 microsecond,Avoid pressing the button and read many times in this very short time
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  while(1){
    if(digitalRead(button)==LOW){ 
    delay(200);              
    digitalWrite(led, LOW);   // turn the LED off (LOW is the voltage level)
    break;                    //End of the while loop,Back to the main loop  
    }}
  }}

