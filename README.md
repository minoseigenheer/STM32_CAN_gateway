# STM32_NMEA2000_CAN_gateway
STM32F105 based dual CAN bus gateway with isolated NMEA2000 CAN


### Specs
```
- STM32F105RBT6 MCU with 2 internal CAN controllers
- CAN1 BMS (micro-fit 6-pin connector)
- CAN2 NMEA2000 isolated (M12 5-pin connector)
- 4-32V supply voltage
- RGB status LED
- USB-C for firmware updates
```
```
- Solder jumpers to use M12 male or female connectors.
- Solder jumpers for the CAN termination resistor.
- Solder jumpers for power output on CAN2 connector.
```
<img src="images/STM32 NMEA2000 CAN gateway render front.png" width="600"/>
<img src="images/STM32 NMEA2000 CAN gateway render back.png" width="600"/>

### EMUS BMS micro-fit 6p connector pinout
<img src="images/EMUS BMS micro-fit 6p connector.png" width="250"/>

### NMEA2000 M12 connector pinout
<img src="images/NMEA2000 M12 connector.png" width="600"/>
