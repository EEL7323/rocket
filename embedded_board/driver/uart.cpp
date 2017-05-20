/*
 * uart.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: mfrata
 */


#include "uart.h"

uart::uart(uint16_t p_baseAddress, uint16_t p_baudRate): uartPort((p_baseAddress == USCI_A0_BASE)? P3 : P4){

    //port configurations
    uartPort.setPinFunctionSelection(BIT3);

	baseAddress = p_baseAddress;
	baudRate = p_baudRate;

	if(baseAddress == USCI_A1_BASE)
		PM_UCA1();

    //To configurate the UART you must stop the state machine
    HWREG8(baseAddress + OFS_UCAxCTL1) |= UCSWRST;

    uint16_t clockPrescaler;
    uint8_t firstModReg = 0;
    uint8_t secondModReg;

    /* This configurations values are for a 4 MHz clock.
     * They are setting the prescalar register and a modulation register as specified at the
     * ti.com/lit/ug/slau208p/slau208p.pdf page 951
     */
	switch(baudRate){
	case 9600:
		clockPrescaler = 109;
		secondModReg   = 0;
		break;
	case 19200:
	    clockPrescaler = 208;
		secondModReg   = 3;
		break;
	case 38400:
	    clockPrescaler = 104;
		secondModReg   = 1;
		break;
	case 57600:
	    clockPrescaler = 69;
		secondModReg   = 4;
		break;
	case 115200:
	    clockPrescaler = 34;
		secondModReg   = 6;
		break;
	default:
	    clockPrescaler = 416;
		secondModReg   = 6;
	}

	HWREG16(baseAddress + OFS_UCAxBRW) = clockPrescaler + (secondModReg << 8);
	HWREG8(baseAddress + OFS_UCAxCTL1) = UCSSEL_2;

	//config interrupts mostly will be rx


	//Enable the State Machine
	HWREG8(baseAddress + OFS_UCAxCTL1) &= ~(UCSWRST);
}

void uart::transmit(uint8_t *transmitData)
{
    while(*transmitData != 0)
    {
    	while (!(HWREG8(baseAddress + OFS_UCAxIFG) & UCTXIFG));
    		HWREG8(baseAddress + OFS_UCAxTXBUF) = *transmitData++;
    }
}


void uart::receive(uint8_t *buffer){


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



//******************************************************************************
//
//This is the USCI_A1 interrupt vector service routine.
//
//******************************************************************************
#pragma vector=USCI_A0_VECTOR
void USCI_A0_ISR(void)
{
    switch(__even_in_range(UCA0IV,4))
    {
    //Vector 2 - RXIFG
    case 2:
        break;
    default:
    	break;
    }
}

#pragma vector=USCI_A1_VECTOR
void USCI_A1_ISR(void)
{
    switch(__even_in_range(UCA0IV,4))
    {
    //Vector 2 - RXIFG
    case 2:
        break;
    default:
    	break;
    }
}
