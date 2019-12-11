#include "rotate.h"
#include "angle_controller.h"

void rotation(double theta, CtrlStruct* struct)
{      
      double r = 0.03;
      double d = 0.215;
      
      double err_angle_gauche = -14*(d/(2*r))*theta;
      double err_angle_droite = 14*(d/(2*r))*theta;
      
      struct->theUserStruct->err_langle = err_angle_gauche;
      struct->theUserStruct->err_rangle = err_angle_droite;
      
      while((err_angle_gauche>0.02)||(err_angle_gauche<-0.02)||(err_angle_droite<-0.02)||(err_angle_droite>0.02))
      {
            run_angle_controller(struct, err_angle_gauche, err_angle_droite);
            err_angle_gauche = struct->theUserStruct->err_langle;
            err_angle_droite = struct->theUserStruct->err_rangle;
      }
      return;
}