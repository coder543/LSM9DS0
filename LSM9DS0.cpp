#include "mbed.h"
#include "LSM9DS0.h"

//inserts char value into end of assignment expression,
//then checks for an error code. If one is found, it
//propogates that error code to the next level on the
//call stack.
#define unwrapchar(optional) optional.val.charval;\
	if (optional.errorcode) {\
		retval.errorcode = optional.errorcode;\
		return retval;\
	}

DigitalOut leda(LED1);
LSM9DS0::LSM9DS0(PinName sda, PinName scl)
{
	i2c = new I2C(sda, scl);

	//turn on the LSM9DS0
	//also, set the gyro to:
	//ODR = 960Hz
	//high-pass cutoff = maximum frequency
	//Scale defaults to 245 degrees per second
	writeToRegister(GYRO_ADDR, REG_CTRL_1, POWER_ON | ODR_960_G | BW_MAX_G);

	//set the accelerometer to:
	//ODR = 1600Hz
	//Bandwidth = 773Hz
	//Scale = +/- 2G
	//All axes enabled
	writeToRegister(ACCMAG_ADDR, REG_CTRL_1, ODR_1600_X | XYZ_ENABLE_X);
	writeToRegister(ACCMAG_ADDR, REG_CTRL_2, BW_773_X | SCALE_2G_X);

	//set the magnetometer to:
	//ODR = 100Hz
	//High resolution
	writeToRegister(ACCMAG_ADDR, REG_CTRL_5, ODR_100_M | RES_HIGH_M);

	//configure FIFO stream mode with a watermark of 24
	writeToRegister(ACCMAG_ADDR, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
	writeToRegister(ACCMAG_ADDR, REG_CTRL_0, FIFO_ENABLE);
	writeToRegister(GYRO_ADDR, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
	writeToRegister(GYRO_ADDR, REG_CTRL_5, FIFO_ENABLE);
}

LSM9DS0::~LSM9DS0()
{
	delete i2c;
}

Option LSM9DS0::writeToRegister(int addr, unsigned char reg, unsigned char value)
{
	Option retval;
	//Prepare a buffer of data to be transferred to the LSM9DS0.
	char writeBuf[2];
	//The first byte of data tells it which register we're writing to,
	writeBuf[0] = reg;
	//The second tells it what value to write.
	writeBuf[1] = value;
	
	//write the buffer, and receive the error code
	retval.errorcode = i2c->write(addr, writeBuf, 2);
	return retval;
}

Option LSM9DS0::readFromRegister(int addr, unsigned char reg)
{
	//Here, we're going to write the address to the LSM9DS0 so it
	//knows which register to read, then we issue a read command.
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
	
	//wait for data
	char fifo_src = unwrapchar(readFromRegister(ACCMAG_ADDR, REG_FIFO_SRC));
	int count = 10;
	bool isEmpty = (fifo_src & FIFO_IS_EMPTY);
	while (isEmpty && (count-- > 0)) {
		fifo_src = unwrapchar(readFromRegister(ACCMAG_ADDR, REG_FIFO_SRC));
		isEmpty = (fifo_src & FIFO_IS_EMPTY);
	}
	if (count == 0)
	{
		retval.errorcode = 1;
		return retval;
	}
	//allocate memory for the sought data
	retval.val.arrayval.data = new unsigned short[3];
	retval.val.arrayval.length = 3;
	
	//retrieve the X acceleration and store it into the first element
	short tmpval = unwrapchar(readFromRegister(ACCMAG_ADDR, REG_X_H_GX));
	tmpval = (tmpval << 8) | unwrapchar(readFromRegister(ACCMAG_ADDR, REG_X_L_GX));
	retval.val.arrayval.data[0] = tmpval;
	
	//retrieve the Y acceleration and store it into the second element
	tmpval = unwrapchar(readFromRegister(ACCMAG_ADDR, REG_Y_H_GX));
	tmpval = (tmpval << 8) | unwrapchar(readFromRegister(ACCMAG_ADDR, REG_Y_L_GX));
	retval.val.arrayval.data[1] = tmpval;
	
	//retrieve the Z acceleration and store it into the third element
	tmpval = unwrapchar(readFromRegister(ACCMAG_ADDR, REG_Z_H_GX));
	tmpval = (tmpval << 8) | unwrapchar(readFromRegister(ACCMAG_ADDR, REG_Z_L_GX));
	retval.val.arrayval.data[2] = tmpval;
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