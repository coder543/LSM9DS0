#include "mbed.h"
#include "LSM9DS0_constants.h"

class LSM9DS0
{
private:
	I2C* i2c;

	//reg is the register
	int writeToRegister(char addr, char reg, char value);
	int readFromRegister(char addr, char reg, char* returnValue);

public:
	LSM9DS0(PinName sda, PinName scl);
	~LSM9DS0();
	
	//each accepts a three-element array of ints, where it will store the
	//values it reads. It will return 0 for no error, nonzero for error.
	int readAccel(int* xyz);
	int readGyro(int* xyz);
	int readMagneto(int* xyz);

	int setScale(int scale); //set scale (i.e. 2G, 4G, etc)
};