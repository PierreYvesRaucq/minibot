#include <stdio.h>
#include <stdlib.h>
//#include "CtrlStruct.h"

void run_angle_controller(CtrlStruct* str, double err_angle_gauche, err_angle_droite){
    double kangle=1;
	  double ki=0.066;
    double kp=0.017;//0.025
    double kPhi=0.0261;
    double K=0.9998;
    
    double omega_ref_m_l = kangle*err_angle_gauche;
    double omega_ref_m_r = kangle*err_angle_droite;

    double lspeed = str->theCtrlIn->l_wheel_speed;
    double rspeed = str->theCtrlIn->r_wheel_speed;
    
    double omega_m_l = lspeed*14;
    double omega_m_r = rspeed*14;

    double t = str->theCtrlIn->t;
    double t_prev = str->theUserStruct->tprev;

    double period = t-t_prev;
    double err_l = omega_ref_m_l-omega_m_l;
    double err_r = omega_ref_m_r-omega_m_r;

    double integ_err_l = err_l*period + struct->theUserStruct->integ_err_l_prev;
    double integ_err_r = err_r*period + struct->theUserStruct->integ_err_r_prev;
	
	double rot_langle = lspeed*period*0.06/0.215;
	double rot_rangle = rspeed*period*0.06/0.215;
	
	str->theUserStruct->err_langle = str->theUserStruct->err_langle - rot_langle;
	str->theUserStruct->err_rangle = str->theUserStruct->err_rangle - rot-rangle;

    if (integ_err_l>0.95*24)
        {integ_err_l = 0.95*24;}
    if (integ_err_r>0.95*24)
        {integ_err_r = 0.95*24;}

    double vl = kp*err_l + ki*integ_err_l;
    double vr = kp*err_r + ki*integ_err_r;

    double Vl = vl+kPhi*omega_m_l/K;
    double Vr = vr+kPhi*omega_m_r/K;

    theCtrlStruct->theUserStruct->integ_err_l_prev = integ_err_l;
    theCtrlStruct->theUserStruct->integ_err_r_prev = integ_err_r;
    theCtrlStruct->theUserStruct->tprev = t;

    double Comm_l;
    double Comm_r;

    if (Vl>0.95*24)
        {Comm_l = 100;}
    else
    {
        if (Vl<-0.95*24)
            {Comm_l = -100;}
        else
            {Comm_l = Vl*100/(0.95*24);}
    }

    if (Vr>0.95*24)
        {Comm_r = 100;}
    else
    {
        if (Vr<-0.95*24)
            {Comm_r = -100;}
        else
            {Comm_r = Vr*100/(0.95*24);}
    }

        str->theCtrlOut->wheel_commands[L_ID] = Comm_l;
        str->theCtrlOut->wheel_commands[R_ID] = Comm_r;

	return;
}
