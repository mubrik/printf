#include "main.h"

/**
 * _printf - does printf stuff
 * @format: stirng format of string
 * Return: number of bytes printed or -1 for fail
 */
int _printf(const char *format, ...)
{
	int count = 0, index = 0, is_form_spec, *buffer_i = NULL;
	char *pr_buff = NULL, *form_spec_buff = NULL;
	Format_flag_t *format_flags = NULL;
	Format_handler *format_handler;
	va_list arg_list;
	/* base check */
	if (format == NULL)
		return (-1);
	if (allocate_buff_mem(&pr_buff, &buffer_i, &form_spec_buff, &format_flags))
		return (-1); /* allocate buffer memory */
	va_start(arg_list, format); /* init varaidic args */
	/* main loop */
	for (index = 0; format[index]; index++)
	{
		is_form_spec = is_format_spec(&format[index], form_spec_buff, format_flags);
		if (is_form_spec < 0)
		{/* if an error, break loop and print buffer */
			count = is_form_spec;
			break;
		}
		else if (is_form_spec > 0)
		{
			format_handler = get_format_handler(form_spec_buff); /* get handler */
			if (!format_handler) /* check */
			{
				count++;
				continue;
			}
			count += format_handler(arg_list, pr_buff, buffer_i, format_flags);
			reset_format_flag(format_flags), index += is_form_spec;/* reset flags */
		}
		else
			add_to_buffer(format[index], pr_buff, buffer_i), count++;
	}
	print_buffer(pr_buff, *buffer_i), va_end(arg_list);
	free_buff_mem(4, pr_buff, format_flags, form_spec_buff, buffer_i);
	return (count);
}
