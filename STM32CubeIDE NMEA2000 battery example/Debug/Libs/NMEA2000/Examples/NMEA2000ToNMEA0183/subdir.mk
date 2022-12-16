################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/BoardSerialNumber.cpp \
../Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/N2kDataToNMEA0183.cpp \
../Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/main.cpp 

OBJS += \
./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/BoardSerialNumber.o \
./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/N2kDataToNMEA0183.o \
./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/main.o 

CPP_DEPS += \
./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/BoardSerialNumber.d \
./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/N2kDataToNMEA0183.d \
./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/main.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/%.o Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/%.su: ../Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/%.cpp Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/EMUS_NMEA2000_gateway/STM32 CAN gateway/STM32_NMEA2000_CAN_gateway_hardware/STM32CubeIDE NMEA2000 battery example/Libs/NMEA2000/src" -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/EMUS_NMEA2000_gateway/STM32 CAN gateway/STM32_NMEA2000_CAN_gateway_hardware/STM32CubeIDE NMEA2000 battery example/Libs/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-NMEA2000-2f-Examples-2f-NMEA2000ToNMEA0183

clean-Libs-2f-NMEA2000-2f-Examples-2f-NMEA2000ToNMEA0183:
	-$(RM) ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/BoardSerialNumber.d ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/BoardSerialNumber.o ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/BoardSerialNumber.su ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/N2kDataToNMEA0183.d ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/N2kDataToNMEA0183.o ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/N2kDataToNMEA0183.su ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/main.d ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/main.o ./Libs/NMEA2000/Examples/NMEA2000ToNMEA0183/main.su

.PHONY: clean-Libs-2f-NMEA2000-2f-Examples-2f-NMEA2000ToNMEA0183

