#include "mbed.h"
#include "LSM9DS0.h"

DigitalOut leda(LED1);
LSM9DS0::LSM9DS0(PinName sda, PinName scl)
{
	i2c = new I2C(sda, scl);

	//turn on the LSM9DS0, set the ODR to 960Hz, and the high-pass cutoff freq to maximum
	writeToRegister(GYRO_ADDR, REG_CTRL_1, POWER_ON | ODR_960_G | BW_MAX_G);
	writeToRegister(ACCMAG_ADDR, REG_CTRL_1, ODR_1600_X | XYZ_ENABLE_X);
	writeToRegister(ACCMAG_ADDR, REG_CTRL_5, ODR_100_M | RES_HIGH_M);

	//configure stream mode with a watermark of 24
	writeToRegister(ACCMAG_ADDR, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
	writeToRegister(GYRO_ADDR, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
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