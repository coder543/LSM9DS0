#include "mbed.h"
#include "LSM9DS0.h"

// LSM9DS0 lsm9(I2C_SDA, I2C_SCL);
Serial pc(SERIAL_TX, SERIAL_RX);

// LSM9DS0::LSM9DS0(PinName cs_g, PinName cs_xm, PinName miso_g, PinName miso_xm, PinName mosi_g, PinName mosi_xm, PinName sck_g, PinName sck_xm)

float raw2dps(short raw, float dps)
{
	return (((float)raw) / 32768.0) * dps;
}

float raw2gravities(short raw, short gravities)
{
	return (((float)raw) / 32768.0) * gravities;
}

float raw2gauss(short raw, short gauss)
{
	return (((float)raw) / 32768.0) * gauss;
}

int main()
{
	LSM9DS0 lsm9(D9, D7, D12, D11, D13);
	pc.baud(115200);

	vector<Triple> accvals = lsm9.readAccel();
	for(std::vector<Triple>::iterator it = accvals.begin(); it != accvals.end(); ++it) {
	    pc.printf("ax: %f Gs\r\n", raw2gravities((*it).x, 2));
	    pc.printf("ay: %f Gs\r\n", raw2gravities((*it).y, 2));
	    pc.printf("az: %f Gs\r\n", raw2gravities((*it).z, 2));
	    pc.printf("\r\n");
	}

	Triple magvals = lsm9.readMagneto();
    pc.printf("mx: %f Gauss\r\n", raw2gauss(magvals.x, 2));
    pc.printf("my: %f Gauss\r\n", raw2gauss(magvals.y, 2));
    pc.printf("mz: %f Gauss\r\n", raw2gauss(magvals.z, 2));
    pc.printf("\r\n");

	vector<Triple> gyrovals = lsm9.readGyro();
	for(std::vector<Triple>::iterator it = gyrovals.begin(); it != gyrovals.end(); ++it) {
	    pc.printf("gx: %f dps\r\n", raw2dps((*it).x, 250));
	    pc.printf("gy: %f dps\r\n", raw2dps((*it).y, 250));
	    pc.printf("gz: %f dps\r\n", raw2dps((*it).z, 250));
	    pc.printf("\r\n");
	}
	return 0;
}