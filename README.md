
# LSM9DS0
A small, simple LSM9DS0 driver for the STM32-F334R8 (but it should work on similar systems and be easily portable)

This driver is part of the work I'm doing for Google Summer of Code 2015.

To use this driver is relatively straightforward. Simply creating and initializing an instance of the LSM9DS0 driver will immediately configure the LSM9DS0 with some sane defaults, along with starting the actual data collection. After that, simply call `readAccel()` to get a vector of acceleration values out of the onboard buffer in the LSM9DS0, and repeat that for `readGyro()` or `readMagneto()`, depending on what data you want. There are also functions to set the scale of each sensor, should you want to adjust that away from the defaults, which are +/- 2G on the accelerometer, 245 degrees per second on the gyro, and +/- 2 guass for the magnetometer. To set the scales, use constants from the `LSM9DS0_constants.h` file. You will also find some useful functions in `LSM9DS0_helper.h` that help with converting from the raw integer values coming out of the LSM9DS0 into scaled floating point values that respect units more properly.

If you find a bug, or need access to a feature of the LSM9DS0 that isn't currently exposed, send me a message at my github username @ gmail.com, but for most people's needs, I believe this driver will probably suffice.
