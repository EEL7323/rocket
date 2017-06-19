#include <msp430.h> 
#include "io.h"

/*
 * main.c
 */
uint8_t ID = 0;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  port P2(P2_address);
  P2.setPinPullup(BIT1);
  P2.setPin(BIT1);
  P2.setInterruptEdge(BIT1, falling);
  P2.clearInterruptFlag(BIT1);
  P2.enableInterrupt(BIT1);

  port P1(P1_address);
  P1.setPinPullup(BIT1);
  P1.setPin(BIT1);
  P1.setInterruptEdge(BIT1, falling);
  P1.clearInterruptFlag(BIT1);
  P1.enableInterrupt(BIT1);

  __bis_SR_register(GIE);       // Enter LPM4 w/interrupt
  while(1);
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
  ID++;
  if(ID == 11)
      ID = 0;
  P2IFG &= ~BIT1;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
  __no_operation();
}
