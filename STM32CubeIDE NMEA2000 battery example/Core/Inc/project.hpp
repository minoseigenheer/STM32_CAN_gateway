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
#include <stdbool.h>

#include "main.h"

//#include "NMEA2000_CAN.h"       // This will automatically choose right CAN library and create suitable NMEA2000 object
#include "NMEA2000.h"
#include "N2kMessages.h"

extern tNMEA2000 &NMEA2000;

void myCppProcessInit(void);
void myCppProcess (void);

void SendN2kBatteryMessages();

#endif /* PROJECT_H_ */
