#include "main.h"

/**
 * is_format_spec: check if the ptr is a format specification, basic check
 * @src_ptr: src char ptr
 * @curr_spec: ptr to format specification
 * Return: 1 if it is, 0 if not
 */
int is_format_spec(const char *src_ptr, char *curr_spec)
{
	/* all spec "cdefgiosux%" */
	char *spec_arr = "cs%";
	/* base check */
	if (*src_ptr != '%')
		return (0);

	/* iterate */
	while (*spec_arr != '\0')
	{
		/* checking the next value is a spec */
		if (*spec_arr == *(src_ptr + 1))
		{
			/* set spec */
			*curr_spec = *spec_arr;
			return (1);
		}
		spec_arr++;
	}

	return (0);

}

/**
 * get_format_printer: gets the function used to print a specific format
 * @spec: the format spec
 * Return: 1 if it is, 0 if not
 */
int (*get_format_printer(char *spec))(va_list arg_list, int *count)
{
	int index;
	/* struct list of format spec to functions */
	struct type_to_func type_list[] = {
		{"c", _printchar},
		{"s", _printstr},
	};
	/* iterate */
	for (index = 0; index < 2; index++)
	{
		/* if spec matches */
		if (*(type_list[index].op_type) == *spec)
		{
			return (type_list[index].op_func);
		}
	}

	return (NULL);
}

/**
 * _printf: does printf stuff
 * @format: stirng format of string
 */
int _printf(const char *format, ...)
{
	int *count, (*print_func)(va_list, int *);
	char *format_ptr, *curr_spec;
	va_list arg_list;
	/* base check */
	if (format == NULL)
		return (-1);
	format_ptr = (char *) format; /* copying & casting ptr to elim const */

	/* alloc space for char spec */
	curr_spec = malloc(sizeof(char));
	count = malloc(sizeof(int));
	/* check */
	if (curr_spec == NULL || count == NULL)
		return (-1);

	*count = 0;
	/* init varaidic args */
	va_start(arg_list, format);
	/* main while loop to iterate over str ptr */
	while (*format_ptr != '\0')
	{
		/* check and set format spec */
		if (is_format_spec(format_ptr, curr_spec))
		{
			if (*curr_spec == '%')
			{
				/* percent, print single % */
				_putchar('%');
				++*count;
				/* dumb pushhing for now!, by 2 */
				format_ptr = format_ptr + 2;
				continue;
			}
			/* not % needs proper handle, get func */
			print_func = get_format_printer(curr_spec);
			/* check */
			if (print_func == NULL)
			{
				format_ptr++; /* should not be, but incaase for now */
				continue;
			}
			/* print & incr count */
			print_func(arg_list, count);
			/* dumb pushhing for now!, by 2 */
			format_ptr = format_ptr + 2;
			continue;
		}

		_putchar(*format_ptr); /* directly printing for now! basic */
		++*count;
		format_ptr++; /* pushptr */
	}


	return (*count);
}
