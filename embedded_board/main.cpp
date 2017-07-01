#include <msp430.h> 
#include "io.h"
#include "dataManagement.h"
#include "accessHandler.h"
#include "student.h"
#include "captcha.h"
#include "clock.h"
#include "serverCommunication.h"
#include "timer.h"

/*
 * main.c
 */
uint8_t ID = 0;
bool app_flag_test = false;


dataManagement RUManager;
accessHandler RUAccessHandler;

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer


    volatile clock Clock;
    timer TimerA;
    serverCommunication link;
    __enable_interrupt();

    link.readDatabase(RUManager);

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


	__bis_SR_register(GIE);
	while(1){
	    if(TimerA.timerExpired())
	        link.writeDatabase(RUManager);
	}
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
	RUAccessHandler.leaveRequestHandler(ID, RUManager);
	P2IFG &= ~BIT1;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	ID++;
	app_flag_test = false;
	RUAccessHandler.accessRequestHandler(ID, RUManager, app_flag_test);
	if(ID == 15)
		ID = 0;
	P1IFG &= ~BIT1;
}
