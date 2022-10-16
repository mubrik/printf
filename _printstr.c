#include "main.h"

/**
 * _printstr: prints a string of chars
 * @src_ptr: src char ptr
 * @count: ptr to count of print
 * Return: 1 if it is, 0 if not
 */
int _printstr(va_list arg_list, int *count)
{
	char *src_ptr;

	/* get argument from list */
	src_ptr = va_arg(arg_list, char *);

	while (*src_ptr != '\0')
	{
		/* print */
		_putchar(*src_ptr);
		/* incr count and src ptr*/
		++*count;
		++src_ptr;
	}

	return (0);
}
