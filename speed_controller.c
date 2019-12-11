#include "speed_controller.h"

double sat(double limit, double value)
{
    if(value < limit){
		return value;
	}
	else{
		return limit;
	}
}

double Ufinal (double U, double mes)
{
    double I = sat(IN, U/RA);
    return sat(UN, I*RA+KPHI*mes*REDUCTION);
}


void run_speed_controller(CtrlStruct* theCtrlStruct, double* omega_ref){

    double wm_l = theCtrlStruct->theCtrlIn->l_wheel_speed;
    double wm_r = theCtrlStruct->theCtrlIn->r_wheel_speed;

	double err_omega_l = (omega_ref[L_ID] - wm_l)*REDUCTION;
	double err_omega_r = (omega_ref[L_ID] - wm_r)*REDUCTION;

    double period = theCtrlStruct->theCtrlIn->t - theCtrlStruct->theUserStruct->time; //calcul de la periode
	theCtrlStruct->theUserStruct->time = theCtrlStruct->theCtrlIn->t;


    if(theCtrlStruct->theUserStruct->Bintegrate){
		theCtrlStruct->theUserStruct->integ_l += err_omega_l* period;//periode à calculer
		theCtrlStruct->theUserStruct->integ_r += err_omega_r* period;
	}

    double U_ref_l = KP*(err_omega_l) + KI*theCtrlStruct->theUserStruct->integ_l;//calcul des U
	double U_ref_r = KP*(err_omega_r) + KI*theCtrlStruct->theUserStruct->integ_r;

    double final_U_l = Ufinal(U_ref_l, wm_l); //recalcul du U en gérant les saturation en courrant et en tension
    double final_U_r = Ufinal(U_ref_r, wm_r);

    ///anti windup : on arrete d'intégré si on est déjà en saturation

    if (final_U_l==UN || final_U_r==UN)
    {
        theCtrlStruct->theUserStruct->Bintegrate = 0;
    }
    else
    {
        theCtrlStruct->theUserStruct->Bintegrate = 1;
    }

    theCtrlStruct->theCtrlOut->wheel_commands[L_ID] = final_U_l*100/(0.95*24);
	theCtrlStruct->theCtrlOut->wheel_commands[R_ID] = final_U_r*100/(0.95*24);
	return;
}

void init_speed_controller(CtrlStruct* theCtrlStruct){
    theCtrlStruct->theUserStruct->Bintegrate = 1;
    theCtrlStruct->theUserStruct->time = theCtrlStruct->theCtrlIn->t;
	return;
}
