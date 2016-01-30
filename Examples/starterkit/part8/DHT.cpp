/*
 * DHT.cpp
 *
 *  Created on: 2015-4-27
 *      Author: Administrator
 */
#include "DHT11.h"
#include <Arduino.h>
#define TIMEOUT 10000

DHT11::DHT11(uint8_t DHTpin)
{
 Dhtpin=DHTpin;
}

byte DHT11::start()
{
	// INIT BUFFERVAR TO RECEIVE DATA
	uint8_t cnt = 7;
	uint8_t idx = 0;

	// EMPTY BUFFER
	for (int i=0; i< 5; i++) DHT11data[i] = 0;

	// REQUEST SAMPLE
	pinMode(Dhtpin, OUTPUT);
	digitalWrite(Dhtpin, LOW);
	delay(20);
	digitalWrite(Dhtpin, HIGH);
	delayMicroseconds(40);
	pinMode(Dhtpin, INPUT);

	// GET ACKNOWLEDGE or TIMEOUT
	unsigned int loopCnt = TIMEOUT;
	while(digitalRead(Dhtpin) == LOW)
		if (loopCnt-- == 0) return -2;

	loopCnt = TIMEOUT;
	while(digitalRead(Dhtpin) == HIGH)
		if (loopCnt-- == 0) return -2;

	// READ THE OUTPUT - 40 DHT11data => 5 BYTES
	for (int i=0; i<40; i++)
	{
		loopCnt = TIMEOUT;
		while(digitalRead(Dhtpin) == LOW)
			if (loopCnt-- == 0) return -2;

		unsigned long t = micros();

		loopCnt = TIMEOUT;
		while(digitalRead(Dhtpin) == HIGH)
			if (loopCnt-- == 0) return -2;

		if ((micros() - t) > 40) DHT11data[idx] |= (1 << cnt);
		if (cnt == 0)   // next byte?
		{
			cnt = 7;
			idx++;
		}
		else cnt--;
	}

	return 0;

}



/////////////////////////////////////////////////////
//
// PUBLIC
//


// return values:
//  0 : OK
// -1 : checksum error
// -2 : timeout
int DHT11::read11()
{
	// READ VALUES
	int rv = start();
	if (rv != 0) return rv;

	// CONVERT AND STORE
	humidity    = DHT11data[0];  // DHT11data[1] == 0;
	temperature = DHT11data[2];  // DHT11data[3] == 0;

	// TEST CHECKSUM
	uint8_t sum = DHT11data[0] + DHT11data[2]; // DHT11data[1] && DHT11data[3] both 0
	if (DHT11data[4] != sum) return -1;

	return 0;
}

// return values:
//  0 : OK
// -1 : checksum error
// -2 : timeout
int DHT11::read22()
{
	// READ VALUES
	int rv = start();
	if (rv != 0) return rv;

	// CONVERT AND STORE
	humidity=word(DHT11data[0], DHT11data[1]) * 0.1;

	int sign = 1;
	if (DHT11data[2] & 0x80) // negative temperature
	{
		DHT11data[2] = DHT11data[2] & 0x7F;
		sign = -1;
	}
	temperature = sign * word(DHT11data[2], DHT11data[3]) * 0.1;


	// TEST CHECKSUM
	uint8_t sum = DHT11data[0] + DHT11data[1] + DHT11data[2] + DHT11data[3];
	if (DHT11data[4] != sum) return -1;

	return 0;
}

//
// END OF FILE
//
