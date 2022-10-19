#include <limits.h>
#include <stdio.h>
#include "../main.h"

void generate_string(int byte_len, char *buffer)
{
	int index = 0;

	for (; index < byte_len; index++)
	{
		if (index == byte_len - 1)
		{
			buffer[index] = 'z';
			continue;
		}
		buffer[index] = 'a';
	}
	buffer[byte_len] = '\0';
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	/* char long_str[5014]; */

	/* correct input long str */
	/* _printf("Testing Correct Input long str 5014: \n");
	len = _printf("long str 5014:[%s]\n", long_str);
	len2 = printf("long str 5014:[%s]\n", long_str);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2); */
	/* correct input capital S */
	_printf("Testing Correct Input capital S: \n");
	len = _printf("String:[%S]\n", "New line: \n Tab: \t backspace: \b return: \r");
	printf("Length my printf: %d\n", len);
	/* correct input capital S */
	_printf("Testing Correct Input: \n");
	len = _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
	len += _printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
	printf("Length my printf: %d\n", len);
	/* correct input len S */
	/* _printf("Testing length, should be 14?:\n");
	len = _printf("%S\n", "New line:\n");
	printf("Length my printf: %d\n", len); */
	return (0);
}
