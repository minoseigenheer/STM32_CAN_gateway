
# NMEA2000 STM32 example

1. DC Detailed Status (PGN127506)
   - State-Of-Charge (SOC)
   - Time remaining
   - Amp hours left
2. Charger Status (PGN127507)
   - Charge state
3. Battery Status (PGN127508)
   - Battery pack voltage
   - Battery pack current
   - Battery pack highest temperature
4. Battery Configuration Status (PGN127513)
   - Static battery info like nominal voltage, chemistry... 


### Libs (Linked git submodules):
  - NMEA2000 library https://github.com/ttlappalainen/NMEA2000
  - NMEA2000_STM32 CAN library https://github.com/BitterAndReal/NMEA2000_STM32
  - STM32 HAL for your MCU

> Use the following command to update the submodules
> git submodule foreach git pull

---
### STM23CubeIDE settings 
If you are not very experienced with STM23CubeIDE this guide can help to configure a project for your own STM32 based hardware.
  - Create a STM32 C++ project in STM23CubeIDE
  - Select your MCU which will add the correct HAL to your project.
  - We can not directly call C++ from the main.c
    > Create your own application.cpp & application.hpp files with your C++ project setup() and loop() which are called from with extern "C" {...
    > From there you can include "NMEA2000.h" & "NMEA2000_STM32.hpp" and call the NMEA2000 methods. 
  - In Cube MX configure external clock settings of your MCU. 
    > CAN bus needs an external clock source!
  - Activate the CAN bus you want to use.
  - Enable the CAN RX1 interrupt in the NVIC settings
  - Enable the CAN TX interrupt in the NVIC settings
  - Copy the NMEA2000 and NMEA_STM32 library's to your "Libs" folders of your STM32Cube project. (or use linked folders)
  - Add the folders to the G++ compiler include paths:
    > - Select your project in the Project Explorer.
    > - go to: File > Properties > C/C++ Build > Settings > MCU G++ Compiler > Include paths
    > - Add the NMEA2000 and NMEA_STM32 library folders to the included paths
  - If you want to use the CAN init of the library, which sets the CAN baud rate and filters, disable the STM32CubeIDE generated code.
    > Navigate to “Project Manager” > “Advanced Settings” find MX_CAN#_Init” 
    > and enable “Do Not Generate Function Call”.
  - By default, the peripheral MSP initialization function HAL_CAN_MspInit (in stm32xxx_hal_msp.c) is automatically called and takes care of the configuration of the CAN_RX/TX GPIOs, enabling of the peripheral clock and enabling of the CAN interrupts
  - Check the following link for more NMEA2000 examples. https://github.com/ttlappalainen/NMEA2000/tree/master/Examples

---
Thanks for the great NMEA2000 CAN lib example Teensyx by ttlappalainen.
https://github.com/ttlappalainen/NMEA2000_Teensyx

---
## License

MIT license

Copyright (c) 2022 Minos Eigenheer

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
