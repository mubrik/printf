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
	_printf("Testing Correct Input: \n");
	len = _printf("Number:[%d] & [%i]\n", 5600, 48484);
	len2 = printf("Number:[%d] & [%i]\n", 5600, 48484);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct input */
	_printf("Testing Correct Input + flag: \n");
	len = _printf("Number:[%+d] & [%+i]\n", 5600, 48484);
	len2 = printf("Number:[%+d] & [%+i]\n", 5600, 48484);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct input */
	_printf("Testing Correct Input   flag: \n");
	len = _printf("Number:[% d] & [% i]\n", 5600, 48484);
	len2 = printf("Number:[% d] & [% i]\n", 5600, 48484);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct input */
	_printf("Testing Correct Input + flag neg number: \n");
	len = _printf("Number:[%+d] & [%+i]\n", INT_MIN, INT_MIN);
	len2 = printf("Number:[%+d] & [%+i]\n", INT_MIN, INT_MIN);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct input 0 */
	_printf("Testing Correct Input 0: \n");
	len = _printf("Number:[%d] & [%i]\n", 0, 0);
	len2 = printf("Number:[%d] & [%i]\n", 0, 0);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct Negative */
	_printf("Testing Correct Input Negative: \n");
	len = _printf("Negative:[%d] & [%d]\n", -5008, -48484);
	len2 = printf("Negative:[%d] & [%d]\n", -5008, -48484);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct max number */
	_printf("Testing Correct Input INT_MAX: \n");
	len = _printf("INT_MAX:[%d] & [%d]\n", INT_MAX, INT_MAX);
	len2 = printf("INT_MAX:[%d] & [%d]\n", INT_MAX, INT_MAX);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct max number negative*/
	_printf("Testing Correct Input negative INT_MAX: \n");
	len = _printf("Negative INT_MAX:[%d] & [%d]\n", (INT_MAX * -1), (INT_MAX * -1));
	len2 = printf("Negative INT_MAX:[%d] & [%d]\n", (INT_MAX * -1), (INT_MAX * -1));
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct max number unsigned */
	_printf("Testing Correct Unsigned INT_MAX: \n");
	len = _printf("Unsigned INT_MAX:[%u] & [%u]\n", INT_MAX, INT_MAX);
	len2 = printf("Unsigned INT_MAX:[%u] & [%u]\n", INT_MAX, INT_MAX);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct max number unsigned */
	_printf("Testing Correct Unsigned 4294967295: \n");
	len = _printf("Unsigned 4294967295:[%u] & [%u]\n", 4294967295, 4294967295);
	len2 = printf("Unsigned 4294967295:[%u] & [%u]\n", 4294967295, 4294967295);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* unsigned NULL */
	_printf("Testing Correct Unsigned NULL: \n");
	len = _printf("Unsigned NULL:[%u] & [%u]\n", NULL, NULL);
	len2 = printf("Unsigned NULL:[%u] & [%u]\n", NULL, NULL);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}