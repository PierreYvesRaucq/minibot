#include "move.h"

void fwd (double dist, double goal, CtrlStruct* str)
{
    double slow = 350; //limite à laquelle on commence à ralentir
    double approach = 100; //limite pour lancer la phase d'aproche
    double v_full = 400;
    double v_slow = 100;
    double K = v_slow/approach;

    if (dist<goal*1.1) //10% => ok
    {
        run_speed_controller(str, 0);
    }
    else if (dist-goal > slow)
    {
        run_speed_controller(str, 300); //loin donc full
    }
    else if (dist-goal > approach)
    {
        run_speed_controller(str, 100); //on approche donc on ralentit
    }
    else
    {
        run_speed_controller(str, K*(dist-goal); //on y est presque donc prop à la dist
    }
}
