int pir = A0; // read PIR
int motor  = 6; // driving the motor
void setup() {
  pinMode(pir, INPUT); // PIR as an input
  pinMode(motor, OUTPUT); //motor as an output 
}

void loop() {
  if(digitalRead(pir) == HIGH)
  {
    digitalWrite(motor, HIGH);
    delay(1000);
    digitalWrite(motor, LOW);//turn off the motor
  }

}
