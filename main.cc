#include <cstdio>

#include <wiringPiSPI.h>
#include "IO/COM/CAN/CAN.hh"
#include "IO/COM/SPI/Specific/SPI_CAN.hh"
#include "IO/COM/SPI/SPI.hh"


#define CAN_BR 125e3

int main()
{
	printf("hello world\n");
	printf("##############################################################################################################\n");
    	printf("\t\t\tWelcome to the Minibot project of the ELEME2002 class :)");
    	printf("##############################################################################################################\n");
    	printf("\t\t I'm Miss Sunshine, please take care of me !\n");
    	printf("\t\t Please do not interchange the chips on my tower/motor PWM boards !\n");
    	printf("\t\t Try to respect the C-file interface when programming me because\n \t\t it will be the same in the robotic project (Q2) !\n");


	CtrlStruct* structure = initialize_struct();
	double tp = structure->theCtrlIn->tower_pos;
	CAN *can;
	can = new CAN(CAN_BR);
	can->configure();
	can->ctrl_motor(1);
	can->push_TowDC(10);
	can->push_PropDC(tp,10);

}

