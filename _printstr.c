#include "main.h"

/**
 * handle_str_format - adds a string of char to the buffer
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: index of buffer
 * @flags: flags to modify behaviour
 * Return: number of characters added
 */
int handle_str_format(va_list arg_list, char *buffer,
	int *buffer_i, __attribute__((unused)) Format_flag_t *flags)
{
	char *string_ptr;
	char *null_str = "(null)"; /* print this if NULL */
	int count = 0;

	/* get argument from list */
	string_ptr = va_arg(arg_list, char *);
	/* null check */
	if (!string_ptr)
	{
		/* print null */
		while (null_str[count])
		{
			add_to_buffer(null_str[count], buffer, buffer_i), count++;
		}
		return (count);
	}

	while (string_ptr[count])
		add_to_buffer(string_ptr[count], buffer, buffer_i), count++;

	return (count);
}
