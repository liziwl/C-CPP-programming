#include "..\lab3.h"
void y_func1()
{
	#if Y_DEBUG
	printf("\n\tStart_debug Y_func1 \n");
	#endif
	
	printf(Y_FUNC);
	
	#if Y_DEBUG
	printf("\n\tEnd_debug Y_func1 \n");
	#endif
}