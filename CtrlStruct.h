#include "../IO/ctrl_io.h"

typedef struct UserStruct{
	double integ_l;
	double integ_r;
	double time;
	int Bintegrate ;//boolean integrate pour savoir si il faut intégrer (antiwindup)
} UserStruct;

typedef struct CtrlStruct{
	UserStruct *theUserStruct;  ///< user defined CtrlStruct
	CtrlIn *theCtrlIn;   ///< controller inputs
	CtrlOut *theCtrlOut; ///< controller outputs
} CtrlStruct;

int size_UserStruct();

CtrlStruct* initalize_struct(); 