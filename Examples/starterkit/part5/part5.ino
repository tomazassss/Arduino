/*part5  USE Photodiode CONTROL Motor
 According to the intensity of light motor speed control */
int photodiode= A0;// The A0 pin,read Photodiode
int motor = 6;// The 6 pin,driving the motor
void setup() {
  pinMode(photodiode,INPUT);// initialize the photodiode pin as an input.
  pinMode(motor,OUTPUT);// initialize the motor pin as an output.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
    int speed=analogRead(photodiode)*2;//because the read max value is 512
    analogWrite(motor,speed);//According to the intensity of light motor speed control
  }

