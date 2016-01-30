/*part6  USE Soil moisture CONTROL Relay
 According to the intensity of light motor speed control */
int soil= A0;// The A0 pin,read Soil moisture
int relay = 6;// The 6 pin,driving the Relay
void setup() {
  pinMode(soil,INPUT);// initialize the soil pin as an input.
  pinMode(relay,OUTPUT);// initialize the relay pin as an output.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
    int value=analogRead(soil);
    if(value>200){//set the default value ,you can set it then more or less to do something
    digitalWrite(relay,HIGH);//turn on the relay
    }else digitalWrite(relay,LOW);//turn off the relay
}

