#ifndef LSM9DS0_H
#define LSM9DS0_H

#include "mbed.h"
#include "LSM9DS0_constants.h"
#include "Option.h"

class LSM9DS0
{
private:
	SPI* spi_g;
	SPI* spi_xm;
	DigitalOut* cs_g;
	DigitalOut* cs_xm;

	//reg is the register
	void writeToRegister(bool gyro, unsigned char reg, unsigned char value);
	unsigned char* readFromRegister(bool gyro, unsigned char reg, unsigned int count);

public:
	LSM9DS0(PinName cs_g, PinName cs_xm, PinName miso_g, PinName miso_xm, PinName mosi_g, PinName mosi_xm, PinName sck_g, PinName sck_xm);
	~LSM9DS0();
	
	//Optionally returns a three element array of values: x, y, and z
	Option readAccel();
	Option readGyro();
	Option readMagneto();

	Option setScale(int scale); //set scale (i.e. 2G, 4G, etc)
};

#endif