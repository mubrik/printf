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
	char *null_str = "(null)"; /* print this if NULL */
	int count = 0;

	/* get argument from list */
	string_ptr = va_arg(arg_list, char *);
	/* need to check if arg doesnt exist, using this for now */
	if (null_str[0] == '\0')
		return (count);
	/* null check */
	if (!string_ptr)
	{
		/* print null */
		while (null_str[count] != '\0')
		{
			add_to_buffer(null_str[count], buffer, (buffer_i + count)), count++;
		}
		return (count);
	}

	while (*string_ptr != '\0')
	{
		/* add to buffer */
		add_to_buffer(*string_ptr, buffer, (buffer_i + count)), count++;
		/* incr count and src ptr*/
		string_ptr++;
	}

	return (count);
}
