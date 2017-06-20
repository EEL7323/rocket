#include "captcha.h"

captcha::captcha(): P3(P3_address){
	P3.setPinDirection(BIT0, output);
	P3.setPinDirection(BIT1, output);
	P3.setPinDirection(BIT2, input);
	P3.setPinDirection(BIT3, input);
	P3OUT = 0;
}

captcha::~captcha(){

}

uint8_t captcha::getRandomNumber(void){
	uint8_t aux;
	aux = (rand() % 3) + 1;
	P3OUT = aux;
	return aux;
}

bool captcha::verifyCaptcha(uint8_t captcha){
	if (captcha == ((P3IN & 0x0C) >> 2))
		return true;
	else return false;

}