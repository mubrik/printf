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
	int len;
	/* correct input */
	_printf("Testing Correct Input 98: \n");
	len = _printf("Number:[%b] & [%b]\n", 98, 98);
	printf("Length my printf: %d \n", len);
	/* correct max number */
	printf("Testing Correct Input INT_MAX %u: \n", INT_MAX);
	len = _printf("INT_MAX:[%b] & [%b]\n", INT_MAX, INT_MAX);
	printf("Length my printf: %d\n", len);
	return (0);
}