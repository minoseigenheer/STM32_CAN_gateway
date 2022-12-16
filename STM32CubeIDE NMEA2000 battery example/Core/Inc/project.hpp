/*
 * project.h
 *
 *  Created on: 11-11-2022
 *      Author: Minos
 *      CPP project header
 */
 
#ifndef PROJECT_H_
#define PROJECT_H_
 

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "main.h"
#include "NMEA2000.h"
#include "N2kMessages.h"
//#include "NMEA2000_CAN.h"       // This will automatically choose right CAN library and create suitable NMEA2000 object

extern tNMEA2000 &NMEA2000;

void myCppProcessInit(void);
void myCppProcess (void);

void SendN2kBatteryMessages();
double PowerAvg();
double SecondsRemaining();
tN2kChargeState N2kChargeState();
tN2kOnOff N2kChargerEnable();
void sendEmusRequest();
void resetEmusParameters();
void ChargingStageProcessing();

std::string GetChargingStageString();
int GetChargingDuration();
double GetChargedEnergy();

double GetTemp(uint16_t ADC);
double GetInternalTemp(uint16_t ADC);
double GetVoltage(uint16_t ADC);
uint8_t GetByteFromBools(uint8_t bool1, uint8_t bool2, uint8_t bool3, uint8_t bool4, uint8_t bool5, uint8_t bool6, uint8_t bool7, uint8_t bool8);


void SendSoftwareVersion();

void NextFadeVal();
uint8_t GammaCorrection(uint8_t linear);
void breathingLED();

HAL_StatusTypeDef CAN_Init(CAN_HandleTypeDef *hcan, uint32_t CANbaudRate, uint32_t APB1clockSpeed);
HAL_StatusTypeDef SetCANFilter( CAN_HandleTypeDef *hcan, bool ExtendedIdentifier, uint32_t FilterNum, uint32_t Mask, uint32_t Filter );




#endif /* PROJECT_H_ */
