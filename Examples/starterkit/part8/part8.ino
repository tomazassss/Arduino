/* Part 8 USE DHT11 Temperature and humidity sensor and Segment
 * display Temperature and humidity*/
#include "DHT11.h" //load Temperature and humidity sensor library
#include "TM1637.h"//load Segment display library
#define CLK 4//pins definitions clk  for TM1637
#define DIO 5//pins definitions dio for TM1637
TM1637 tm1637(CLK,DIO);//get Segment display controler
DHT11 dht11(A0);//DHT11  A0
void setup(){
tm1637.init();
tm1637.set(BRIGHT_TYPICAL);}
void loop(){
	dht11.start();
	tm1637.display(3,12);//Temperature Unit
        tm1637.display(2,(dht11.DHT11data)[2]%10);
	tm1637.display(1,(dht11.DHT11data)[2]%100/10);
	delay(1000);
	tm1637.clearDisplay();
	tm1637.display(3,(dht11.DHT11data)[0]%10); // humidity  
	tm1637.display(2,(dht11.DHT11data)[0]%100/10);
	delay(1000);
}

