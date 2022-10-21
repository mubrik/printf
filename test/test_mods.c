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
	len = _printf("%6c", 'A');
	len2 = printf("%6c", 'A');
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	_printf("Testing Correct mod flag + width: \n");
	len = _printf("%6c", 0);
	len2 = printf("%6c", 0);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	_printf("Testing Correct mod flag + width: \n");
	len = _printf("In the middle %6c of a sentence.\n", 'H');
	len2 = printf("In the middle %6c of a sentence.\n", 'H');
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	_printf("Testing Correct mod flag + width: \n");
	len = _printf("%-6c", 'A');
	len2 = printf("%-6c", 'A');
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	_printf("Testing Correct mod flag + width: \n");
	len = _printf("%-6c", 0);
	len2 = printf("%-6c", 0);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	_printf("Testing Correct mod flag + width: \n");
	len = _printf("In the middle %-6c of a sentence.\n", 'H');
	len2 = printf("In the middle %-6c of a sentence.\n", 'H');
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}
