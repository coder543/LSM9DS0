#include "mbed.h"
#include "LSM9DS0.h"

// LSM9DS0 lsm9(I2C_SDA, I2C_SCL);
// Serial pc(SERIAL_TX, SERIAL_RX);

int main()
{
	LSM9DS0 lsm9(I2C_SDA, I2C_SCL);
	lsm9.readAccel();
	return 0;
}