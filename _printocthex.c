#include "main.h"

/**
 * _int_to_oct_buff - adds octal chars to the buffer
 * @integer: integer
 * @bin_b: the ptr to a buffer
 * @num: num of bytes in buff
 */
void _int_to_oct_buff(unsigned int integer, char *bin_b, int num)
{

	for (; num >= 0; num--)
	{
		if (integer <= 0)
		{
			bin_b[num] = '0';
			continue;
		}
		bin_b[num] = (integer % 8) + '0';
		integer /= 8;
	}
}

/**
 * _int_to_hex_buff - adds hex chars to the buffer
 * @integer: integer
 * @bin_b: the ptr to a buffer
 * @num: num of bytes in buff
 */
void _int_to_hex_buff(unsigned int integer, char *bin_b, int num)
{
	int res;

	for (; num >= 0; num--)
	{
		if (integer <= 0)
		{
			bin_b[num] = '0';
			continue;
		}
		res = (integer % 16);
		res = (res > 9) ? (res + 'W') : (res + '0');
		bin_b[num] = res;
		integer /= 16;
	}
}

/**
 * handle_oct_format - adds a binary to the buffer
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: ptr to index of buffer
 * @flags: flags to modify behaviour
 * Return: count of chars added
 */
int handle_oct_format(va_list arg_list, char *buffer,
	int *buffer_i, __attribute__((unused)) Format_flag_t *flags)
{
	unsigned int num, count = 0, bytes;
	char *bin_buffer, *cp_buff;
	/* get num from list */
	num = va_arg(arg_list, int);
	/* base check */
	if (!num)
	{
		add_to_buffer('0', buffer, buffer_i);
		return (1);
	}
	bytes = 10; /* max needed for unsigned int to octal */
	/* maloc */
	bin_buffer = malloc((sizeof(char) * bytes) + 1);
	if (!bin_buffer)
		return (0);
	bin_buffer[bytes + 1] = '\0';
	_int_to_oct_buff(num, bin_buffer, bytes);
	/* push buffer ptr until we hit the fisrt 1 */
	cp_buff = bin_buffer;
	while (*bin_buffer == '0')
		bin_buffer++;
	/* buffer, strat from 1 excluding first zeros of binary */
	while (bin_buffer[count])
	{
		add_to_buffer((bin_buffer[count]), buffer, buffer_i);
		count++;
	}
	/* free buffer */
	free(cp_buff);
	return (count);
}

/**
 * handle_shex_format - adds a hex to the buffer small letter!
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: ptr to index of buffer
 * @flags: flags to modify behaviour
 * Return: count of chars added
 */
int handle_shex_format(va_list arg_list, char *buffer,
	int *buffer_i, __attribute__((unused)) Format_flag_t *flags)
{
	unsigned int num, count = 0, bytes;
	char *bin_buffer, *cp_buff;
	/* get num from list */
	num = va_arg(arg_list, int);
	/* base check */
	if (!num)
	{
		add_to_buffer('0', buffer, buffer_i);
		return (1);
	}
	bytes = 7; /* max needed for unsigned int to octal */
	/* maloc */
	bin_buffer = malloc((sizeof(char) * bytes) + 1);
	if (!bin_buffer)
		return (0);
	bin_buffer[bytes + 1] = '\0';
	_int_to_hex_buff(num, bin_buffer, bytes);
	/* push buffer ptr until we hit the fisrt non zero*/
	cp_buff = bin_buffer;
	while (*bin_buffer == '0')
		bin_buffer++;
	while (bin_buffer[count])
	{
		add_to_buffer((bin_buffer[count]), buffer, buffer_i);
		count++;
	}
	/* free buffer */
	free(cp_buff);
	return (count);
}

/**
 * handle_chex_format - adds a hex to the buffer capital letter!
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: ptr to index of buffer
 * @flags: flags to modify behaviour
 * Return: count of chars added
 */
int handle_chex_format(va_list arg_list, char *buffer,
	int *buffer_i, __attribute__((unused)) Format_flag_t *flags)
{
	unsigned int num, count = 0, bytes;
	char *bin_buffer, *cp_buff;
	/* get num from list */
	num = va_arg(arg_list, int);
	/* base check */
	if (!num)
	{
		add_to_buffer('0', buffer, buffer_i);
		return (1);
	}
	bytes = 7; /* max needed for unsigned int to octal */
	/* maloc */
	bin_buffer = malloc((sizeof(char) * bytes) + 1);
	if (!bin_buffer)
		return (0);
	bin_buffer[bytes + 1] = '\0';
	_int_to_hex_buff(num, bin_buffer, bytes);
	/* push buffer ptr until we hit the fisrt non zero*/
	cp_buff = bin_buffer;
	while (*bin_buffer == '0')
		bin_buffer++;
	while (bin_buffer[count])
	{
		capitalize_alpha(&bin_buffer[count]);
		add_to_buffer((bin_buffer[count]), buffer, buffer_i);
		count++;
	}
	/* free buffer */
	free(cp_buff);
	return (count);
}
