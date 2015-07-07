#ifndef LSM9DS0_helper
#define LSM9DS0_helper

float raw2dps(short raw, float dps);
float raw2gravities(short raw, short gravities);
float raw2gauss(short raw, short gauss);

#endif