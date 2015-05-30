#include "mbed.h"
#include "LSM9DS0.h"

LSM9DS0::LSM9DS0(PinName sda, PinName scl)
{
	i2c = new I2C(sda, scl);
}

LSM9DS0::~LSM9DS0()
{

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