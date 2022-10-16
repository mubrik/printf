#include "main.h"

/**
 * Consider the number 123.456. Cast it to int (discarding the fraction):
 * 123. That's an integer, you know how to print it.
 * Now subtract 123.456 - 123 = 0.456. That's the fraction you have to print.
 * Multiply it by 10: 4.56. Cast it to int: 4.
 * That's the first digit after the decimal you have to print.
 * Now subtract 4.56 - 4 = 0.56. Multiply it by 10: 5.6.
 * Cast it to int to get the next digit past the decimal to print.
 * Repeat until the subtraction gives too small a number.
 * (Note that it will almost never go to 0.)
 */


/**
 * _print_float_rec: recursively cast and print
 * @num: number tye double
 * @count: ptr to count of print
 * Description: works but prints too large as 0 isnt small enough
 */
void _print_float_rec(double num, int *count)
{
	int int_part;
	double zero;

	/* cast */
	int_part = (long int) num;
	zero = 0;
	/* print int */
	_putchar(int_part + '0');
	/* recurse if more */
	if ((num - int_part) > zero)
	{
		_print_float_rec((num - int_part) * 10, count);
	}
}

/**
 * _printfloat: prints float type
 * @arg_list: args list
 * @count: ptr to count of print
 * Return: 1 if it is, 0 if not
 * ref: https://stackoverflow.com/questions/35542757/
 * print-float-without-using-printf-in-c
 */
int _printfloat(va_list arg_list, int *count)
{
	/* float is promoted to double using va_arg */
	double src_float;
	double dec_part;
	long int int_part;

	/* get argument from list */
	src_float = va_arg(arg_list, double);
	/* if neg */
	if (src_float < 0)
	{
		_putchar('-');
		++*count;
		src_float *= -1; /* make absolute */
	}
	/* split the float to an int by casting it to int */
	int_part = (long int) src_float;
	/* print integer part */
	_printint_rec(int_part, count);
	/* print dot, increment count */
	_putchar('.');
	++*count;
	/* get difference from float */
	/* integer will be promoted to double for minus op */
	dec_part = src_float - int_part;
	/* print recurse.. not working correctly */
	/* _print_float_rec(dec_part * 10, count); */
	/* multiply by large number and just print as int */
	dec_part *= 1000000;
	_printint_rec((long int) (dec_part + 0.5) , count);

	return (0);
}
