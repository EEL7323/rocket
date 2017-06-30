/*
 * clock.cpp
 *
 *  Created on: 21/05/2017
 *      Author: Bruno Eiterer
 */

#include "clock.h"

clock::clock(void):clockPort(P5_address){

    clockPort.setPinFunctionSelection(BIT2);
    clockPort.setPinFunctionSelection(BIT3);

    UCSCTL4 = SELA_2 + SELS_5 + SELM_5;  // select ACLK = REFOCLK = 32.768kHz
                                                                    // select SMCLK = XT2 = 4MHz
                                                                    // select MCLK = XT2 = 4MHz
    UCSCTL6 = XT1OFF + XCAP_3;

    do {
        UCSCTL7 &= ~(XT2OFFG | XT1LFOFFG | XT1HFOFFG | DCOFFG);  // Clear XT2,XT1,DCO fault flags
        SFRIFG1 &= ~OFIFG;                      // Clear fault flags
    } while (SFRIFG1 & OFIFG);

}
