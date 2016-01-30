/*part4  USE PIR CONTROL Motor
 If someone passing from the front, the motor will turn */
int pir = A0;// The A0 pin,read PIR
int motor = 6;// The 6 pin,driving the motor
void setup() {
  pinMode(pir,INPUT);// initialize the PIR pin as an input.
  pinMode(motor,OUTPUT);// initialize the motor pin as an output.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  if(digitalRead(pir)==HIGH){ 
    digitalWrite(motor,HIGH);
    delay(5000);// wait for 5000 microsecond
    digitalWrite(motor,LOW); //turn off the motor
 } }

