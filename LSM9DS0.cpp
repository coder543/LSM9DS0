#include "mbed.h"
#include "LSM9DS0.h"

LSM9DS0::LSM9DS0(PinName cs_g, PinName cs_xm, PinName miso, PinName mosi, PinName sck)
{
	this->cs_g = new DigitalOut(cs_g);
	*this->cs_g = 1;
	this->cs_xm = new DigitalOut(cs_xm);
	*this->cs_xm = 1;

	spi = new SPI(mosi, miso, sck);
	spi->frequency(8000000);
	spi->format(8, 3);

	//turn on the LSM9DS0
	//also, set the gyro to:
	//ODR = 960Hz
	//high-pass cutoff = maximum frequency
	// Scale defaults to 245 degrees per second
	writeToRegister(GYRO, REG_CTRL_1, POWER_ON | ODR_960_G | BW_MAX_G);
	spi->write(*readFromRegister(GYRO, REG_CTRL_1, 1));

	//set the accelerometer to:
	//ODR = 1600Hz
	//Bandwidth = 773Hz
	//Scale = +/- 2G
	//All axes enabled
	writeToRegister(ACCMAG, REG_CTRL_1, ODR_1600_X | XYZ_ENABLE_X);
	writeToRegister(ACCMAG, REG_CTRL_2, BW_773_X | SCALE_2G_X);

	//set the magnetometer to:
	//ODR = 100Hz
	//High resolution
	writeToRegister(ACCMAG, REG_CTRL_5, ODR_100_M | RES_HIGH_M);

	//configure FIFO stream mode with a watermark of 24
	writeToRegister(ACCMAG, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
	writeToRegister(ACCMAG, REG_CTRL_0, FIFO_ENABLE);
	writeToRegister(GYRO, REG_FIFO_CTRL, FIFO_MODE_STREAM | 24);
	writeToRegister(GYRO, REG_CTRL_5, FIFO_ENABLE);
}

LSM9DS0::~LSM9DS0()
{
	delete spi;
	delete cs_g;
	delete cs_xm;
}

void LSM9DS0::writeToRegister(bool gyro, unsigned char reg, unsigned char value)
{
	DigitalOut* currentCS;
	//select the correct SPI and CS connections based on whether
	//we're talking to the gyro or the accelerometer
	if (gyro == true)
		currentCS = cs_g;
	else
		currentCS = cs_xm;
	//lower the CS line to tell the chip we're talking to it.
	*currentCS = 0;
	//The first byte of data tells it which register we're writing to,
	spi->write(reg & 0x3F); //force RW and MS to 0
	//The second tells it what value to write.
	spi->write(value);
	//raise it back up to end the transfer.
	*currentCS = 1;
}

unsigned char* LSM9DS0::readFromRegister(bool gyro, unsigned char reg, unsigned int count)
{
	//Here, we're going to write the address to the LSM9DS0 so it
	//knows which register to read, then we issue a read command.
	if (count == 0)
		return (unsigned char*)NULL;
	DigitalOut* currentCS;
	if (gyro == true)
		currentCS = cs_g;
	else
		currentCS = cs_xm;
	unsigned char* returnVal = new unsigned char[count];
	*currentCS = 0;
	// unsigned char* txreg = (unsigned char*)0x4001300C;
	// *txreg = (reg | 0x80) & 0xBF;
	spi->write((reg | 0x80) & 0xBF); //force RW to 1 and MS to 0.
	unsigned int i = 0;
	while (i < count)
		returnVal[i++] = spi->write(0x00);
	*currentCS = 1;
	return returnVal;
}


Option LSM9DS0::readAccel()
{
	Option retval;
	retval.errorcode = 0;
	
	//wait for data
	char fifo_src = *readFromRegister(ACCMAG, REG_FIFO_SRC, 1);
	spi->write(fifo_src);
	int count = 10;
	bool isEmpty = (fifo_src & FIFO_IS_EMPTY);
	while (isEmpty && (count-- > 0)) {
		fifo_src = *readFromRegister(ACCMAG, REG_FIFO_SRC, 1);
		spi->write(fifo_src);
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
	short tmpval = *readFromRegister(ACCMAG, REG_X_H_GX, 1);
	tmpval = (tmpval << 8) | *readFromRegister(ACCMAG, REG_X_L_GX, 1);
	retval.val.arrayval.data[0] = tmpval;
	
	//retrieve the Y acceleration and store it into the second element
	tmpval = *readFromRegister(ACCMAG, REG_Y_H_GX, 1);
	tmpval = (tmpval << 8) | *readFromRegister(ACCMAG, REG_Y_L_GX, 1);
	retval.val.arrayval.data[1] = tmpval;
	
	//retrieve the Z acceleration and store it into the third element
	tmpval = *readFromRegister(ACCMAG, REG_Z_H_GX, 1);
	tmpval = (tmpval << 8) | *readFromRegister(ACCMAG, REG_Z_L_GX, 1);
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