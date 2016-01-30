/*
 * DHT11.h
 *
 *  Created on: 2015-4-27
 *      Author: Administrator
 */

#ifndef DHT11_H_
#define DHT11_H_
#include <Arduino.h>

#define DHT11_LIB_VERSION "1.0"

class DHT11
{
  public:
	DHT11(uint8_t);
	byte DHT11data[5];
	int read11();
	int read22();
	byte read_dht11_dat(void);
    byte start(void);//send start bits and get data

  private:
    uint8_t Dhtpin;
    double humidity;
    double temperature;
};

#endif /* DHT11_H_ */
