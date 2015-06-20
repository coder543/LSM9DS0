#ifndef LSMCONSTANTS_H
#define LSMCONSTANTS_H

#define ACCMAG           false
#define GYRO             true

//_X is accelerometer
//_M is magnetometer
//_G is gyro
#define REG_STATUS_M     0x07
#define REG_X_L_M        0x08
#define REG_X_H_M        0x09
#define REG_Y_L_M        0x0A
#define REG_Y_H_M        0x0B
#define REG_Z_L_M        0x0C
#define REG_Z_H_M        0x0D
#define REG_CTRL_0       0x1F
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
#define REG_STATUS_X     0x27
#define REG_FIFO_CTRL    0x2E
#define REG_FIFO_SRC     0x2F

#define POWER_OFF_G      0x00
#define POWER_ON_G       0x08
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

#define BW_773_X         0x00
#define BW_194_X         0x40
#define BW_362_X         0x80
#define BW_50_X          0xC0
#define SCALE_2G_X       0x00
#define SCALE_4G_X       0x08
#define SCALE_6G_X       0x10
#define SCALE_8G_X       0x18
#define SCALE_16G_X      0x20

#define TEMPSENSE_ON     0x80
#define ODR_100_M        0x1C
#define RES_HIGH_M       0x60
#define NEW_DATA_M       0x0F
#define POWER_OFF_M      0x02
#define POWER_ON_M       0x00

#define FIFO_ENABLE      0x40
#define FIFO_MODE_STREAM 0x40
#define FIFO_IS_EMPTY    0x20

#endif