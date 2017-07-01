/*
 * timer.h
 *
 *  Created on: 01/07/2017
 *      Author: Bruno Eiterer
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <msp430.h>
#include <stdint.h>
#include "msp430f5529_hal.h"

class timer{

private:
    static uint8_t counter;
public:
    timer(void);
    ~timer(void);
    static bool timerExpired(void);
    static interrupt void TIMER0_A0_ISR(void);
};

#endif /* TIMER_H_ */
