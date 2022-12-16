################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/ActisenseReader.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kDeviceList.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kGroupFunction.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kGroupFunctionDefaultHandlers.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kMaretron.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kMessages.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kMsg.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kStream.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kTimer.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/NMEA2000.cpp \
/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/Seasmart.cpp 

OBJS += \
./Libs/NMEA2000/src/ActisenseReader.o \
./Libs/NMEA2000/src/N2kDeviceList.o \
./Libs/NMEA2000/src/N2kGroupFunction.o \
./Libs/NMEA2000/src/N2kGroupFunctionDefaultHandlers.o \
./Libs/NMEA2000/src/N2kMaretron.o \
./Libs/NMEA2000/src/N2kMessages.o \
./Libs/NMEA2000/src/N2kMsg.o \
./Libs/NMEA2000/src/N2kStream.o \
./Libs/NMEA2000/src/N2kTimer.o \
./Libs/NMEA2000/src/NMEA2000.o \
./Libs/NMEA2000/src/Seasmart.o 

CPP_DEPS += \
./Libs/NMEA2000/src/ActisenseReader.d \
./Libs/NMEA2000/src/N2kDeviceList.d \
./Libs/NMEA2000/src/N2kGroupFunction.d \
./Libs/NMEA2000/src/N2kGroupFunctionDefaultHandlers.d \
./Libs/NMEA2000/src/N2kMaretron.d \
./Libs/NMEA2000/src/N2kMessages.d \
./Libs/NMEA2000/src/N2kMsg.d \
./Libs/NMEA2000/src/N2kStream.d \
./Libs/NMEA2000/src/N2kTimer.d \
./Libs/NMEA2000/src/NMEA2000.d \
./Libs/NMEA2000/src/Seasmart.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/NMEA2000/src/ActisenseReader.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/ActisenseReader.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kDeviceList.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kDeviceList.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kGroupFunction.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kGroupFunction.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kGroupFunctionDefaultHandlers.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kGroupFunctionDefaultHandlers.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kMaretron.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kMaretron.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kMessages.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kMessages.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kMsg.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kMsg.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kStream.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kStream.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/N2kTimer.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/N2kTimer.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/NMEA2000.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/NMEA2000.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Libs/NMEA2000/src/Seasmart.o: /Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter\ and\ Real/PROJECTEN/programeren/Embedded\ projects/NMEA2000/NMEA2000/src/Seasmart.cpp Libs/NMEA2000/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/DFU/Inc -I"/Users/minoseigenheer/Library/CloudStorage/OneDrive-BitterandReal/Bitter and Real/PROJECTEN/programeren/Embedded projects/NMEA2000/NMEA2000_STM32" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-NMEA2000-2f-src

clean-Libs-2f-NMEA2000-2f-src:
	-$(RM) ./Libs/NMEA2000/src/ActisenseReader.d ./Libs/NMEA2000/src/ActisenseReader.o ./Libs/NMEA2000/src/ActisenseReader.su ./Libs/NMEA2000/src/N2kDeviceList.d ./Libs/NMEA2000/src/N2kDeviceList.o ./Libs/NMEA2000/src/N2kDeviceList.su ./Libs/NMEA2000/src/N2kGroupFunction.d ./Libs/NMEA2000/src/N2kGroupFunction.o ./Libs/NMEA2000/src/N2kGroupFunction.su ./Libs/NMEA2000/src/N2kGroupFunctionDefaultHandlers.d ./Libs/NMEA2000/src/N2kGroupFunctionDefaultHandlers.o ./Libs/NMEA2000/src/N2kGroupFunctionDefaultHandlers.su ./Libs/NMEA2000/src/N2kMaretron.d ./Libs/NMEA2000/src/N2kMaretron.o ./Libs/NMEA2000/src/N2kMaretron.su ./Libs/NMEA2000/src/N2kMessages.d ./Libs/NMEA2000/src/N2kMessages.o ./Libs/NMEA2000/src/N2kMessages.su ./Libs/NMEA2000/src/N2kMsg.d ./Libs/NMEA2000/src/N2kMsg.o ./Libs/NMEA2000/src/N2kMsg.su ./Libs/NMEA2000/src/N2kStream.d ./Libs/NMEA2000/src/N2kStream.o ./Libs/NMEA2000/src/N2kStream.su ./Libs/NMEA2000/src/N2kTimer.d ./Libs/NMEA2000/src/N2kTimer.o ./Libs/NMEA2000/src/N2kTimer.su ./Libs/NMEA2000/src/NMEA2000.d ./Libs/NMEA2000/src/NMEA2000.o ./Libs/NMEA2000/src/NMEA2000.su ./Libs/NMEA2000/src/Seasmart.d ./Libs/NMEA2000/src/Seasmart.o ./Libs/NMEA2000/src/Seasmart.su

.PHONY: clean-Libs-2f-NMEA2000-2f-src

