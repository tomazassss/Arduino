int photoDiode = A0;
int motor = 6;

void setup() {
  pinMode(photoDiode, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  int speed = analogRead(photoDiode)/2; //because the read max value is 512
  analogWrite(motor, speed); //According to the intensity of light motor speed control
}
