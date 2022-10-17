#include "main.h"

/**
 * _int_to_bin_buff - adds binary chars to the buffer
 * @integer: integer
 * @bin_b: the ptr to a buffer
 * @num: num of bytes in buff
 */
void _int_to_bin_buff(unsigned int integer, char *bin_b, int num)
{
	int i;
	/* binary stuff */
	for (i = 0; i < num; i++)
		bin_b[i] = (integer & 1 << (num - i - 1)) ? '1' : '0';
	/* null byte */
	bin_b[num] = '\0';
}

/**
 * handle_bin_format - adds a binary to the buffer
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: index of buffer
 * @flags: flags to modify behaviour
 * Return: count of chars added
 */
int handle_bin_format(va_list arg_list, char *buffer,
	char buffer_i, __attribute__((unused)) Format_flag_t *flags)
{
	unsigned int num, count = 0, bytes;
	char *bin_buffer;
	/* get num from list */
	num = va_arg(arg_list, int);
	bytes = (num < 1025) ? 8 : (num < 65536) ? 16 : 32;
	/* maloc */
	bin_buffer = malloc((sizeof(char) * bytes) + 1);
	if (!bin_buffer)
		return (0);
	_int_to_bin_buff(num, bin_buffer, bytes);
	/* buffer */
	while (bin_buffer[count])
	{
		buffer_i = add_to_buffer((bin_buffer[count]), buffer, buffer_i);
		count++;
	}

	return (count);
}
