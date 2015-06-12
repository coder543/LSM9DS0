#include "mbed.h"
#include "LSM9DS0.h"

#define unwrapchar(optional) optional.val.charval;\
	if (optional.errorcode) {\
		retval.errorcode = optional.errorcode;\
		return retval;\
	}

DigitalOut leda(LED1);
LSM9DS0::LSM9DS0(PinName sda, PinName scl)
{
	i2c = new I2C(sda, scl);

	//turn on the LSM9DS0, set the ODR to 960Hz, and the high-pass cutoff freq to maximum
	writeToRegister(GYRO_ADDR, REG_CTRL_1, POWER_ON | ODR_960_G | BW_MAX_G);

	writeToRegister(ACCMAG_ADDR, REG_CTRL_1, ODR_1600_X | XYZ_ENABLE_X);
	writeToRegister(ACCMAG_ADDR, REG_CTRL_2, BW_773_X | SCALE_2G_X);

	writeToRegister(ACCMAG_ADDR, REG_CTRL_5, ODR_100_M | RES_HIGH_M);

	//configure stream mode with a watermark of 24
	writeToRegister(ACCMAG_ADDR, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
	writeToRegister(GYRO_ADDR, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
}

LSM9DS0::~LSM9DS0()
{
	delete i2c;
}

Option LSM9DS0::writeToRegister(int addr, unsigned char reg, unsigned char value)
{
	char writeBuf[2];
	writeBuf[0] = reg;
	writeBuf[1] = value;
	Option retval;
	retval.errorcode = i2c->write(addr, writeBuf, 2);
	return retval;
}

Option LSM9DS0::readFromRegister(int addr, unsigned char reg)
{
	Option retval;
	retval.errorcode = i2c->write(addr, (char*)&reg, 1);
	if (retval.errorcode)
		return retval;
	retval.errorcode = i2c->read(addr, (char*)&retval.val.charval, 1);
	return retval;
}

Option LSM9DS0::readAccel()
{
	Option retval;
	retval.errorcode = 0;
	char fifo_src = unwrapchar(readFromRegister(ACCMAG_ADDR, REG_FIFO_SRC));
	while (fifo_src | FIFO_IS_EMPTY)
		fifo_src = unwrapchar(readFromRegister(ACCMAG_ADDR, REG_FIFO_SRC));
	
	return retval;
}

Option LSM9DS0::readGyro()
{
	Option retval;
	retval.errorcode = 0;
	return retval;
}

Option LSM9DS0::readMagneto()
{
	Option retval;
	retval.errorcode = 0;
	return retval;
}

Option LSM9DS0::setScale(int scale)
{
	Option retval;
	retval.errorcode = 0;
	return retval;
}