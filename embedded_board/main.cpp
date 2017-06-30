#include <msp430.h> 
#include "io.h"
#include "dataManagement.h"
#include "accessHandler.h"
#include "student.h"
#include "captcha.h"
#include "clock.h"
#include "serverCommunication.h"

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
    serverCommunication link;

    volatile uint32_t received_data = 0;
    __enable_interrupt();
	received_data = link.readCredit(5);
	volatile uint8_t aux_credit = (uint8_t) (received_data >> 24);


	Student* aux0;
	Student* aux1;
	Student* aux2;
	Student* aux3;
	Student* aux4;
	Student* aux5;
	Student* aux6;
//	Student* aux7;
//	Student* aux8;
//	Student* aux9;
//	Student* aux10;
//	Student* aux11;
//	Student* aux12;
//	Student* aux13;
//	Student* aux14;
//	Student* aux15;

	aux0 = new Student();
	aux1 = new Student();
	aux2 = new Student();
	aux3 = new Student();
	aux4 = new Student();
	aux5 = new Student();
	aux6 = new Student();
//	aux7 = new Student();
//	aux8 = new Student();
//	aux9 = new Student();
//	aux10 = new Student();
//	aux11 = new Student();
//	aux12 = new Student();
//	aux13 = new Student();
//	aux14 = new Student();
//	aux15 = new Student();

	aux0->setRegistration("00");
	aux0->setCred(0);
	aux1->setRegistration("01");
	aux1->setCred(1);
	aux2->setRegistration("02");
	aux2->setCred(2);
	aux3->setRegistration("03");
	aux3->setCred(3);
	aux4->setRegistration("04");
	aux4->setCred(4);
	aux5->setRegistration("05");
	aux5->setCred(5);
	aux6->setRegistration("06");
	aux6->setCred(5);
//	aux7->setRegistration("07");
//	aux7->setCred(5);
//	aux8->setRegistration("08");
//	aux8->setCred(5);
//	aux9->setRegistration("09");
//	aux9->setCred(5);
//	aux10->setRegistration("10");
//	aux10->setCred(5);
//	aux11->setRegistration("11");
//	aux11->setCred(5);
//	aux12->setRegistration("12");
//	aux12->setCred(5);
//	aux13->setRegistration("13");
//	aux13->setCred(5);
//	aux14->setRegistration("14");
//	aux14->setCred(5);
//	aux15->setRegistration("15");
//	aux15->setCred(5);


	RUManager.insertInRegisteredPeopleList(aux0);
	RUManager.insertInRegisteredPeopleList(aux1);
	RUManager.insertInRegisteredPeopleList(aux2);
	RUManager.insertInRegisteredPeopleList(aux3);
	RUManager.insertInRegisteredPeopleList(aux4);
	RUManager.insertInRegisteredPeopleList(aux5);
	RUManager.insertInRegisteredPeopleList(aux6);
//	RUManager.insertInRegisteredPeopleList(aux7);
//	RUManager.insertInRegisteredPeopleList(aux8);
//	RUManager.insertInRegisteredPeopleList(aux9);
//	RUManager.insertInRegisteredPeopleList(aux10);
//	RUManager.insertInRegisteredPeopleList(aux11);
//	RUManager.insertInRegisteredPeopleList(aux12);
//	RUManager.insertInRegisteredPeopleList(aux13);
//	RUManager.insertInRegisteredPeopleList(aux14);
//	RUManager.insertInRegisteredPeopleList(aux15);

	delete aux0;
	delete aux1;
	delete aux2;
	delete aux3;
	delete aux4;
	delete aux5;
	delete aux6;
//	delete aux7;
//	delete aux8;
//	delete aux9;
//	delete aux10;
//	delete aux11;
//	delete aux12;
//	delete aux13;
//	delete aux14;
//	delete aux15;

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
	while(1);
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
