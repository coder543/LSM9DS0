#ifndef LSM9DS0_H
#define LSM9DS0_H

#include "mbed.h"
#include "LSM9DS0_constants.h"
#include <vector>

struct Triple
{
	short x;
	short y;
	short z;
};

class LSM9DS0
{
private:
	SPI* spi;
	DigitalOut* cs_g;
	DigitalOut* cs_xm;

	//reg is the register
	void writeToRegister(bool gyro, unsigned char reg, unsigned char value);
	unsigned char readFromRegister(bool gyro, unsigned char reg);

public:
	LSM9DS0(PinName cs_g, PinName cs_xm, PinName miso, PinName mosi, PinName sck);
	~LSM9DS0();
	
	//Returns a three element array of values: x, y, and z
	vector<Triple> readAccel();
	Triple readMagneto();
	vector<Triple> readGyro();


	//use appropriate scale constants from the constants header
	void setGyroScale(char scale);
	void setAccScale(char scale);
	void setMagScale(char scale);
};

#endif