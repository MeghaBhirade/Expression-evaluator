#include<stdio.h>
#include<stdlib.h>
#include<infix.h>

int main()
{

	char stack[100];

	char array[50] ="1+2*(6-3)/6-1";

    infix_prefix_con(array ,stack);

//	infix_postfix_con(array ,stack);

//	post_infix_eval(stack);

	return 0;
}
