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
 * int_to_hex_buff - adds hex chars to the buffer
 * @integer: integer
 * @bin_b: the ptr to a buffer
 * @num: num of bytes in buff
 */
void int_to_hex_buff(unsigned int integer, char *bin_b, int num)
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
 * @mods: ptr of modifiers
 * Return: count of chars added
 */
int handle_oct_format(va_list arg_list, char *buffer,
	int *buffer_i, Modifiers_t *mods)
{
	unsigned int count = 0, index = 0, bytes;
	char *bin_buffer, *cp_buff;
	unsigned long int num_l = 1;
	unsigned int num_s = 1;
	/* get num from list */
	if (mods->length->long_m)
		num_l = va_arg(arg_list, long int), bytes = 21;
	else
		num_s = va_arg(arg_list, int), bytes = 10;
	if (!num_l || !num_s)
	{
		add_to_buffer('0', buffer, buffer_i);
		return (1);
	}
	/* maloc */
	bin_buffer = malloc((sizeof(char) * bytes) + 1);
	if (!bin_buffer)
		return (0);
	bin_buffer[bytes + 1] = '\0';
	if (mods->length->long_m)
		long_int_to_oct_buff(num_l, bin_buffer, bytes);
	else
		_int_to_oct_buff(num_s, bin_buffer, bytes);
	/* push buffer ptr until we hit the fisrt 1 */
	cp_buff = bin_buffer;
	while (*bin_buffer == '0')
		bin_buffer++;
	/* handling # flag */
	if ((mods->flags->pound) && bin_buffer[index])
		add_to_buffer('0', buffer, buffer_i), index++;
	/* buffer, strat from 1 excluding first zeros of binary */
	while (bin_buffer[count])
	{
		add_to_buffer((bin_buffer[count]), buffer, buffer_i);
		count++;
	}
	/* free buffer */
	free(cp_buff);
	return (count + index);
}

/**
 * handle_shex_format - adds a hex to the buffer small letter!
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: ptr to index of buffer
 * @mods: ptr of modifiers
 * Return: count of chars added
 */
int handle_shex_format(va_list arg_list, char *buffer,
	int *buffer_i, Modifiers_t *mods)
{
	unsigned int count = 0, index = 0, bytes;
	char *bin_buffer, *cp_buff;
	unsigned long int num_l = 1;
	unsigned int num_s = 1;
	/* get num from list */
	if (mods->length->long_m)
		num_l = va_arg(arg_list, long int), bytes = 16;
	else
		num_s = va_arg(arg_list, int), bytes = 7;
	/* base check */
	if (!num_l || !num_s)
	{
		add_to_buffer('0', buffer, buffer_i);
		return (1);
	}
	/* maloc */
	bin_buffer = malloc((sizeof(char) * bytes) + 1);
	if (!bin_buffer)
		return (0);
	bin_buffer[bytes + 1] = '\0';
	if (mods->length->long_m)
		long_int_to_hex_buff(num_l, bin_buffer, bytes);
	else
		int_to_hex_buff(num_s, bin_buffer, bytes);
	/* push buffer ptr until we hit the fisrt non zero*/
	cp_buff = bin_buffer;
	while (*bin_buffer == '0')
		bin_buffer++;
	/* handling # flag */
	if ((mods->flags->pound) && bin_buffer[index])
	{
		add_to_buffer('0', buffer, buffer_i), index++;
		add_to_buffer('x', buffer, buffer_i), index++;
	}
	while (bin_buffer[count])
		add_to_buffer((bin_buffer[count]), buffer, buffer_i), count++;
	/* free buffer */
	free(cp_buff);
	return (count + index);
}

/**
 * handle_chex_format - adds a hex to the buffer capital letter!
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: ptr to index of buffer
 * @mods: ptr of modifiers
 * Return: count of chars added
 */
int handle_chex_format(va_list arg_list, char *buffer,
	int *buffer_i, Modifiers_t *mods)
{
	char *bin_buffer, *cp_buff;
	unsigned long int num_l = 1;
	unsigned int num_s = 1, count = 0, index = 0, bytes;
	/* get num from list */
	if (mods->length->long_m)
		num_l = va_arg(arg_list, long int), bytes = 16;
	else
		num_s = va_arg(arg_list, int), bytes = 7;
	if (!num_l || !num_s)
	{
		add_to_buffer('0', buffer, buffer_i);
		return (1);
	}
	/* maloc */
	bin_buffer = malloc((sizeof(char) * bytes) + 1);
	if (!bin_buffer)
		return (0);
	bin_buffer[bytes + 1] = '\0';
	if (mods->length->long_m)
		long_int_to_hex_buff(num_l, bin_buffer, bytes);
	else
		int_to_hex_buff(num_s, bin_buffer, bytes);
	/* push buffer ptr until we hit the fisrt non zero*/
	cp_buff = bin_buffer;
	while (*bin_buffer == '0')
		bin_buffer++;
	/* handling # flag */
	if ((mods->flags->pound) && bin_buffer[index])
	{
		add_to_buffer('0', buffer, buffer_i), index++;
		add_to_buffer('X', buffer, buffer_i), index++;
	}
	while (bin_buffer[count])
	{
		capitalize_alpha(&bin_buffer[count]);
		add_to_buffer((bin_buffer[count]), buffer, buffer_i), count++;
	}
	/* free buffer */
	free(cp_buff);
	return (count + index);
}
