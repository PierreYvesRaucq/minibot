#include "rotate.h"
#include "angle_controller.h"

void rotation(double theta, CtrlStruct* struct)
{      
      double r = 0.03;
      double d = distance_entre_roues;
      
      double angle_gauche = struct->theCtrlIn->angle_gauche;
      double angle_droit = struct->theCtrlIn->angle_droit;
      
      double angle_comm_gauche = angle_gauche - 14*(d/2r)*theta;
      double angle_comm_droite = angle_droite + 14*(d/2r)*theta;
      
      run_angle_controller(struct, angle_comm_gauche, angle_comm_droite);
}
