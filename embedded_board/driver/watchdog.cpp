/*
 * IO.cpp
 *
 *  Created on: 21/05/2017
 *      Author: Bruno Eiterer
 */

#include "watchdog.h"

watchdog::watchdog(void){

    WDTCTL = WDTPW + WDTSSEL_1 + WDTIS_4;

}

watchdog::~watchdog(void){

}

void watchdog::watchdogResetCounter(void){

    WDTCTL = (WDTCTL & 0x00FF) + WDTPW + WDTCNTCL;
    WDTCTL = ((WDTCTL & 0x00FF) + WDTPW) & ~WDTCNTCL;
}
