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
	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* no input */
	_printf("Testing no input: \n");
	len = _printf("Character:[%c]\n");
	len2 = printf("Character:[%c]\n");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is null */
	_printf("Testing input is null: \n");
	len = _printf("Character:[%c]\n", NULL);
	len2 = printf("Character:[%c]\n", NULL);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is null byte */
	_printf("Testing input is nullbyte: \n");
	len = _printf("Character:[%c]\n", '\0');
	len2 = printf("Character:[%c]\n", '\0');
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is string "Ghh" */
	_printf("Testing input string Ghh: \n");
	len = _printf("Character:[%c]\n", "Ghh");
	len2 = printf("Character:[%c]\n", "Ghh");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}