/*
 * NMEA2000_STM32.h

 use with STM32 HAL for your MCU!

 Based on STM32F1 CAN library by Jaume Clarens jiauka_at_gmail_dot_com
 https://github.com/jiauka/NMEA2000_stm32f1


 Copyright (c) 2022 Minos Eigenheer


Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Inherited NMEA2000 object for STM32 MCU's with internal CAN
based setup. See also NMEA2000 library.
*/


#ifndef NMEA2000_STM32_H_
#define NMEA2000_STM32_H_

#include "stm32f1xx_hal.h"
#include "main.h"

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "NMEA2000.h"
#include "N2kMsg.h"
#include "RingBuffer.h"


extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

class tNMEA2000_STM32 : public tNMEA2000 {

  public:
	tNMEA2000_STM32(CAN_HandleTypeDef *_N2kCan);

  protected:
    bool CANSendFrame(unsigned long id, unsigned char len, const unsigned char* buf, bool wait_sent = true);
    bool CANOpen();
    bool CANGetFrame(unsigned long& id, unsigned char& len, unsigned char* buf);
    void InitCANFrameBuffers();

  protected:
	CAN_HandleTypeDef *N2kCan;

	CAN_TxHeaderTypeDef CANTxHeader;
	CAN_RxHeaderTypeDef CANRxHeader;

	uint8_t CANTxdata[8];
	uint8_t CANRxdata[8];

	uint32_t CANTxMailbox;

	const uint32_t CANbaudRate = 250; // NMEA2000 works with 250 kbit/s
	const uint32_t RX_FIFO = CAN_RX_FIFO1;

	CAN_TypeDef *CANinstance;


  protected:
    struct CAN_message_t {
      uint32_t id = 0;          // can identifier
  //    uint16_t timestamp = 0;   // time when message arrived
  //    uint8_t idhit = 0; // filter that id came from
      struct {
        bool extended = 0; // identifier is extended (29-bit)
        bool remote = 0;  // remote transmission request packet type
        bool overrun = 0; // message overrun
        bool reserved = 0;
      } flags;
      uint8_t len = 8;      // length of data
      uint8_t buf[8] = { 0 };       // data
  //    uint8_t mb = 0;       // used to identify mailbox reception
  //    uint8_t bus = 0;      // used to identify where the message came from when events() is used.
  //    bool seq = 0;         // sequential frames
    };


    tPriorityRingBuffer<CAN_message_t>  *rxRing;
    tPriorityRingBuffer<CAN_message_t>  *txRing;
    uint8_t firstTxBox;

    bool sendFromTxRing(uint8_t prio);
    bool CANwriteTxMailbox(unsigned long id, unsigned char len, const unsigned char *buf, bool extended);

    HAL_StatusTypeDef N2kCAN_Init();
    HAL_StatusTypeDef SetN2kCANFilter( CAN_HandleTypeDef *hcan, bool ExtendedIdentifier, uint32_t FilterNum, uint32_t Mask, uint32_t Filter );

  public:
    void CANreadRxMailbox(CAN_HandleTypeDef *hcan);


};


//-----------------------------------------------------------------------------

void     delay(uint32_t ms);
uint32_t millis(void);



#endif /* NMEA2000_STM32_H_ */

