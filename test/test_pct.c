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
	_printf("Testing Correct Input: double prct \n");
	len = _printf("Character:[%%]\n");
	len2 = printf("Character:[%%]\n");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* double perct with string*/
	_printf("Testing double perct with string \n");
	len = _printf("Character:[%%]\n", "A string");
	len2 = printf("Character:[%%]\n", "A string");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* Testing double perct with null */
	_printf("Testing double perct with null: \n");
	len = _printf("Character:[%%]\n", NULL);
	len2 = printf("Character:[%%]\n", NULL);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* invalid input */
	_printf("Testing Correct Input: multiple flags \n");
	len = _printf("Character:[%%% ++% multiple flags before\n");
	len2 = printf("Character:[%%% ++% multiple flags before\n");
	/* invalid input */
	_printf("Testing Correct Input: triple prct \n");
	len = _printf("Character:[%%%\n");
	len2 = printf("Character:[%%%\n");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}