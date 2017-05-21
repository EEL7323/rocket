#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include <msp430.h>
#include "clock.h"

class watchdog{

private:

public:
    watchdog(void);
    ~watchdog(void);
    void watchdogResetCounter(void);
};

#endif /* WATCHDOG_H_ */
