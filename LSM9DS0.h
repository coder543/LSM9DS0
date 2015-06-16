#ifndef LSM9DS0_H
#define LSM9DS0_H

#include "mbed.h"
#include "LSM9DS0_constants.h"
#include "Option.h"

class LSM9DS0
{
private:
	SPI* spi;
	PinName cs;

	//reg is the register
	Option writeToRegister(int addr, unsigned char reg, unsigned char value);
	Option readFromRegister(int addr, unsigned char reg);
	
	void spiwrite(unsigned char reg, unsigned char value);
	int spiread(unsigned char reg);

public:
	LSM9DS0(PinName cs, PinName mosi, PinName miso, PinName sck);
	~LSM9DS0();
	
	//Optionally returns a three element array of values: x, y, and z
	Option readAccel();
	Option readGyro();
	Option readMagneto();

	Option setScale(int scale); //set scale (i.e. 2G, 4G, etc)
};

#endif