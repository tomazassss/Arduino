/*
 * 
 */
int led = 5;                              //D5 driving led
int button = A0;                          // A0 read the button
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button, INPUT_PULLUP);
}
void loop()
{
  if(digitalRead(button) == LOW)
  {
    delay(200);
    digitalWrite(led, HIGH);
    while(1)
    {
      if(digitalRead(button) == LOW)
      {
        delay(200);
        digitalWrite(led, LOW);            //turn the led off
        break;
      }
    }
  }
}

