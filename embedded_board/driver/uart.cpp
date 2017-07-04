/*
 * uart.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: mfrata
 */


#include "uart.h"

	uint32_t uart::UCA0RxBuffer = 0;
	std::string uart::UCA1RxBuffer;

uart::uart(uint16_t p_baseAddress, uint16_t p_baudRate): uartPort((p_baseAddress == USCI_A0_BASE)? P3_address : P4_address){

    if(baseAddress == USCI_A1_BASE)
        PM_UCA1();

    //port configurations
    uartPort.setPinFunctionSelection(BIT3);
    uartPort.setPinFunctionSelection(BIT4);

    uartPort.setPinFunctionSelection(BIT4);
    uartPort.setPinFunctionSelection(BIT5);

	baseAddress = p_baseAddress;
	baudRate = p_baudRate;


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
		clockPrescaler = 416;
		secondModReg   = 6;
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

	HWREG16(baseAddress + OFS_UCAxBRW) = clockPrescaler;
	HWREG16(baseAddress + OFS_UCAxMCTL) =  secondModReg << 1;
	HWREG8(baseAddress + OFS_UCAxCTL1) = UCSSEL_2;

	//config interrupts mostly will be rx
	HWREG8(baseAddress + OFS_UCAxIE) = UCRXIE;

	//Enable the State Machine
	HWREG8(baseAddress + OFS_UCAxCTL1) &= ~(UCSWRST);
}

uart::~uart(){

}

void uart::transmit(uint8_t *transmitData)
{
    while(*transmitData != 0)
    {
    	while (!(HWREG8(baseAddress + OFS_UCAxIFG) & UCTXIFG));
    		HWREG8(baseAddress + OFS_UCAxTXBUF) = *transmitData++;
    }
}


uint32_t uart::receive_USCI_A0(void){
	uint32_t aux = UCA0RxBuffer;
	UCA0RxBuffer = 0;
    return aux;
}

uint8_t uart::receive_USCI_A1(void){
    return UCA1RXBUF;
}

std::string uart::getBuffer(void){
    return UCA1RxBuffer;
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

void uart::clear_A1_string(void){
    UCA1RxBuffer.clear();

}



//******************************************************************************
//
//This is the USCI_A1 interrupt vector service routine.
//
//******************************************************************************
#pragma vector=USCI_A0_VECTOR
__interrupt void uart::USCI_A0_ISR(void)
{
    switch(__even_in_range(UCA0IV,4))
    {
    //Vector 2 - RXIFG
    case 2:
        UCA0RxBuffer = (UCA0RxBuffer << 8) | UCA0RXBUF;
    default:
    	break;
    }
}

#pragma vector=USCI_A1_VECTOR
__interrupt void uart::USCI_A1_ISR(void)
{
    switch(__even_in_range(UCA1IV,4))
    {
    //Vector 2 - RXIFG
    case 2:
        UCA1RxBuffer.push_back((char)(receive_USCI_A1()));
        break;
    default:
    	break;
    }
}
