#include "CtrlStruct.h"
#include <stdlib.h>



int size_UserStruct(){
    return sizeof(CtrlStruct)*10;
}




CtrlStruct* initalize_struct(){
	CtrlStruct* structure = (CtrlStruct*) malloc(sizeof(CtrlStruct));
	structure->theUserStruct = (UserStruct *) malloc(sizeof(UserStruct));
	structure->theCtrlIn = (CtrlIn *) malloc(sizeof(CtrlIn));
	structure->theCtrlOut = (CtrlOut *) malloc(sizeof(CtrlOut)); 
	structure->theUserStruct->integ_l = 0;
	structure->theUserStruct->integ_r = 0;
	structure->theUserStruct->time = 0;
	structure->theUserStruct->Bintegrate = 0;//boolean integrate pour savoir si il faut intégrer (antiwindup)
	return structure;
}



void freeStruct(CtrlStruct *structure){
	free(structure->theUserStruct);
	free(structure);
}

