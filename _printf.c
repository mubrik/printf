#include "main.h"

/**
 * _printf - does printf stuff
 * @format: stirng format of string
 * Return: number of bytes printed or -1 for fail
 */
int _printf(const char *format, ...)
{
	int count = 0, buffer_i = 0, index = 0;
	int (*format_buff_handler)(va_list arg_list, char *, char, char *);
	char *buffer, *flags, *curr_spec;
	va_list arg_list;
	/* base check */
	if (format == NULL)
		return (-1);
	/* allocate buffer space */
	buffer = malloc(sizeof(char) * BUFFER_SIZE), flags = malloc(sizeof(char) * 4);
	curr_spec = malloc(sizeof(char) + 1);
	if (buffer == NULL)
		return (-1);
	va_start(arg_list, format); /* init varaidic args */
	/* main loop */
	for (index = 0; format[index] != '\0'; index++)
	{
		if (is_format_spec(&format[index], curr_spec))
		{
			/* get handler */
			format_buff_handler = get_format_handler(curr_spec);
			/* check */
			if (format_buff_handler == NULL)
			{
				printf("yeah null"), count++;
				continue;
			}
			count += format_buff_handler(arg_list, buffer, buffer_i, flags), index++;
		}
		else
		{
			/* add directly to buff */
			add_to_buffer(format[index], buffer, buffer_i), count++;
		}
		buffer_i = count; /* refresh buffer, but within limits */
		while (buffer_i > BUFFER_SIZE)
			buffer_i -= BUFFER_SIZE;
	}
	/* PRINT BUFFER */
	print_buffer(buffer, buffer_i), free(buffer), va_end(arg_list);
	return (count);
}
