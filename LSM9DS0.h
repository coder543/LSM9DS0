#ifndef LSM9DS0_H
#define LSM9DS0_H

#include "mbed.h"
#include "LSM9DS0_constants.h"
#include "Option.h"

class LSM9DS0
{
private:
	I2C* i2c;

	//reg is the register
	Option writeToRegister(int addr, unsigned char reg, unsigned char value);
	Option readFromRegister(int addr, unsigned char reg);

public:
	LSM9DS0(PinName sda, PinName scl);
	~LSM9DS0();
	
	//Optionally returns a three element array of values: x, y, and z
	Option readAccel();
	Option readGyro();
	Option readMagneto();

	Option setScale(int scale); //set scale (i.e. 2G, 4G, etc)
};

#endif