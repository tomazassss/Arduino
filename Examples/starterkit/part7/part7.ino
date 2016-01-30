/*part7  USE encode CONTROL Servos
Turn the rotary encoder control servos
  */
#include <Servo.h>//load servo library
int encodeB= A0;// The A0 pin,read encodeB
int servos = 6;// The 6 pin,driving the servos
Servo servo;//Get a servo controller
int angle=90;//set the servo default angle
void setup() {
  pinMode(encodeB,INPUT);// initialize the encodeB pin as an input.
  servo.attach(servos);
  attachInterrupt(0,start,FALLING);//set encodeA interrupt,this board interrupt0 is pin 2
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
}
void start(){
  if(digitalRead(encodeB)==HIGH){
    angle-=30;
    }else angle+=30;
    if(angle>=180)angle=180;
    else if(angle<=0)angle=0;
    servo.write(angle);
}
