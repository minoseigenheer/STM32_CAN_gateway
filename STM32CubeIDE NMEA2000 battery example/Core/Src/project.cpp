/*
    project.cpp
    Created on: 11-11-2022
    Author: Minos

	**********************************************************************************************
	NMEA2000 STM32 battery example
	**********************************************************************************************
	- DC Detailed Status (PGN127506)
		 State-Of-Charge (SOC)
		 Time remaining
		 Amp hours left
	- Charger Status (PGN127507)
		 Charge state
	- Battery Status (PGN127508)
		 Battery pack voltage
		 Battery pack current
		 Battery pack highest temperature
	- Battery Configuration Status (PGN127513)
		 Static battery info like nominal voltage, chemistry...


	Copyright (c) 2022 Minos Eigenheer

	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
	Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
	CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
	OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include "project.hpp"
#include "main.h"
#include "NMEA2000_STM32.hpp"		// manually select CAN library


/////////////////////////////////
// PRIVAT VARIABLES
////////////////////////////////

extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;


// fake battery variables
int state_of_charge = 95;
double pack_voltage = 48.25;
double battery_current = 20.11;
double cel_temp_avg = 20.2;
double estimated_amp_hours_left = 652.5;
double state_of_health = 95.1;
double time_remaining = 32.6;


// Constant NMEA2000 battery configuration parameters
tN2kBatType BatType;                            		// we don't know the code for lithium batteries
tN2kBatEqSupport SupportsEqual = N2kDCES_Unavailable;   // Equalisation is not used with lithium batteries
tN2kBatNomVolt BatNominalVoltage = N2kDCbnv_48v;        // N2kDCbnv_6v, N2kDCbnv_12v, N2kDCbnv_24v, N2kDCbnv_32v, N2kDCbnv_62v, N2kDCbnv_42v, N2kDCbnv_48v
tN2kBatChem BatChemistry = N2kDCbc_LiIon;               //
double BatCapacity = 800.0;                              //
int8_t BatTemperatureCoefficient = 0xFF;                //
double PeukertExponent = 0;                             //
int8_t ChargeEfficiencyFactor = 92;                     //

unsigned char SequenceID = 0; // counter


// *****************************************************************************
// NMEA2000
// *****************************************************************************

//tNMEA2000_STM32 NMEA2000;
tNMEA2000 &NMEA2000 = *( new tNMEA2000_STM32(&hcan2, tNMEA2000_STM32::CAN250kbit) );

// List here messages your device will transmit.
const unsigned long TransmitMessagesBattery[] PROGMEM={127506L,127507L,127508L,127513L,0};

// ---  Example of using PROGMEM to hold Product ID.  However, doing this will prevent any updating of
//      these details outside of recompiling the program.
const tNMEA2000::tProductInformation ProductInformation PROGMEM={
                                       2100,                        // N2kVersion
                                       100,                         // Manufacturer's product code
                                       "Battery example",          // Manufacturer's Model ID
                                       "0.1.0.0 (2022-10-22)",      // Manufacturer's Software version code
                                       "0.1.0.0 (2022-10-22)",      // Manufacturer's Model version
                                       "00000001",                  // Manufacturer's Model serial code
                                       0,                           // SertificationLevel
                                       1                            // LoadEquivalency
                                      };

// ---  Example of using PROGMEM to hold Configuration information.  However, doing this will prevent any updating of
//      these details outside of recompiling the program.
const char ManufacturerInformation [] PROGMEM = "SuperPowerBattery3000";
const char InstallationDescription1 [] PROGMEM = "";
const char InstallationDescription2 [] PROGMEM = "";

// Define schedulers for messages. Define schedulers here disabled. Schedulers will be enabled
// on OnN2kOpen so they will be synchronized with system.
// We use own scheduler for each message so that each can have different offset and period.
// Setup periods according PGN definition (see comments on IsDefaultSingleFrameMessage and
// IsDefaultFastPacketMessage) and message first start offsets. Use a bit different offset for
// each message so they will not be sent at same time.
tN2kSyncScheduler DCBatStatusScheduler(false,1500,500);
tN2kSyncScheduler DCStatusScheduler(false,1500,510);
tN2kSyncScheduler BatConfScheduler(false,5000,530); // Non periodic


void SendN2kBatteryMessages() {
    tN2kMsg N2kMsg;

    if ( DCBatStatusScheduler.IsTime() ) {
      DCBatStatusScheduler.UpdateNextTime();

      SequenceID ++;
      if ( SequenceID > 252 ) {
        SequenceID = 0;
      }

  //  SetN2kPGN127508(tN2kMsg &N2kMsg, unsigned char BatteryInstance, double BatteryVoltage, double BatteryCurrent, double BatteryTemperature, unsigned char SID)
      SetN2kDCBatStatus(N2kMsg, 0, pack_voltage, battery_current, CToKelvin(cel_temp_avg), SequenceID);
      NMEA2000.SendMsg(N2kMsg);

    }

    if ( DCStatusScheduler.IsTime() ) {
      DCStatusScheduler.UpdateNextTime();
  //  SetN2kPGN127506(const tN2kMsg &N2kMsg, unsigned char &SID, unsigned char &DCInstance, tN2kDCType &DCType,
  //                     uint8_t &StateOfCharge, uint8_t &StateOfHealth, double &TimeRemaining, double &RippleVoltage, double &Capacity)
      SetN2kDCStatus(N2kMsg,SequenceID, 0, N2kDCt_Battery, state_of_charge, state_of_health, time_remaining, 0xFF, estimated_amp_hours_left);
      NMEA2000.SendMsg(N2kMsg);
    }

    if ( BatConfScheduler.IsTime() ) {
      BatConfScheduler.UpdateNextTime();
  //  SetN2kPGN127513(tN2kMsg &N2kMsg, unsigned char BatInstance, tN2kBatType BatType, tN2kBatEqSupport SupportsEqual,
  //                  tN2kBatNomVolt BatNominalVoltage, tN2kBatChem BatChemistry, double BatCapacity, int8_t BatTemperatureCoefficient,
  //                  double PeukertExponent, int8_t ChargeEfficiencyFactor)
  //  SetN2kBatConf(N2kMsg, 0, 0, N2kDCES_Unavailable, N2kDCbnv_48v, N2kDCbc_LiIon, 0xFF, 0xFF, 0, 92);
      SetN2kBatConf(N2kMsg, 0, BatType, SupportsEqual, BatNominalVoltage, BatChemistry, BatCapacity, BatTemperatureCoefficient, PeukertExponent, ChargeEfficiencyFactor);
      NMEA2000.SendMsg(N2kMsg);
    }
}


// *****************************************************************************
// Call back for NMEA2000 open. This will be called, when library starts bus communication.
// See NMEA2000.SetOnOpen(OnN2kOpen); on setup()
void OnN2kOpen() {
    // Start schedulers now.
    DCBatStatusScheduler.UpdateNextTime();
    DCStatusScheduler.UpdateNextTime();
    BatConfScheduler.UpdateNextTime();
}



/////////////////////////////////
// INITIALIZATION
////////////////////////////////

void myCppProcessInit()
{

    // NMEA2000 setup
	//-----------------------------------------------------------
    // Set Product information
    NMEA2000.SetProductInformation(&ProductInformation);
    // Set Configuration information
    NMEA2000.SetProgmemConfigurationInformation(ManufacturerInformation,InstallationDescription1,InstallationDescription2);
    // Set device information
    NMEA2000.SetDeviceInformation(1,      // Unique number. Use e.g. Serial number.
                                  170,    // Device function=Battery. See codes on http://www.nmea.org/Assets/20120726%20nmea%202000%20class%20&%20function%20codes%20v%202.00.pdf
                                  35,     // Device class=Electrical Generation. See codes on  http://www.nmea.org/Assets/20120726%20nmea%202000%20class%20&%20function%20codes%20v%202.00.pdf
                                  0,      // Just choosen free from code list on http://www.nmea.org/Assets/20121020%20nmea%202000%20registration%20list.pdf
                                  4,      // Marine
                                  0);     // device


    // If you also want to see all traffic on the bus use N2km_ListenAndNode instead of N2km_NodeOnly below
    NMEA2000.SetMode(tNMEA2000::N2km_NodeOnly,80);
    // NMEA2000.SetDebugMode(tNMEA2000::dm_ClearText);     // Uncomment this, so you can test code without CAN bus chips on Arduino Mega
    // NMEA2000.EnableForward(false);                      // Disable all msg forwarding to USB (=Serial)

    //  NMEA2000.SetN2kCANMsgBufSize(2);                    // For this simple example, limit buffer size to 2, since we are only sending data
    // Define OnOpen call back. This will be called, when CAN is open and system starts address claiming.

    // Here we tell library, which PGNs we transmit
    NMEA2000.ExtendTransmitMessages(TransmitMessagesBattery);

    NMEA2000.SetOnOpen(OnN2kOpen);
    NMEA2000.Open();

}


/////////////////////////////////
// CPP program main function
////////////////////////////////

void myCppProcess(void) {

	// infinite loop
	while (1) {


	    SendN2kBatteryMessages();
	    NMEA2000.ParseMessages();



	}// end myCppProcess while (1) loop

}
