#include <vector>
#include "LSM9DS0.h"

//will be used for chaining
#define readburst() spi->write(0x00);

LSM9DS0::LSM9DS0(PinName cs_g, PinName cs_xm, PinName miso, PinName mosi, PinName sck)
{
	this->cs_g = new DigitalOut(cs_g);
	*this->cs_g = 1;
	this->cs_xm = new DigitalOut(cs_xm);
	*this->cs_xm = 1;

	spi = new SPI(mosi, miso, sck);
	spi->frequency(8000000);
	spi->format(8, 3);

	//turn on the gyro
	//also, set the gyro to:
	//ODR = 960Hz
	//high-pass cutoff = maximum frequency
	// Scale defaults to 245 degrees per second
	writeToRegister(GYRO, REG_CTRL_1, POWER_ON_G | ODR_960_G | BW_MAX_G);

	//setting ODR automatically turns on accelerometer
	//set the accelerometer to:
	//ODR = 1600Hz
	//Bandwidth = 773Hz
	//Scale = +/- 2G
	//All axes enabled
	writeToRegister(ACCMAG, REG_CTRL_1, ODR_1600_X | XYZ_ENABLE_X);
	writeToRegister(ACCMAG, REG_CTRL_2, BW_773_X | SCALE_2G_X);

	//turn on the magnetometer
	//set the magnetometer to:
	//ODR = 100Hz
	//High resolution
	writeToRegister(ACCMAG, REG_CTRL_7, POWER_ON_M);
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

unsigned char LSM9DS0::readFromRegister(bool gyro, unsigned char reg)
{
	DigitalOut* currentCS;
	if (gyro == true)
		currentCS = cs_g;
	else
		currentCS = cs_xm;
	*currentCS = 0;
	//Here, we're going to write the address to the LSM9DS0 so it
	//knows which register to read, then we issue a read command.
	spi->write(reg | 0xc0); //force RW and MS to 1.
	unsigned char returnVal = (unsigned char)spi->write(0x00);
	*currentCS = 1;
	return returnVal;
}


vector<Triple> LSM9DS0::readAccel()
{
	vector<Triple> retval;
	
	//wait for data
	char fifo_src;
	bool isEmpty;
	unsigned char numVals;
	do {
		fifo_src = readFromRegister(ACCMAG, REG_FIFO_SRC);
		isEmpty = (fifo_src & FIFO_IS_EMPTY);
		numVals = (fifo_src & 0x1F);
	} while (isEmpty || numVals == 0);

	/* dynamic read expansion allows for the possibility of more data
	 * being generated while we're reading data out, so at the end it
	 * checks for new data and reads it out as well. An additional
	 * vector expansion is costly, especially if the number of values
	 * to be read is large as I've sometimes seen with my digital logic
	 * analyzer, therefore we cap the maximum expansion to 1.5*numVals
	 */
//#define DYNAMIC_READ_EXPANSION
#ifdef DYNAMIC_READ_EXPANSION
	unsigned char numValMax = numVals + (numVals >> 2);
	retval.reserve(numValMax);
#else
	retval.reserve(numVals);
#endif
	
	for (unsigned char i = 0; i < numVals; ++i)
	{
		Triple tmpval;
		//retrieve the X acceleration and store it into the first element
		tmpval.x = (readFromRegister(ACCMAG, REG_X_L_GX)) | ((readFromRegister(ACCMAG, REG_X_H_GX)) << 8);
		
		//retrieve the Y acceleration and store it into the second element
		tmpval.y = (readFromRegister(ACCMAG, REG_Y_L_GX)) | ((readFromRegister(ACCMAG, REG_Y_H_GX)) << 8);

		//retrieve the Z acceleration and store it into the third element
		tmpval.z = (readFromRegister(ACCMAG, REG_Z_L_GX)) | ((readFromRegister(ACCMAG, REG_Z_H_GX)) << 8);

		retval.push_back(tmpval);

#ifdef DYNAMIC_READ_EXPANSION
		if (i == numVals - 1 && numVals < numValMax)
		{
			fifo_src = readFromRegister(ACCMAG, REG_FIFO_SRC);
			isEmpty = (fifo_src & FIFO_IS_EMPTY);
			unsigned char valtmp = (fifo_src & 0x1F);
			numVals += valtmp;
			if (!isEmpty && valtmp > 0)
				numVals = (numVals < numValMax ? numVals : numValMax);
			else
				break;
		}
#endif
	}

	return retval;
}

Triple LSM9DS0::readMagneto()
{
	Triple retval;

	//wait for data
	char status_reg;
	bool hasData;
	do {
		status_reg = readFromRegister(ACCMAG, REG_STATUS_M);
		hasData = ((status_reg & NEW_DATA_M) == 0x0F);
	} while (!hasData);

	//retrieve the X acceleration and store it into the first element
	retval.x = (readFromRegister(ACCMAG, REG_X_L_M)) | ((readFromRegister(ACCMAG, REG_X_H_M)) << 8);
	
	//retrieve the Y acceleration and store it into the second element
	retval.y = (readFromRegister(ACCMAG, REG_Y_L_M)) | ((readFromRegister(ACCMAG, REG_Y_H_M)) << 8);

	//retrieve the Z acceleration and store it into the third element
	retval.z = (readFromRegister(ACCMAG, REG_Z_L_M)) | ((readFromRegister(ACCMAG, REG_Z_H_M)) << 8);


	return retval;
}

vector<Triple> LSM9DS0::readGyro()
{
	vector<Triple> retval;
		//wait for data
	char fifo_src;
	bool isEmpty;
	unsigned char numVals;
	do {
		fifo_src = readFromRegister(GYRO, REG_FIFO_SRC);
		isEmpty = (fifo_src & FIFO_IS_EMPTY);
		numVals = (fifo_src & 0x1F);
	} while (isEmpty || numVals == 0);

	/* dynamic read expansion allows for the possibility of more data
	 * being generated while we're reading data out, so at the end it
	 * checks for new data and reads it out as well. An additional
	 * vector expansion is costly, especially if the number of values
	 * to be read is large as I've sometimes seen with my digital logic
	 * analyzer, therefore we cap the maximum expansion to 1.5*numVals
	 */
//#define DYNAMIC_READ_EXPANSION
#ifdef DYNAMIC_READ_EXPANSION
	unsigned char numValMax = numVals + (numVals >> 2);
	retval.reserve(numValMax);
#else
	retval.reserve(numVals);
#endif
	
	for (unsigned char i = 0; i < numVals; ++i)
	{
		Triple tmpval;
		//retrieve the X acceleration and store it into the first element
		tmpval.x = (readFromRegister(GYRO, REG_X_L_GX)) | ((readFromRegister(GYRO, REG_X_H_GX)) << 8);
		
		//retrieve the Y acceleration and store it into the second element
		tmpval.y = (readFromRegister(GYRO, REG_Y_L_GX)) | ((readFromRegister(GYRO, REG_Y_H_GX)) << 8);

		//retrieve the Z acceleration and store it into the third element
		tmpval.z = (readFromRegister(GYRO, REG_Z_L_GX)) | ((readFromRegister(GYRO, REG_Z_H_GX)) << 8);

		retval.push_back(tmpval);

#ifdef DYNAMIC_READ_EXPANSION
		if (i == numVals - 1 && numVals < numValMax)
		{
			fifo_src = readFromRegister(GYRO, REG_FIFO_SRC);
			isEmpty = (fifo_src & FIFO_IS_EMPTY);
			unsigned char valtmp = (fifo_src & 0x1F);
			numVals += valtmp;
			if (!isEmpty && valtmp > 0)
				numVals = (numVals < numValMax ? numVals : numValMax);
			else
				break;
		}
#endif
	}
	return retval;
}

//the scale input is bit-masked to prevent the scale function
//from adjusting anything but scale.
void LSM9DS0::setGyroScale(char scale)
{
	writeToRegister(GYRO, REG_CTRL_4, scale & 0x30);
}

void LSM9DS0::setAccScale(char scale)
{
	writeToRegister(ACCMAG, REG_CTRL_2, BW_773_X | (scale & 0x38));
}

void LSM9DS0::setMagScale(char scale)
{
	writeToRegister(ACCMAG, REG_CTRL_6, scale & 0x60);
}
