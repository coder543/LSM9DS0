# This file was automagically generated by mbed.org. For more information, 
# see http://mbed.org/handbook/Exporting-to-GCC-ARM-Embedded

GCC_BIN = 
PROJECT = LSM9DS0_demo
OBJECTS = ./demo.o ./LSM9DS0.o ./LSM9DS0_helper.o
SYS_OBJECTS = ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_pwr.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/retarget.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_hrtim.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_flash_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_nor.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_opamp.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/system_stm32f3xx.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_dac_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_smartcard_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_irda.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_rcc_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/board.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_i2c.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_tsc.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_adc_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_spi.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_i2s_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_flash.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_uart.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/cmsis_nvic.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_sram.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_cortex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_wwdg.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_sdadc.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/mbed_overrides.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_rtc_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_i2s.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_pccard.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_dma.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_smartcard.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_dac.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_pcd_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_tim.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_i2c_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_nand.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_opamp_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/startup_stm32f334x8.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_crc.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_pwr_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_adc.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_ll_fmc.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_can.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_cec.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_tim_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_rcc.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_rtc.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/hal_tick.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_smbus.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_uart_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_crc_ex.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_iwdg.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_usart.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_comp.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_pcd.o ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/stm32f3xx_hal_gpio.o 
INCLUDE_PATHS = -I. -I./mbed -I./mbed/TARGET_NUCLEO_F334R8 -I./mbed/TARGET_NUCLEO_F334R8/TARGET_STM -I./mbed/TARGET_NUCLEO_F334R8/TARGET_STM/TARGET_STM32F3 -I./mbed/TARGET_NUCLEO_F334R8/TARGET_STM/TARGET_STM32F3/TARGET_NUCLEO_F334R8 -I./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM 
LIBRARY_PATHS = -L./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM 
LIBRARIES = -lmbed 
LINKER_SCRIPT = ./mbed/TARGET_NUCLEO_F334R8/TOOLCHAIN_GCC_ARM/STM32F334x8.ld

############################################################################### 
AS      = $(GCC_BIN)arm-none-eabi-as
CC      = $(GCC_BIN)arm-none-eabi-gcc
CPP     = $(GCC_BIN)arm-none-eabi-g++
LD      = $(GCC_BIN)arm-none-eabi-gcc
OBJCOPY = $(GCC_BIN)arm-none-eabi-objcopy
OBJDUMP = $(GCC_BIN)arm-none-eabi-objdump
SIZE 	= $(GCC_BIN)arm-none-eabi-size

CPU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=$(FLOAT_ABI)
CC_FLAGS = $(CPU) -c -g -fno-common -fmessage-length=0 -Wall -fno-exceptions -ffunction-sections -fdata-sections -fomit-frame-pointer
CC_FLAGS += -MMD -MP
CC_SYMBOLS = -DTARGET_NUCLEO_F334R8 -DTARGET_M4 -DTARGET_CORTEX_M -DTARGET_STM -DTARGET_STM32F3 -DTARGET_STM32F334R8 -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -D__CORTEX_M4 -DARM_MATH_CM4 -D__FPU_PRESENT=1 -DMBED_BUILD_TIMESTAMP=1432758582.77 -D__MBED__=1 -DTARGET_FF_ARDUINO -DTARGET_FF_MORPHO 

LD_FLAGS = $(CPU) -Wl,--gc-sections --specs=nano.specs -u _printf_float -u _scanf_float -Wl,--wrap,main
LD_FLAGS += -Wl,-Map=$(PROJECT).map,--cref
LD_SYS_LIBS = -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys


ifeq ($(HARDFP),1)
	FLOAT_ABI = hard
else
	FLOAT_ABI = softfp
endif

ifeq ($(DEBUG), 1)
  CC_FLAGS += -DDEBUG -O0
else
  CC_FLAGS += -DNDEBUG -Os
endif

all: $(PROJECT).bin $(PROJECT).hex 

clean:
	rm -f $(PROJECT).bin $(PROJECT).elf $(PROJECT).hex $(PROJECT).map $(PROJECT).lst $(OBJECTS) $(DEPS)

.s.o:
	$(AS) $(CPU) -o $@ $<

.c.o:
	$(CC)  $(CC_FLAGS) $(CC_SYMBOLS) -std=gnu99   $(INCLUDE_PATHS) -o $@ $<

.cpp.o:
	$(CPP) $(CC_FLAGS) $(CC_SYMBOLS) -std=gnu++98 -fno-rtti $(INCLUDE_PATHS) -o $@ $<


$(PROJECT).elf: $(OBJECTS) $(SYS_OBJECTS)
	$(LD) $(LD_FLAGS) -T$(LINKER_SCRIPT) $(LIBRARY_PATHS) -o $@ $^ $(LIBRARIES) $(LD_SYS_LIBS) $(LIBRARIES) $(LD_SYS_LIBS)
	$(SIZE) $@

$(PROJECT).bin: $(PROJECT).elf
	@$(OBJCOPY) -O binary $< $@

$(PROJECT).hex: $(PROJECT).elf
	@$(OBJCOPY) -O ihex $< $@

$(PROJECT).lst: $(PROJECT).elf
	@$(OBJDUMP) -Sdh $< > $@

lst: $(PROJECT).lst

size:
	$(SIZE) $(PROJECT).elf

DEPS = $(OBJECTS:.o=.d) $(SYS_OBJECTS:.o=.d)
-include $(DEPS)
