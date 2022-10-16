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
	char buffer_i, __attribute__((unused)) char *flags)
{
	char *string_ptr;
	char *null_str = "(nil)";
	int count = 0;

	/* get argument from list */
	string_ptr = va_arg(arg_list, char *);
	/* null check */
	if (string_ptr == NULL)
	{
		/* print nil */
		while (*null_str != '\0')
		{
			add_to_buffer(*null_str, buffer, (buffer_i + count));
		}
		return (count);
	}

	while (*string_ptr != '\0')
	{
		/* add to buffer */
		add_to_buffer(*string_ptr, buffer, (buffer_i + count));
		/* incr count and src ptr*/
		count++;
		string_ptr++;
	}

	return (count);
}
