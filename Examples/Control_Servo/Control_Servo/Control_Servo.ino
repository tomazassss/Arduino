#include <Servo.h>

int  encodeB = A0;
int servos = 6;
Servo servo;//get a servo cotroller
int angle = 90;
void setup() {
  pinMode(encodeB, INPUT);//initialize the encodeB pin as an input
  servo.attach(servos);
  attachInterrupt(0, start, FALLING);// set encodeA interrupt, this board interrupt0 is pin 2
}

void loop() {
}
void start()
{
  if(digitalRead(encodeB)==HIGH)
  {
    angle -= 30;
  }
  else{
    angle += 30;
  }
  if(angle >= 180)
  {
    angle = 180;
  }
  else if(angle <= 0)
  {
    angle = 0;
  }
  servo.write(angle);
}

