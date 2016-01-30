int vibration = A0; //A0 pin, read vibration pin as an output
int buzzer = 6;     // The D6 pin, driving the passive buzzer, the must PWM pin(3 5 6 9 10 11 on UNO)

void setup() {
  pinMode(vibration, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if(digitalRead(vibration) == HIGH)
  {
    analogWrite(buzzer, 200); //driver Passive buzzer must PWM, so analogWrite, 200 is PWM value, max 1024
    delay(1000);
    analogWrite(buzzer, 0);
  }
}
