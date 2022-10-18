#include "main.h"


/**
 * _allocate_buff_mem - reducing lines in main func,
 * moving malloc and check here
 * @pr_buff: ptr to ptr of main print buffer
 * @pr_buff_index: ptr to ptr of INDEX of print buffer
 * @format_spec_buff: ptr to ptr of format specification buffer
 * @format_flags: ptr to ptr of main format flag struct
 * Return: 0 on success, 1 on failure
 */
int _allocate_buff_mem(char **pr_buff, int **pr_buff_index,
	char **format_spec_buff, Format_flag_t **format_flags)
{
	/* allocate buffer space */
	*pr_buff = malloc(sizeof(char) * PRINT_BUFF_SIZE);
	*pr_buff_index = malloc(sizeof(int));
	*format_spec_buff = malloc(sizeof(char) + 1);
	*format_flags = malloc(sizeof(Format_flag_t));
	/* check */
	if (!(*format_spec_buff) || !(*pr_buff) ||
		!(*format_flags) || !(*pr_buff_index))
	{
		return (1);
	}
	/* set flags/attribs */
	(*format_flags)->minus = 0, (*format_flags)->zero = 0;
	(*format_flags)->plus = 0, (*format_flags)->space = 0;
	(*format_flags)->pound = 0;
	**pr_buff_index = 0;

	return (0);
}

/**
 * _free_buff_mem - frees up buffer in args
 * @num: num of args
 * Return: 0 on success, 1 on failure
 */
int _free_buff_mem(int num, ...)
{
	int index;
	va_list arg_list;

	if (num <= 0)
		return (1);
	/* init variadic */
	va_start(arg_list, num);
	/* iterate and free pointers */
	for (index = 0; index < num; index++)
	{
		free(va_arg(arg_list, char *)); /* be free arguments */
	}
	va_end(arg_list);
	return (0);
}

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
	Format_handler format_handler;
	va_list arg_list;
	/* base check */
	if (format == NULL)
		return (-1);
	if (_allocate_buff_mem(&pr_buff, &buffer_i, &form_spec_buff, &format_flags))
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
	_free_buff_mem(4, pr_buff, format_flags, form_spec_buff, buffer_i);
	return (count);
}
