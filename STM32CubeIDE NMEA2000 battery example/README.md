
# NMEA2000 STM32 battery example

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

---
### Used libraries (Linked git submodules):
  - NMEA2000 library https://github.com/ttlappalainen/NMEA2000
  - NMEA2000_STM32 CAN library https://github.com/minoseigenheer/NMEA2000_STM32
  - STM32_CAN library https://github.com/minoseigenheer/STM32_CAN
  - STM32 HAL for your MCU
  
```
git pull --recurse-submodules
git submodule update --remote --recursive
```

---
### STM23CubeIDE settings 
Check the NMEA2000_STM32 STM32CubeIDE setup guide...
https://github.com/minoseigenheer/NMEA2000_STM32


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
