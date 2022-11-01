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

	/* correct input pointer */
	_printf("Testing Correct Input capital S: \n");
	len = _printf("%p\n", (void *)0x7fff5100b608);
	len2 = printf("%p\n", (void *)0x7fff5100b608);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* NULL */
	_printf("Testing NULL: \n");
	len = _printf("%p\n", NULL);
	len2 = printf("%p\n", NULL);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* Testing sr add 0x7fff5100b6f8 */
	_printf("Testing sr add 0x7fff5100b6f8: \n");
	len = _printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	len2 = printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* Testing sr add -1 */
	_printf("Testing sr add -1: \n");
	len = _printf("Can you print an address?\n%p\nNice!\n", (void *)-1);
	len2 = printf("Can you print an address?\n%p\nNice!\n", (void *)-1);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* Testing multiple flags */
	_printf("Testing multiple flags: \n");
	len = _printf("%pppp\n", (void *)0x7fff5100b6f8);
	len2 = printf("%pppp\n", (void *)0x7fff5100b6f8);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* Testing severalr add */
	_printf("Testing severalr add: \n");
	len = _printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	len2 = printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}
