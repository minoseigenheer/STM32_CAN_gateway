/*
 NMEA2000_STM32.cpp


 Inherited NMEA2000 object for the STM32F105 internal CAN
 See also NMEA2000 library.

 Only use with STM32 HAL for your MCU!


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

 */

#include "NMEA2000_STM32.hpp"


static tNMEA2000_STM32 *NMEA2000_STM32_instance = 0;

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);


//*****************************************************************************
tNMEA2000_STM32::tNMEA2000_STM32(CAN_HandleTypeDef *_N2kCan) :
		tNMEA2000(), N2kCan(_N2kCan) {

	NMEA2000_STM32_instance = this;

	rxRing = 0;
	txRing = 0;
}


//*****************************************************************************
bool tNMEA2000_STM32::CANOpen() {

	bool ret = true;

	// CAN initialisation instead of using the by the STM32cubeIDE configuration tool generated init function
	if (N2kCAN_Init() != HAL_OK) {
		ret = false;
	}

	// Enable CAN
	if (HAL_CAN_Start(N2kCan) != HAL_OK) {
		ret = false;
	}

	// activate CAN callback 1 interrupt for NMEA2000 CAN bus
	if (HAL_CAN_ActivateNotification(N2kCan, CAN_IT_RX_FIFO1_MSG_PENDING) != HAL_OK) {
		ret = false;
	}


	if (SetN2kCANFilter( N2kCan, true, 0, 0x00000000, 0x00000000 ) != HAL_OK) {
		ret = false;
	}

	return ret;
}

//*****************************************************************************
bool tNMEA2000_STM32::CANSendFrame(unsigned long id, unsigned char len, const unsigned char* buf, bool wait_sent) {
	//TODO wait_sent
	uint8_t prio = (uint8_t)((id >> 26) & 0x7);
	bool ret = false;

	//This interrupt deactivation does probably nothing because the TX mailboxes get not filled by interrupt!
	HAL_CAN_DeactivateNotification(N2kCan, CAN_IT_TX_MAILBOX_EMPTY);

	bool TxMailboxesFull = HAL_CAN_GetTxMailboxesFreeLevel(N2kCan) == 0;
	bool SendFromBuffer = false;

	// If TX buffer has already some frames waiting with higher prio or mailbox is full, buffer frame
	if ( !txRing->isEmpty(prio) || TxMailboxesFull ) {
		CAN_message_t *msg = txRing->getAddRef(prio);
		if ( msg!=0 ) {
			msg->id = id;
			msg->flags.extended = 1;
			if ( len > 8 ) len = 8;
			msg->len = len;
			memcpy(msg->buf, buf, len);
			ret = true;
			//frame buffered
		}
		SendFromBuffer = true;
	}

	if ( !TxMailboxesFull ) {
		if ( SendFromBuffer ) {
			ret = sendFromTxRing(prio);
		} else {
			ret = CANwriteTxMailbox(id, len, buf, 1);
		}
		/* transmit entry accepted */
	}

	HAL_CAN_ActivateNotification(N2kCan, CAN_IT_TX_MAILBOX_EMPTY);

	return ret;
}

//*****************************************************************************
bool tNMEA2000_STM32::CANGetFrame(unsigned long& id, unsigned char& len, unsigned char* buf) {

	bool ret = false;

	HAL_CAN_DeactivateNotification(N2kCan, CAN_IT_RX_FIFO1_MSG_PENDING);

	const CAN_message_t *msg = rxRing->getReadRef();
	if ( msg!=0 ) {
	    id = msg->id;
	    len = msg->len;
		if ( len > 8 ) len = 8;
	    memcpy(buf, msg->buf, len);
	    ret = true;
	}

	HAL_CAN_ActivateNotification(N2kCan, CAN_IT_RX_FIFO1_MSG_PENDING);

	return ret;

}

// *****************************************************************************
void tNMEA2000_STM32::InitCANFrameBuffers() {

  if ( MaxCANReceiveFrames == 0 ) MaxCANReceiveFrames = 32; // Use default, if not set
  if ( MaxCANReceiveFrames < 10 ) MaxCANReceiveFrames = 10; // Do not allow less than 10 - should have enough memory.
  if ( MaxCANSendFrames == 0 ) MaxCANSendFrames = 50;  // Use big enough default buffer
  if ( MaxCANSendFrames < 30 ) MaxCANSendFrames = 30; // Do not allow less than 30 - should have enough memory.

  //TODO deleting ring buffer results in hard fault!
  // if buffer is initialized with a different size delete it
  if ( rxRing != 0 && rxRing->getSize() != MaxCANReceiveFrames ) {
    delete rxRing;
    rxRing = 0;
  }
  if ( txRing != 0 && txRing->getSize() != MaxCANSendFrames ) {
    delete txRing;
    txRing = 0;
  }
  //							tPriorityRingBuffer(uint16_t _size, uint8_t _maxPriorities=1);
  if ( rxRing == 0 ) rxRing=new tPriorityRingBuffer<CAN_message_t>(MaxCANReceiveFrames, 7);
  if ( txRing == 0 ) txRing=new tPriorityRingBuffer<CAN_message_t>(MaxCANSendFrames, 7);

}

// *****************************************************************************
bool tNMEA2000_STM32::CANwriteTxMailbox(unsigned long id, unsigned char len, const unsigned char *buf, bool extended) {

	if (extended) {
		CANTxHeader.IDE = CAN_ID_EXT;
		CANTxHeader.ExtId = id;
	} else {
		CANTxHeader.IDE = CAN_ID_STD;
		CANTxHeader.StdId = id;
	}
	CANTxHeader.RTR = CAN_RTR_DATA;
	CANTxHeader.DLC = len;
	CANTxHeader.TransmitGlobalTime = DISABLE;

    if ( len > 8 ) len = 8;
    memcpy(CANTxdata, buf, len);
	//for (int i = 0; i < len; i++) {
	//	CANTxdata[i] = buf[i];
	//}

	// send message
	if (HAL_CAN_AddTxMessage(N2kCan, &CANTxHeader, CANTxdata, &CANTxMailbox) == HAL_OK) {
		return true;
	} else {
		return false;
	}

}

// *****************************************************************************
bool tNMEA2000_STM32::sendFromTxRing(uint8_t prio) {
	const CAN_message_t *txMsg;

	txMsg = txRing->getReadRef(prio);
	if ( txMsg != 0 ) {
		return CANwriteTxMailbox(txMsg->id, txMsg->len, txMsg->buf, txMsg->flags.extended);
	} else {
		return false;
	}

}

// *****************************************************************************
void tNMEA2000_STM32::CANreadRxMailbox(CAN_HandleTypeDef *hcan) {
	CAN_message_t *rxMsg;
	uint8_t prio;

	if (hcan == N2kCan) {
		if (HAL_CAN_GetRxMessage(hcan, RX_FIFO, &CANRxHeader, CANRxdata) == HAL_OK) {
			prio = (uint8_t)((CANRxHeader.ExtId >> 26) & 0x7);
			rxMsg = rxRing->getAddRef(prio);
			if ( rxMsg!=0 ) {
				rxMsg->len = CANRxHeader.DLC;
				if ( rxMsg->len > 8 ) rxMsg->len = 8;
				rxMsg->flags.remote = CANRxHeader.RTR == CAN_RTR_REMOTE;
				rxMsg->flags.extended = CANRxHeader.IDE == CAN_ID_EXT;
				rxMsg->id = CANRxHeader.ExtId;
			}
			memcpy(rxMsg->buf, CANRxdata, rxMsg->len);
		}
	}
	// I think we don't have to check the fifo fill level if we use interrups?
	// HAL_CAN_GetRxFifoFillLevel(*N2kCan, CAN_RX_FIFO1);

}


/**
  * @brief CAN Initialization Function
  * @param hcan CAN_HandleTypeDef pointer to CAN instance
  * @param CANinstance CAN_TypeDef pointer CAN1 or CAN2
  * @param baudRate in kbit/s
  * @param clockSpeed enum of the clock connected to the CAN controller (APB1 for STM32F105=48mHz)
  * @retval bool success or not
  */
HAL_StatusTypeDef tNMEA2000_STM32::N2kCAN_Init()
{
	// CAN1000kbitPrescaler, TimeSeg1 and TimeSeg2 are configured for 1000 kbit/s @ defined clock speed
	// Baud rate has to be dividable by 1000 (500, 250, 200, 125, 100...)

#ifdef CAN1
	if (N2kCan == &hcan1) {
		CANinstance = CAN1;
	}
#ifdef CAN2
	else if (N2kCan == &hcan2) {
		CANinstance = CAN2;
	}
#endif
#ifdef CAN3
	else if (N2kCan == &hcan3) {
		CANinstance = CAN3;
	}
#endif
	else {
		// CAN_HandleTypeDef *hcan is unknown
		return HAL_ERROR;
	}
#endif

	uint32_t CAN1000kbitPrescaler;
	uint32_t CANtimeSeg1;
	uint32_t CANtimeSeg2;


	// usually the APB1 clock is running at the following speed if max clock frequencies are used:
	// STM32F103/105/107   36'000'000 Hz
	// STM32F405/407       42 000'000 Hz
	uint32_t APB1clockSpeed = HAL_RCC_GetPCLK1Freq();

	if (APB1clockSpeed == 24000000) {
		CAN1000kbitPrescaler = 2;
		CANtimeSeg1 = CAN_BS1_10TQ;
		CANtimeSeg2 = CAN_BS2_1TQ;
	}
	else if (APB1clockSpeed == 36000000) {
		CAN1000kbitPrescaler = 2;
		CANtimeSeg1 = CAN_BS1_15TQ;
		CANtimeSeg2 = CAN_BS2_2TQ;
	}
	else if (APB1clockSpeed == 42000000) {
		CAN1000kbitPrescaler = 3;
		CANtimeSeg1 = CAN_BS1_11TQ;
		CANtimeSeg2 = CAN_BS2_2TQ;
	}
	else if (APB1clockSpeed == 48000000) {
		CAN1000kbitPrescaler = 3;
		CANtimeSeg1 = CAN_BS1_13TQ;
		CANtimeSeg2 = CAN_BS2_2TQ;
	}
	else {
		// There are no settings four your ABT1 clock speed yet!
		// On the following website you can find a matching prescaler, TS1 and TS2
		// Add the values for your clock speed and 1000kbit/s
		// http://www.bittiming.can-wiki.info/?CLK=36&ctype=bxCAN&SamplePoint=87.5
		return HAL_ERROR;
	}

	N2kCan->Instance = CANinstance;
	N2kCan->Init.Prescaler = CAN1000kbitPrescaler * 1000 / CANbaudRate;
	N2kCan->Init.Mode = CAN_MODE_NORMAL;
	N2kCan->Init.SyncJumpWidth = CAN_SJW_1TQ;
	N2kCan->Init.TimeSeg1 = CANtimeSeg1;
	N2kCan->Init.TimeSeg2 = CANtimeSeg2;
	N2kCan->Init.TimeTriggeredMode = DISABLE;
	N2kCan->Init.AutoBusOff = DISABLE;
	N2kCan->Init.AutoWakeUp = DISABLE;
	N2kCan->Init.AutoRetransmission = DISABLE;
	N2kCan->Init.ReceiveFifoLocked = DISABLE;
	N2kCan->Init.TransmitFifoPriority = DISABLE;

	return HAL_CAN_Init(N2kCan);
}

/*******************************************************************************
  * @brief  Set STM32 HAL CAN filter
  * @param  hcan CAN_HandleTypeDef pointer to CAN instance
  * @param  ExtendedIdentifier: 0 = normal CAN identifier; 1 = extended CAN identifier
  * @param  FilterNum CAN bus filter number for this CAN bus 0...13 / 0...27
  * @param  Mask uint32_t bit mask
  * @param  Filter uint32_t CAN identifier
  * @retval success or not
  */
HAL_StatusTypeDef tNMEA2000_STM32::SetN2kCANFilter( CAN_HandleTypeDef *hcan, bool ExtendedIdentifier, uint32_t FilterNum, uint32_t Mask, uint32_t Filter )
{
	HAL_StatusTypeDef ret = HAL_ERROR;

	// For dual CAN MCU's we have 28 filter banks to share between the CAN busses
	// For single CAN SlaveStartFilterBank does nothing and we have 14 filter banks.
	// If not defined different we use filter 0 .. 13 for primary CAN bus and 14 ... 27 for secondary CAN bus
	#if !defined(SlaveStartFilterBank)
	const uint32_t SlaveStartFilterBank = 14;
	#endif

	#if defined(CAN2) // we have two CAN busses
		const int32_t TotalFilterBanks = 27;
    #elif defined(CAN1) // we have only one CAN bus
		const int32_t TotalFilterBanks = 13;
	#else // we have no CAN defined
		const int32_t TotalFilterBanks = -1;
	#endif

	int32_t FilterBank = -1;
	if (hcan->Instance == CAN1
			&& FilterNum <= TotalFilterBanks
			&& FilterNum < SlaveStartFilterBank ) {
		FilterBank = FilterNum;
	}
	else if (hcan->Instance == CAN2
			&& FilterNum <= TotalFilterBanks - SlaveStartFilterBank) {
		FilterBank = FilterNum + SlaveStartFilterBank;
	}

	if ( FilterBank >= 0
			&& IS_CAN_ALL_INSTANCE(hcan->Instance) )
	{
		CAN_FilterTypeDef sFilterConfig;

		sFilterConfig.FilterBank = FilterBank;
		sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

		if (ExtendedIdentifier == false)
		{
			sFilterConfig.FilterMaskIdHigh = Mask << 5 & 0xFFFF;
			sFilterConfig.FilterMaskIdLow = 0x0000; // allows both remote request and data frames
			sFilterConfig.FilterIdHigh = Filter << 5 & 0xFFFF;
			sFilterConfig.FilterIdLow =  0x0000;
		}
		else
		{ // ExtendedIdentifier == true
			sFilterConfig.FilterMaskIdHigh = Mask >> 13 & 0xFFFF;
			sFilterConfig.FilterMaskIdLow = (Mask << 3 & 0xFFF8) | (0x1 << 2);
			sFilterConfig.FilterIdHigh = Filter >> 13 & 0xFFFF; // EXTID[28:13]
			sFilterConfig.FilterIdLow = (Filter << 3 & 0xFFF8) | (0x1 << 2); // EXTID[12:0] + IDE
		}

		sFilterConfig.FilterFIFOAssignment = 0;
		sFilterConfig.FilterActivation = CAN_FILTER_ENABLE;
		sFilterConfig.SlaveStartFilterBank = SlaveStartFilterBank; // CAN 0: 0...13 // CAN 1: 14...27 (28 filter banks in total)

		ret = HAL_CAN_ConfigFilter(hcan, &sFilterConfig);
	}
	return ret;
}


// *****************************************************************************


void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	// Call rxInterrupt method of the last tNMEA2000_STM32 instance.
	NMEA2000_STM32_instance->CANreadRxMailbox(hcan);
}

// *****************************************************************************
//	Other 'Bridge' functions

void delay(const uint32_t ms) {
	HAL_Delay(ms);
};


//*****************************************************************************
uint32_t millis(void) {
    return HAL_GetTick();
};



