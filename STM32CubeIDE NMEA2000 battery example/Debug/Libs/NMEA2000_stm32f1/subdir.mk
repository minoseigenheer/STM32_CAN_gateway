################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000_stm32f1/NMEA2000_stm32f1.cpp 

OBJS += \
./Libs/NMEA2000_stm32f1/NMEA2000_stm32f1.o 

CPP_DEPS += \
./Libs/NMEA2000_stm32f1/NMEA2000_stm32f1.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/NMEA2000_stm32f1/NMEA2000_stm32f1.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000_stm32f1/NMEA2000_stm32f1.cpp Libs/NMEA2000_stm32f1/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000/src" -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_stm32f1" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-NMEA2000_stm32f1

clean-Libs-2f-NMEA2000_stm32f1:
	-$(RM) ./Libs/NMEA2000_stm32f1/NMEA2000_stm32f1.d ./Libs/NMEA2000_stm32f1/NMEA2000_stm32f1.o ./Libs/NMEA2000_stm32f1/NMEA2000_stm32f1.su

.PHONY: clean-Libs-2f-NMEA2000_stm32f1

