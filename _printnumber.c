#include "main.h"

/**
 * _printint_rec: recursive func to print
 * @num: src char ptr
 * @count: ptr to count of print
 * Return: 1 if it is, 0 if not
 * Description: works recursively, wont print until last digit which becomes first
 */
void _printint_rec(int num, int *count)
{
	if (num > 9)
	{
		/* divide by 10 */
		_printint_rec(num / 10, count);
	}
	/* print reminder, which wil be the last number */
	_putchar((num % 10) + '0');
	++*count;
}

/**
 * _printnumber: prints numbers/integers
 * @src_ptr: src char ptr
 * @count: ptr to count of print
 * Return: 1 if it is, 0 if not
 */
int _printnumber(va_list arg_list, int *count)
{
	int src_nmbr;

	/* get argument from list */
	src_nmbr = va_arg(arg_list, int);
	/* if negative */
	if (src_nmbr < 0)
	{
		_putchar('-');
		++*count;
		src_nmbr *= -1; /* make absolute */
	}
	/* print recursively */
	_printint_rec(src_nmbr, count);

	return (0);
}
