
/*
 * ms430f5529_hal.h
 *
 *  Created on: 15/05/2017
 *      Author: mfrata
 */

#include <msp430.h>
#include "msp430f5xx_6xxgeneric.h"
#include "stdint.h"
#include "stdbool.h"

#ifndef _MSP430F5529_HAL_H_
#define _MSP430F5529_HAL_H_


/****************************************************************/
/* Too see if the clocks are right set this variable, and recom-
 * pile */
/****************************************************************/
#define OUTPUT_CLOCKS 0


/****************************************************************/
/* PIN DEFINITIONS                                              */
/****************************************************************/

/****************************************************************/
/* PORT IO DEFINITIONS                                             */
/****************************************************************/

/**** BASE ADDRESSES ****/

#define P1_address (__MSP430_BASEADDRESS_PORTA_R__)
#define P2_address (__MSP430_BASEADDRESS_PORTA_R__ + 0x01)
#define P3_address (__MSP430_BASEADDRESS_PORTB_R__)
#define P4_address (__MSP430_BASEADDRESS_PORTB_R__ + 0x01)
#define P5_address (__MSP430_BASEADDRESS_PORTC_R__)
#define P6_address (__MSP430_BASEADDRESS_PORTC_R__ + 0x01)
#define P7_address (__MSP430_BASEADDRESS_PORTD_R__)
#define P8_address (__MSP430_BASEADDRESS_PORTD_R__ + 0x01)

/**** REGISTER OFFSET ****/

#define input_offset 0x00
#define output_offset 0x02
#define direction_offset 0x04
#define pullup_enable_offset 0x06
#define drive_strength_offset 0x08
#define function_selection_offset 0x0A
#define interrupt_vector_word_offset 0x0E
#define interrupt_edge_select_offset 0x18
#define interrupt_enable_offset 0x1A
#define interrupt_flag_offset 0x1C

/**** PORT DIRECTION ****/

#define input 0
#define output 1

/**** EXTERNAL INTERRUPT EDGES ****/

#define rising 0
#define falling 1

/****************************************************************/
/* UART DEFINITIONS                                             */
/****************************************************************/
#define UART_A0_BASE    (USCI_A0_BASE)
#define UART_A0_PORT    (3)
#define UART_A0_TX      (BIT3)
#define UART_A0_RX      (BIT4)
#define UART_A1_PORT    (4)

#define UART_A1_BASE    (USCI_A1_BASE)
#define UART_A1_PORT    (4)
#define UART_A1_TX      (BIT4)
#define UART_A1_RX      (BIT5)




/****************************************************************/
/* RTC Defines                                                  */
/****************************************************************/

/****************************************************************/
/* Internal Flash Defines                                       */
/****************************************************************/
#define INFOA_START             (0x1980)
#define INFOB_START             (0x1900)
#define INFOC_START             (0x1880)
#define INFOD_START             (0x1800)
#define BANKA_START             (0x4400)
#define BANKB_START             (0xC400)
#define BANKC_START             (0x14400)
#define BANKD_START             (0x1C400)
#define BANK_SIZE               (32768)

//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_SUCCESS  0x01
#define STATUS_FAIL     0x00

//*****************************************************************************
//
// Macros for hardware access
//
//*****************************************************************************
#define HWREG32(x)                                                              \
    (*((volatile uint32_t *)((uint16_t)x)))
#define HWREG16(x)                                                             \
    (*((volatile uint16_t *)((uint16_t)x)))
#define HWREG8(x)                                                             \
    (*((volatile uint8_t *)((uint16_t)x)))


#endif
