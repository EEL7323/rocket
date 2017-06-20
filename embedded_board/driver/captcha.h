#ifndef _CAPTCHA_H
#define _CAPTCHA_H

#include <stdlib.h>
#include <stdint.h>
#include "io.h"

class captcha{
private:
	port P3;

public:
	captcha();
	~captcha();
	uint8_t getRandomNumber(void);
	bool verifyCaptcha(uint8_t captcha);

};

#endif // _CAPTCHA_H
