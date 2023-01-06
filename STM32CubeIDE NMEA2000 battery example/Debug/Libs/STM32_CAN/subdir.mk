################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Libs/STM32_CAN/STM32_CAN.cpp 

OBJS += \
./Libs/STM32_CAN/STM32_CAN.o 

CPP_DEPS += \
./Libs/STM32_CAN/STM32_CAN.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/STM32_CAN/%.o Libs/STM32_CAN/%.su: ../Libs/STM32_CAN/%.cpp Libs/STM32_CAN/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/EMUS_NMEA2000_gateway/STM32 CAN gateway/STM32_NMEA2000_CAN_gateway_hardware/STM32CubeIDE NMEA2000 battery example/Libs/NMEA2000/src" -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/EMUS_NMEA2000_gateway/STM32 CAN gateway/STM32_NMEA2000_CAN_gateway_hardware/STM32CubeIDE NMEA2000 battery example/Libs/NMEA2000_STM32" -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/EMUS_NMEA2000_gateway/STM32 CAN gateway/STM32_NMEA2000_CAN_gateway_hardware/STM32CubeIDE NMEA2000 battery example/Libs/STM32_CAN" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-STM32_CAN

clean-Libs-2f-STM32_CAN:
	-$(RM) ./Libs/STM32_CAN/STM32_CAN.d ./Libs/STM32_CAN/STM32_CAN.o ./Libs/STM32_CAN/STM32_CAN.su

.PHONY: clean-Libs-2f-STM32_CAN

