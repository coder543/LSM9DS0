#include "mbed.h"
#include "LSM9DS0.h"

// LSM9DS0 lsm9(I2C_SDA, I2C_SCL);
Serial pc(SERIAL_TX, SERIAL_RX);

int main()
{
	while (1) {
		pc.printf("This is a test.\n");
	}
	return 0;
}