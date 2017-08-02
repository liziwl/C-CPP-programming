#include <stdio.h>
#define TEST_VALUE 101

void func_addr(int *x)
{
	*x = TEST_VALUE;
	printf("\nin func_addr,the value of x : %d\n",*x);
}

void func_value(int x)
{
	x = TEST_VALUE;
	printf("\nin func_value,the value of x : %d\n",x);
}

int main()
{
	int a = 42;
	func_value(a);
	printf("after use func_value,the value of a : %d\n",a);
	func_addr(&a);
	printf("after use func_addr,the value of a : %d\n",a);
	return 0;
}