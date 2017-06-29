#include <msp430.h> 
#include "io.h"
#include "dataManagement.h"
#include "accessHandler.h"
#include "student.h"
#include "captcha.h"

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

	Student* aux0;
	Student* aux1;
	Student* aux2;
	Student* aux3;
	Student* aux4;
	Student* aux5;
	aux0 = new Student();
	aux1 = new Student();
	aux2 = new Student();
	aux3 = new Student();
	aux4 = new Student();
	aux5 = new Student();

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

	RUManager.insertInRegisteredPeopleList(aux0);
	RUManager.insertInRegisteredPeopleList(aux1);
	RUManager.insertInRegisteredPeopleList(aux2);
	RUManager.insertInRegisteredPeopleList(aux3);
	RUManager.insertInRegisteredPeopleList(aux4);
	RUManager.insertInRegisteredPeopleList(aux5);

	delete aux0;
	delete aux1;
	delete aux2;
	delete aux3;
	delete aux4;
	delete aux5;

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
	if(ID == 11)
		ID = 0;
	P1IFG &= ~BIT1;
}
