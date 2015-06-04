#include "mbed.h"
#include "LSM9DS0.h"

DigitalOut leda(LED1);
LSM9DS0::LSM9DS0(PinName sda, PinName scl)
{
	i2c = new I2C(sda, scl);
	// status2 = i2c->write(12, "test", 5);
}

LSM9DS0::~LSM9DS0()
{

}

int LSM9DS0::writeToRegister(char addr, char reg, char value)
{
	char writeBuf[2];
	writeBuf[0] = reg;
	writeBuf[1] = value;
	return i2c->write(addr, writeBuf, 2);
}

int LSM9DS0::readFromRegister(char addr, char reg, char* returnValue)
{
	int retVal = i2c->write(addr, &reg, 1);
	if (retVal)
		return retVal;
	return i2c->read(addr, returnValue, 1);
}

int LSM9DS0::readAccel(int* xyz)
{
	return 0;
}

int LSM9DS0::readGyro(int* xyz)
{
	return 0;
}

int LSM9DS0::readMagneto(int* xyz)
{
	return 0;
}

int LSM9DS0::setScale(int scale)
{
	return 0;
}