#include "captcha.h"

captcha::captcha(){

}

captcha::~captcha(){

}

uint8_t captcha::getRandomNumber(void){
	return (uint8_t) ((rand() % 4) + 1);
}
