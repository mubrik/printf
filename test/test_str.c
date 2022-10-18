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
	int len, len2;
	char long_str[1026];

	generate_string(1026, long_str);
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
	/* input is string "Ghh", mising an argument */
	_printf("Testing an argument missing: \n");
	len = _printf("3rd arg missing:[%s], [%s], [%s] \n", "first", "second");
	len2 = printf("3rd arg missing:[%s], [%s], [%s] \n", "first", "second");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* input is string "Ghh", more tests */
	_printf("Testing an argument missing: \n");
	len = _printf("2nd arg missing:[%s], [%s], [%s] \n", "first", '\0', "second");
	len2 = printf("2nd arg missing:[%s], [%s], [%s] \n", "first", '\0', "second");
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	/* correct input long str */
	_printf("Testing Correct Input long str 1026: \n");
	len = _printf("long str 1026:[%s]\n", long_str);
	len2 = printf("long str 1026:[%s]\n", long_str);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2);
	return (0);
}
