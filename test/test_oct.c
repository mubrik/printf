#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;
	/* correct input */
	_printf("Testing Correct Input 98: \n");
	len = _printf("Number:[%o] & [%o]\n", 98, 98);
	len2 = printf("Number:[%o] & [%o]\n", 98, 98);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct max number */
	printf("Testing Correct Input INT_MAX %u: \n", INT_MAX);
	len = _printf("INT_MAX:[%o] & [%o]\n", INT_MAX, INT_MAX);
	len2 = printf("INT_MAX:[%o] & [%o]\n", INT_MAX, INT_MAX);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* null */
	printf("Testing NULL: \n");
	len = _printf("INT_MAX:[%o] & [%o]\n", NULL, NULL);
	len2 = printf("INT_MAX:[%o] & [%o]\n", NULL, NULL);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	return (0);
}