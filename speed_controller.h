#ifndef _SPEED_CONTROLLER_H_
#define _SPEED_CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CtrlStruct.h"

#define REDUCTION 14
#define KPHI 0.0261
#define KP 0.0199
#define KI 0.1219
#define UN 24
#define IN 0.689
#define RA 7.1
#define PERIOD 0.04 //enlever si on calcul la période en live

double sat(double limit, double value);
double Ufinal (double U, double mes);
void run_speed_controller(CtrlStruct *theCtrlStruct, double* omega_ref);
void init_speed_controller(CtrlStruct* theCtrlStruct);


#endif //ifndef
