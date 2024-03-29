# STM32 CAN gateway

STM32F105 based dual CAN bus gateway / isolator.\
Designed for a EMUS BMS CAN to NMEA2000 converter.\
But hardware can be used for many CAN gateway or CAN isolation applications.

### Specs
```
- STM32F105RCT6 72MHz MCU with 2 internal CAN controllers
- CAN1 BMS (micro-fit 6-pin connector) optionally isolated
- CAN2 NMEA2000 (M12 5-pin connector) optionally isolated
  or second micro-fit 6-pin connector
- 4-32V supply voltage
- RGB status LED
- USB-C for firmware updates
```
```
- Solder jumpers to use M12 male or female connectors.
- Solder jumpers for the CAN termination resistor.
- Solder jumpers for power output on CAN2 connector.
```
<img src="images/STM32_CAN_gateway.png" width="1000"/>

## pinout
 - EMUS BMS micro-fit 6p. connector (CAN1 & power input)
 - NMEA2000 M12 5p. connector (isolated CAN2 & optional power output)
 
<img src="images/STM32_CAN_gateway_pinout.png" width="600" alt="EMUS BMS micro-fit 6p connector | NMEA2000 M12 connector"/>

## Examples
- [STM32CubeIDE NMEA2000 battery project example](/STM32CubeIDE%20NMEA2000%20battery%20example)
  > Import projet into STM32CubeIDE
  > tested with version: 1.10.1
