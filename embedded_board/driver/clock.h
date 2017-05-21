/*
 * clock.h
 *
 *  Created on: 21/05/2017
 *      Author: Bruno Eiterer
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <msp430.h>
#include "msp430f5529_hal.h"
#include "io.h"

class clock{

private:
    port clockPort;

public:
    clock(void);
    ~clock(void);
};

#endif /* CLOCK_H_ */
