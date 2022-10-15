#include "main.h"

/**
 * _printchar: prints a single character
 * @arg_list: args list
 * @count: ptr to count of print
 * Return: 1 if it is, 0 if not
 */
int _printchar(va_list arg_list, int *count)
{
	int str;
	/* get arg from list */
	str = va_arg(arg_list, int);

	_putchar(str);
	/* incr count */
	++*count;

	return (0);
}