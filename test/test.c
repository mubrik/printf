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
	int len = 0, len2 = 0;
	/* char long_str[5014]; */

	/* correct input long str */
	/* _printf("Testing Correct Input long str 5014: \n");
	len = _printf("long str 5014:[%s]\n", long_str);
	len2 = printf("long str 5014:[%s]\n", long_str);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2); */
	/* correct input pointer */
	_printf("Testing Correct Input capital S: \n");
	len = _printf("% ");
	len2 = printf("% ");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}
