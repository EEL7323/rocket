#include "timer.h"

uint8_t timer::counter = 0;

timer::timer(){
    TA0CCR0 = 50000;
    TA0CTL = TASSEL_2 + MC_1 + TACLR + ID_3;
    //TA0CCTL0 |= CCIE;
}

timer::~timer(){

}

bool timer::timerExpired(void){
    if(counter >= 99){
        counter = 0;
        return true;
    }
    else
        return false;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void timer::TIMER0_A0_ISR(void)
{
  counter++;
}

