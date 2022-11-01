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
	int len = 0, len2 = 0;

	_printf("Testing Correct mod flag + width: \n");
	len = _printf("%l\n");
	len2 = printf("%l\n");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}
