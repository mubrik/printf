#include "main.h"

/**
 * _printint - prints an integer
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: number of chars printed.
 */
int _printint(va_list args, char *buffer, unsigned int buffer_index)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isneg;

	int_input = va_arg(args, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffer_index = handle_buf(buffer, '-', buffer_index);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_index = handle_buf(buffer, ((int_in / div) % 10) + '0', buffer_index);
	}
	return (i + isneg);
}
