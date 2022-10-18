#include "main.h"

/**
 * _is_format_spec_char - checks if char is a format spec char "cdefgiosux%"
 * @c: character
 * Return: 1 if true, 0 else
 */
int _is_format_spec_char(char c)
{
	/* all spec "cdefgiosux%" custom: "b" */
	char *spec_arr = "cdsfiouxXb%";

	/* iterate */
	while (*spec_arr != '\0')
	{
		if (*spec_arr == c)
		{
			return (1);
		}
		spec_arr++;
	}
	return (0);
}

/**
 * _set_spec_format - sets the character to the specification buffer
 * @c: character
 * @form_spec_buff: ptr to format specification buffer
 * Return: 1 if true, 0 else
 */
int _set_spec_format(char c, char *form_spec_buff)
{
	if (c == '\0')
	{
		form_spec_buff[0] = '\0';
		return (1);
	}
	/* set */
	form_spec_buff[0] = c, form_spec_buff[1] = '\0';
	return (1);
}

/**
 * is_format_spec - check if the ptr is a format specification, basic check
 * @src_ptr: src char ptr
 * @form_spec_buff: ptr to format specification buffer
 * @flags: ptr to flags buffer
 * Return: 1 if it is, 0 if not
 */
int is_format_spec(const char *src_ptr, char *form_spec_buff,
	Format_flag_t *flags)
{
	int count;

	/* base check */
	if (src_ptr[0] != '%')
		return (0);
		/* checking the immediate next (1) value is a null byte */
	if (src_ptr[1] == '\0')
		return (-1); /* invalid */
	/* checking the immediate next(1) value is a spec directly, no flags: 0(n) */
	if (_is_format_spec_char(src_ptr[1]))
	{
		_set_spec_format(src_ptr[1], form_spec_buff);
		return (1);
	}
	count = 1;
	/* iterate until we find our format spec or nullbyt, assume every flags */
	/* checking only flags for now */
	for (; src_ptr[count]; count++)
	{
		/* checking if a format spec */
		if (_is_format_spec_char(src_ptr[count]))
		{
			_set_spec_format(src_ptr[count], form_spec_buff);
			return (count);
		}
		/* checking if its a flag */
		else if (is_flag_character(src_ptr[count]))
		{/* if not set, set it */
			if (!is_flag_set(src_ptr[count], flags))
				set_format_flag(src_ptr[count], flags);
			continue;
		}
		/* not a format spec or flag */
		else
		{
			return (count - 1);
		}
	}
	/* string did not end with a spec character */
	return (0);
}

/**
 * get_format_handler - gets the function used to print a specific format
 * @format_spec: the format spec
 * Return: 1 if it is, 0 if not
 */
Format_handler *get_format_handler(char *format_spec)
{
	int index;
	format_to_func_t type_list[] = {
		{"c", handle_char_format}, {"d", handle_int_format},
		{"s", handle_str_format}, {"f", handle_float_format},
		{"i", handle_int_format}, {"%", handle_percent_format},
		{"b", handle_bin_format}, {"o", handle_oct_format},
		{"x", handle_shex_format}, {"X", handle_chex_format},
		{"u", handle_uint_format}
	};
	/* iterate */
	for (index = 0; index < (int) sizeof(format_to_func_t); index++)
	{
		/* if spec matches */
		if (*(type_list[index].format_type) == *format_spec)
		{
			return (type_list[index].format_func);
		}
	}

	return (NULL);
}
