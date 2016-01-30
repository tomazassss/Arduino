/*part3  USE Vibration sensors CONTROL Passive buzzer
 Knock on the table, the buzzer will ring */
int vibration = A0;// The A0 pin,read Vibration sensors
int buzzer = 6;// The 6 pin,driving the Passive buzzer,the pin must PWM out(3 5 6 9 10 11)
void setup() {
  pinMode(vibration,INPUT_PULLUP);// initialize the vibration pin as an input.
  pinMode(buzzer,OUTPUT);// initialize the buzzer pin as an output.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  if(digitalRead(vibration)==HIGH){ 
    analogWrite(buzzer,200);//driver Passive buzzer must PWM,so analogWrite,200 is PWM value,max 1024
    delay(1000);// wait for 1000 microsecond
    analogWrite(buzzer,0); //turn off the buzzer
 } }

