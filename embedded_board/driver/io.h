/*
 * IO.h
 *
 *  Created on: 08/05/2017
 *      Author: Bruno Eiterer
 */

#include <msp430.h>
#include <stdint.h>
#include "msp430f5529_hal.h"

#ifndef IO_H_
#define IO_H_

class port {

private:

    uint16_t base_address;
    volatile uint16_t* input_register_address;
    volatile uint16_t* output_register_address;
    volatile uint16_t* direction_register_address;
    volatile uint16_t* pullup_enable_register_address;
    volatile uint16_t* drive_strength_register_address;
    volatile uint16_t* function_selection_register_address;
    volatile uint8_t base_address_shift;    // this is necessary for odd addresses as the MSP430 is only word accessible

public:
    port(uint16_t address);
    ~port();
    void setPin(uint8_t pin);
    void clearPin(uint8_t pin);
    void togglePin(uint8_t pin);
    void setPinDirection(uint8_t pin, uint8_t direction);
    void setPinPullup(uint8_t pin);
    void clearPinPullup(uint8_t pin);
    void setPinDriveStrength(uint8_t pin);
    void clearPinDriveStrength(uint8_t pin);
    void setPinFunctionSelection(uint8_t pin);
    void clearPinFunctionSelection(uint8_t pin);
};




#endif /* IO_H_ */
