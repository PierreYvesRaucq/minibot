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
	
	quit = 0; // variable de sortie d'urgence
	
	// initialisation du CAN, de la structure et du speed controller
	CAN *can; 
	can = new CAN(CAN_BR); 
	can->configure();
	can->ctrl_motor(1);
	CtrlStruct* structure = initalize_struct();
	init_speed_controller(structure);
	
	//tourelle tourne à une valeur constante (valeur mise au hasard) 
	can->push_TowDC(10);
	
	while(1){
		angle; // Bruno : fonction qui renvoie (ou actualise un paramêtre de la structure on verra après) les 2 angles de détection de l'obstacle
		rotation(angle); //Pierre-Yves : fonction qui renvoie (ou actualise un paramêtre de la structure on verra après) les 2 commande à donner au roues pour que le robot tourne d'un angle theta
		avancement(D); // Pierre : fonction qui renvoie (ou actualise un paramêtre de la structure on verra après) les 2 commande à donner au roues pour que le robot avance d'une dist D 
		
		//on va rechrcher le paramètre commande des roue dans la structure et on les applique
		double cmdL = structure->theCtrlOut->wheel_commandsL; 
		double cmdR = structure->theCtrlOut->wheel_commandsR;
		printf("command0 %f, command1 %f\n", cmdL, cmdR);
		can->push_PropDC(cmdL, cmdR);
			
		if(quit ==1){
			break;
		}
	}
	
can->ctrl_motor(0);
}
