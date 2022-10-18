#include "main.h"

/**
 * _is_number - checks if char is a number
 * @c: character
 * Return: 1 if true, 0 else
 */
int _is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * _is_flag_character - checks if char is a flag type ( +-0)
 * @c: character
 * Return: 1 if true, 0 else
 */
int _is_flag_character(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0')
		return (1);
	return (0);
}

/**
 * _is_format_spec_char - checks if char is a format spec char "cdefgiosux%"
 * @c: character
 * Return: 1 if true, 0 else
 */
int _is_format_spec_char(char c)
{
	/* all spec "cdefgiosux%" custom: "b" */
	char *spec_arr = "cdsfi%b";

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
		else if (_is_flag_character(src_ptr[count]))
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
