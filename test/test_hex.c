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
	len = _printf("Number:[%x] & [%x]\n", 98, 98);
	len2 = printf("Number:[%x] & [%x]\n", 98, 98);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct input */
	_printf("Testing Correct Input 5617235: \n");
	len = _printf("Number:[%x] & [%x]\n", 5617235, 5617235);
	len2 = printf("Number:[%x] & [%x]\n", 5617235, 5617235);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct max number */
	printf("Testing Correct Input INT_MAX %u: \n", INT_MAX);
	len = _printf("INT_MAX:[%x] & [%x]\n", INT_MAX, INT_MAX);
	len2 = printf("INT_MAX:[%x] & [%x]\n", INT_MAX, INT_MAX);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct max unsigned number */
	printf("Testing Correct Input 4294967295 %u: \n", 4294967295);
	len = _printf("max unsigned:[%x] & [%x]\n", 4294967295, 4294967295);
	len2 = printf("max unsigned:[%x] & [%x]\n", 4294967295, 4294967295);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct max unsigned number */
	printf("Testing Correct Input 4294967295 with # flag %u: \n", 4294967295);
	len = _printf("max unsigned:[%#x] & [%#x]\n", 4294967295, 4294967295);
	len2 = printf("max unsigned:[%#x] & [%#x]\n", 4294967295, 4294967295);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* null */
	printf("Testing NULL: \n");
	len = _printf("INT_MAX:[%x] & [%x]\n", NULL, NULL);
	len2 = printf("INT_MAX:[%x] & [%x]\n", NULL, NULL);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct input */
	_printf("Testing Correct Input 98: \n");
	len = _printf("Number:[%x] & [%x]\n", 98, 98);
	len2 = printf("Number:[%x] & [%x]\n", 98, 98);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct input capital */
	_printf("Testing Correct Input 5617235: \n");
	len = _printf("Number:[%X] & [%X]\n", 5617235, 5617235);
	len2 = printf("Number:[%X] & [%X]\n", 5617235, 5617235);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct max number capital*/
	printf("Testing Correct Input INT_MAX %u: \n", INT_MAX);
	len = _printf("INT_MAX:[%X] & [%X]\n", INT_MAX, INT_MAX);
	len2 = printf("INT_MAX:[%X] & [%X]\n", INT_MAX, INT_MAX);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct max unsigned number capital */
	printf("Testing Correct Input 4294967295 %u: \n", 4294967295);
	len = _printf("max unsigned:[%X] & [%X]\n", 4294967295, 4294967295);
	len2 = printf("max unsigned:[%X] & [%X]\n", 4294967295, 4294967295);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* correct max unsigned number capital */
	printf("Testing Correct Input 4294967295 with # flag %u: \n", 4294967295);
	len = _printf("max unsigned:[%##X] & [%##X]\n", 4294967295, 4294967295);
	len2 = printf("max unsigned:[%##X] & [%##X]\n", 4294967295, 4294967295);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	/* null capital */
	printf("Testing NULL: \n");
	len = _printf("INT_MAX:[%X] & [%X]\n", NULL, NULL);
	len2 = printf("INT_MAX:[%X] & [%X]\n", NULL, NULL);
	printf("Length my printf: %d , Orig Printf len: %d \n", len, len2);
	return (0);
}