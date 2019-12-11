#include "rotate.h"
#include "angle_controller.h"

void rotation(double theta, CtrlStruct* str)
{      
      double r = 0.03;
      double d = 0.215;
      
      double err_angle_gauche = -(d/(2*r))*theta;
      double err_angle_droite = (d/(2*r))*theta;
      
      str->theUserStruct->err_langle = err_angle_gauche;
      str->theUserStruct->err_rangle = err_angle_droite;
      
      str->theUserStruct->integ_err_l_prev = 0;
      str->theUserStruct->integ_err_r_prev = 0;
      
      while((err_angle_gauche>0.02)||(err_angle_gauche<-0.02)||(err_angle_droite<-0.02)||(err_angle_droite>0.02))
      {
            run_angle_controller(str, err_angle_gauche, err_angle_droite);
            err_angle_gauche = str->theUserStruct->err_langle;
            err_angle_droite = str->theUserStruct->err_rangle;
      }
      return;
}
