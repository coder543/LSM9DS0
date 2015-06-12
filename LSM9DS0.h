#include "mbed.h"
#include "LSM9DS0_constants.h"

struct Option
{
	int errorcode;
	union {
		unsigned int intval;
		unsigned short shortval;
		unsigned char charval;
		struct {
			unsigned short* data;
			unsigned char length;
		} arrayval;
	} val;
};

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