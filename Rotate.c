#include "rotate.h"
#include "angle_controller.h"

void rotation(double theta, CtrlStruct* struct)
{      
      double r = 0.03;
      double d = distance_entre_roues;
      
      double comm_gauche = - 14*(d/2r)*theta;
      double comm_droite = + 14*(d/2r)*theta;
      
      run_angle_controller(struct, comm_gauche, comm_droite);
}
