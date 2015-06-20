#include "mbed.h"
#include "LSM9DS0.h"

// LSM9DS0 lsm9(I2C_SDA, I2C_SCL);
// Serial pc(SERIAL_TX, SERIAL_RX);

// LSM9DS0::LSM9DS0(PinName cs_g, PinName cs_xm, PinName miso_g, PinName miso_xm, PinName mosi_g, PinName mosi_xm, PinName sck_g, PinName sck_xm)

int main()
{
	LSM9DS0 lsm9(D9, D7, D12, D11, D13);
	// lsm9.readAccel();
	// lsm9.readMagneto();
	// lsm9.readGyro();
	return 0;
}