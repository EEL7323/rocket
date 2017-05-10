/*
 * uart.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: mfrata
 */


#include "uart.h"

uart::uart(uint8_t p_baseAddress, uint16_t p_baudRate){
	baseAddress = p_baseAddress;
	baudRate = p_baudRate;

	//pins from msp if
	switch(baseAddress){
	case USCI_A0_BASE:
    	UART_A0_PORT |= UART_A0_TX + UART_A0_RX;
    	break;
	case USCI_A1_BASE:
		UART_A1_PORT |= UART_A1_TX + UART_A1_RX;
		PM_UCA1();
    	break;
	default:
		return;
	}

    //Disable the USCI Module
    HWREG8(baseAddress + OFS_UCAxCTL1) |= UCSWRST;

    uint16_t clockPrescalar;
    uint8_t firstModReg = 0;
    uint8_t secondModReg;

	//config baudrate
	switch(baudRate){
	case 9600:
		clockPrescalar = 416;
		secondModReg   = 6;
		break;
	case 19200:
		clockPrescalar = 208;
		secondModReg   = 3;
		break;
	case 38400:
		clockPrescalar = 104;
		secondModReg   = 1;
		break;
	case 57600:
		clockPrescalar = 69;
		secondModReg   = 4;
		break;
	case 115200:
		clockPrescalar = 34;
		secondModReg   = 6;
		break;
	default:
		clockPrescalar = 416;
		secondModReg   = 6;
	}

	HWREG16(baseAddress + OFS_UCAxBRW) = clockPrescalar;
	HWREG8(baseAddress + OFS_UCAxCTL1) = (firstModReg << 4) + (secondModReg << 1);

	//config interrupts mostly will be rx


	//enable the state machine

}

void uart::PM_UCA1(void) {
	// Disable Interrupts before altering Port Mapping registers
	__disable_interrupt();
	// Enable Write-access to modify port mapping registers
	PMAPPWD = 0x02D52;

#ifdef PORT_MAP_RECFG
	// Allow reconfiguration during runtime
	PMAPCTL = PMAPRECFG;
#endif

	P4MAP5 = PM_UCA1RXD;
	P4MAP4 = PM_UCA1TXD;

	// Disable Write-Access to modify port mapping registers
	PMAPPWD = 0;
#ifdef PORT_MAP_EINT
	__enable_interrupt();                     // Re-enable all interrupts
#endif
}
