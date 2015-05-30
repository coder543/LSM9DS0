#include "mbed.h"
#include "LSM9DS0.h"

// LSM9DS0 lsm9(I2C_SDA, I2C_SCL);
Serial pc(SERIAL_TX, SERIAL_RX);

DigitalOut led(LED1);

int main()
{
	pc.printf("starting up...\r\n");
	wait(1);
	pc.printf("starting I2C.\r\n");
	led = 1;
	LSM9DS0 lsm9(I2C_SDA, I2C_SCL);
	led = 0;
	pc.printf("finished with status: %i, %i.\r\n", lsm9.status1, lsm9.status2);
	return 0;
}