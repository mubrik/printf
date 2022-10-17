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
	int len, len2, nil, nil2;

	nil = _printf("String:[%s]\n");
	nil2 = printf("String:[%s]\n");
	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Sub Characters %c %c %c\n", 'a', 'b', 'c');
	printf("Sub Characters %c %c %c\n", 'a', 'b', 'c');
	_printf("Sub String %s %s %s\n", "stringa", "stringb", "stringc");
	printf("Sub String %s %s %s\n", "stringa", "stringb", "stringc");
	len = _printf("Mix String & Chars %c %s %c %s %% %% \n", 'a', "stringb", 'b', "stringify");
	len2 = printf("Mix String & Chars %c %s %c %s %% %% \n", 'a', "stringb", 'b', "stringify");
	/* _printf("Numbers Floatt and decimal %f %f %f %d %d %i %i\n", 1255.66, -12.447, 1.6, 2.2, -0.5, '7', -777777);
	printf("Numbers Floatt and decimal %f %f %f %d %d %i %i\n", 1255.66, -12.447, 1.6, 2.2, -0.5, '7', -777777); */

	printf("Length c printf: %d, length myprintf: %d\n", len2, len);
	printf("NULl c printf: %d, NULl myprintf: %d\n", nil2, nil);
	return (0);
}