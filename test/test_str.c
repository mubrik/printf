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
	len = _printf("String:[%s]\n", "This is a string!@#11a");
	len2 = printf("String:[%s]\n", "This is a string!@#11a");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* no input */
	_printf("Testing no input: \n");
	len = _printf("String:[%s]\n");
	len2 = printf("String:[%s]\n");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is null */
	_printf("Testing input is null: \n");
	len = _printf("String:[%s]\n", NULL);
	len2 = printf("String:[%s]\n", NULL);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is null byte */
	_printf("Testing input is nullbyte: \n");
	len = _printf("String:[%s]\n", '\0');
	len2 = printf("String:[%s]\n", '\0');
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is string "Ghh" */
	_printf("Testing input string Ghh: \n");
	len = _printf("String:[%s]\n", "Ghh");
	len2 = printf("String:[%s]\n", "Ghh");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is string "Ghh", percentage at end */
	_printf("Testing percentage at end of str: \n");
	len = _printf("String:[%s]%\n", "Ghh");
	len2 = printf("String:[%s]%\n", "Ghh");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is string "Ghh", unknown flag */
	_printf("Testing unknown flag: \n");
	len = _printf("Unknown:[%r]\n", "Ghh");
	len2 = printf("Unknown:[%r]\n", "Ghh");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is number 123434, THIS CAUSES SEG DUMP FOR BOTH! */
	_printf("Testing input is number 123434: \n");
	/* len = _printf("String:[%s]\n", 123434); */
	/* len2 = printf("String:[%s]\n", 123434); */
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}