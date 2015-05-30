#include "mbed.h"
#include "LSM9DS0.h"

DigitalOut leda(LED1);
LSM9DS0::LSM9DS0(PinName sda, PinName scl)
{
	leda = 0;
	i2c = new I2C(sda, scl);
	//testing to demonstrate I2C functionality
	status2 = i2c->write(12, "test", 5);
	leda = 1;
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