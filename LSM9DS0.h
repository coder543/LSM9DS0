#include "mbed.h"

#define ACCMAG_ADDR      0x3A
#define GYRO_ADDR        0xD6

//_X is accelerometer
//_M is magnetometer
//_G is gyro
#define REG_X_L_M        0x08
#define REG_X_H_M        0x09
#define REG_Y_L_M        0x0A
#define REG_Y_H_M        0x0B
#define REG_Z_L_M        0x0C
#define REG_Z_H_M        0x0D
#define REG_CTRL_1       0x20
#define REG_CTRL_2       0x21
#define REG_CTRL_3       0x22
#define REG_CTRL_4       0x23
#define REG_CTRL_5       0x24
#define REG_CTRL_6       0x25
#define REG_CTRL_7       0x26
#define REG_X_L_GX       0x28
#define REG_X_H_GX       0x29
#define REG_Y_L_GX       0x2A
#define REG_Y_H_GX       0x2B
#define REG_Z_L_GX       0x2C
#define REG_Z_H_GX       0x2D
#define REG_FIFO_CTRL    0x2E

#define POWER_OFF        0x00
#define POWER_ON         0x08
#define ODR_95_G         0x00
#define ODR_190_G        0x40
#define ODR_380_G        0x80
#define ODR_960_G        0xC0
#define BW_MIN_G         0x00
#define BW_LOW_G         0x10
#define BW_HIGH_G        0x20
#define BW_MAX_G         0x30

//ODR_X = 3.125 Hz * 2^(ODR_VAL - 1)
//1600 Hz is maximum
//1600 Hz = 3.125 Hz * 2^(0xA - 1)
//ODR is only the most significant 4 bits,
//therefore the second number must always be zero.
//ODR_VAL of zero turns off the accelerometer
#define ODR_OFF_X        0x00
#define ODR_1600_X       0xA0
#define X_ENABLE_X       0x01
#define Y_ENABLE_X       0x02
#define Z_ENABLE_X       0x04
#define XYZ_ENABLE_X (X_ENABLE_X | Y_ENABLE_X | Z_ENABLE_X)

#define TEMPSENSE_ON     0x80
#define ODR_100_M        0x1C
#define RES_HIGH_M       0x60

#define FIFO_MODE_STREAM 0x40

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