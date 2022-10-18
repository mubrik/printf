#include "main.h"

/**
 * handle_percent_format - adds a % to the buffer
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: index of buffer
 * @flags: flags to modify behaviour
 * Return: 1
 */
int handle_percent_format(__attribute__((unused)) va_list arg_list,
	char *buffer, int *buffer_i, __attribute__((unused)) Format_flag_t *flags)
{
	/* beffer */
	add_to_buffer('%', buffer, buffer_i);
	return (1);
}
