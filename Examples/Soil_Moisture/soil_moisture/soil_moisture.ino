int soil = A0; //read soil moisture
int relay = 6; // driving the relay
void setup() {
  Serial.begin(9600);
  pinMode(soil, INPUT); 
  pinMode(relay, OUTPUT);
}

void loop() {
  int value = analogRead(soil);
  if(value > 200)
  {
   digitalWrite(relay, HIGH); // turn on the relay
   Serial.println(value);
  }
  else
  {
    digitalWrite(relay, LOW); // turn off thw relay
  }
}
