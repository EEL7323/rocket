#ifndef _ACCESSHANDLER_H
#define _ACCESSHANDLER_H

#include "dataManagement.h"
#include "student.h"
#include "io.h"
#include "msp430f5529_hal.h"
#include "captcha.h"


class accessHandler {
private:
    port P1;
    port P4;
    captcha captchaSystem;

public:
    accessHandler();
    ~accessHandler();
    bool accessRequestHandler(uint8_t request_ID, dataManagement &manager, bool app_flag);
    void leaveRequestHandler(uint8_t request_ID, dataManagement &manager);
    void openTurnstile(void);
    void closeTurnstile(void);
};

#endif // _ACCESSHANDLER_H
