#ifndef _CAPTCHA_H
#define _CAPTCHA_H

#include <stdlib.h>
#include <stdint.h>

class captcha{
private:

public:
	captcha();
	~captcha();
	uint8_t getRandomNumber(void);

};

#endif // _CAPTCHA_H
