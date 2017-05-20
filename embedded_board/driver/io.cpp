/*
 * IO.cpp
 *
 *  Created on: 08/05/2017
 *      Author: Bruno Eiterer
 */

#include "IO.h"

port::port(uint16_t address){
    base_address = address;
    base_address_shift = 0;
    if((address % 2) != 0){
        base_address_shift = 8;
    }
    input_register_address = (volatile uint16_t*) (base_address + input_offset);
    output_register_address = (volatile uint16_t*) (base_address + output_offset);
    direction_register_address = (volatile uint16_t*) (base_address + direction_offset);
    pullup_enable_register_address = (volatile uint16_t*) (base_address + pullup_enable_offset);
    drive_strength_register_address = (volatile uint16_t*) (base_address + drive_strength_offset);
    function_selection_register_address = (volatile uint16_t*) (base_address + function_selection_offset);
}

port::~port(){

}

void port::setPin(uint8_t pin){

    *output_register_address |= pin << base_address_shift;
}

void port::clearPin(uint8_t pin){
    *output_register_address &= ~(pin << base_address_shift);
}

void port::togglePin(uint8_t pin){
    *output_register_address ^= (pin << base_address_shift);
}

void port::setPinDirection(uint8_t pin, uint8_t direction){
    if(direction == output){
        *direction_register_address |= pin << base_address_shift;
    }
    else{
        *direction_register_address &= ~(pin << base_address_shift);
    }
}

void port::setPinPullup(uint8_t pin){
    *pullup_enable_register_address |= (pin << base_address_shift);
}

void port::clearPinPullup(uint8_t pin){
    *pullup_enable_register_address &= ~(pin << base_address_shift);
}

void port::setPinDriveStrength(uint8_t pin){
    *drive_strength_register_address |= (pin << base_address_shift);
}

void port::clearPinDriveStrength(uint8_t pin){
    *drive_strength_register_address &= ~(pin << base_address_shift);
}

void port::setPinFunctionSelection(uint8_t pin){
    *function_selection_register_address |= (pin << base_address_shift);
}

void port::clearPinFunctionSelection(uint8_t pin){
    *function_selection_register_address &= ~(pin << base_address_shift);
}
