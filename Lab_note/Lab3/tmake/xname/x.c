#include "..\lab3.h"

#include "x.h"

void x_func1()
{
	#if X_DEBUG
	printf("\n\tStart_debug X_func1 \n");
	#endif
	
	printf(X_FUNC);
	
	#if X_DEBUG
	printf("\n\tEnd_debug X_func1 \n");
	#endif
}
//void main()
//{
//}