#include "main.h"


/**
 * _allocate_buff_mem - reducing lines in main func,
 * moving malloc and check here
 * @p_buff: ptr to ptr of main print buffer
 * @f_buff: ptr to ptr ofmain flag buffer
 * @s_buff: ptr to ptr of format specification buffer
 * Return: 0 on success, 1 on failure
 */
int _allocate_buff_mem(char **p_buff, char **f_buff, char **s_buff)
{
	/* allocate buffer space */
	*p_buff = malloc(sizeof(char) * PRINT_BUFF_SIZE);
	*f_buff = malloc(sizeof(char) * FLAG_BUFF_SIZE);
	*s_buff = malloc(sizeof(char) + 1);
	/* check */
	if (!(*s_buff) || !(*p_buff) || !(*f_buff))
	{
		return (1);
	}
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
	int count = 0, buffer_i = 0, index = 0;
	char *pr_buff = NULL, *flags_buff = NULL, *spec_buff = NULL;
	int (*format_buff_handler)(va_list arg_list, char *, char, char *);
	va_list arg_list;
	/* base check */
	if (format == NULL)
		return (-1);
	/* allocate buffer memory */
	if (_allocate_buff_mem(&pr_buff, &flags_buff, &spec_buff))
		return (-1);
	va_start(arg_list, format); /* init varaidic args */
	/* main loop */
	for (index = 0; format[index] != '\0'; index++)
	{
		if (is_format_spec(&format[index], spec_buff, flags_buff))
		{
			format_buff_handler = get_format_handler(spec_buff); /* get handler */
			if (format_buff_handler == NULL) /* check */
			{
				count++;
				continue;
			}
			count += format_buff_handler(arg_list, pr_buff, buffer_i, flags_buff);
			index++;
		}
		else
		{
			add_to_buffer(format[index], pr_buff, buffer_i), count++;
		}
		buffer_i = count; /* refresh buffer, but within limits */
		while (buffer_i > PRINT_BUFF_SIZE)
			buffer_i -= PRINT_BUFF_SIZE;
	}
	print_buffer(pr_buff, buffer_i);
	_free_buff_mem(3, pr_buff, flags_buff, spec_buff), va_end(arg_list);
	return (count);
}
