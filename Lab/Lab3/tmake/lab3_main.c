#include <stdio.h>
#include "lab3.h"

extern void x_func1();
extern void y_func1();

int main(int argc,char *argv[])
{
	#if MAIN_DEBUG
	printf("main_debug_start\n");
	#endif
	x_func1();
	y_func1();
	#if MAIN_DEBUG
	printf("main_debug_ends\n");
	#endif
}