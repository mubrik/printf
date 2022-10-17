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
	if (c == ' ' || c == '+' || c == '-')
		return (1);
	if (_is_number(c))
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
	/* all spec "cdefgiosux%" */
	char *spec_arr = "cdsfi%";

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
 * _set_spec_format - sets the character to the spec buffer
 * @c: character
 * @s_buff: ptr to format specification buffer
 * Return: 1 if true, 0 else
 */
int _set_spec_format(char c, char *s_buff)
{
	if (c == '\0')
	{
		s_buff[0] = '\0';
		return (1);
	}
	/* set */
	s_buff[0] = c, s_buff[1] = '\0';
	return (1);
}

/**
 * is_format_spec - check if the ptr is a format specification, basic check
 * @src_ptr: src char ptr
 * @s_buff: ptr to format specification buffer
 * @flags: ptr to flags buffer
 * Return: 1 if it is, 0 if not
 */
int is_format_spec(const char *src_ptr, char *s_buff, char *flags)
{
	/* base check */
	if (src_ptr[0] != '%')
		return (0);
	/* checking the immediate next (1) value is a spec directly */
	if (_is_format_spec_char(src_ptr[1]))
	{
		_set_spec_format(src_ptr[1], s_buff);
		return (1);
	}
	/* checking (2) value is a spec, (1) must be a flag */
	if (_is_format_spec_char(src_ptr[2]) &&
		_is_flag_character(src_ptr[1]))
	{
		/* set flag and set spec */
		cp_to_flag_buffer(&src_ptr[1], 1, flags);
		_set_spec_format(src_ptr[2], s_buff);
		return (1);
	}
	/* checking (3) value is a spec, (2) must be a number/flag and (1) a flag */
	if (_is_format_spec_char(src_ptr[3]) &&
		_is_flag_character(src_ptr[2]) && _is_flag_character(src_ptr[1]))
	{
		/* set flag and set spec  */
		_set_spec_format(src_ptr[3], s_buff);
		cp_to_flag_buffer(&src_ptr[1], 2, flags);
		return (1);
	}
	/* checking (4) value is a spec, (3-1) must be a number/flag */
	if (_is_format_spec_char(src_ptr[4]) &&
		_is_flag_character(src_ptr[3]) && _is_flag_character(src_ptr[2]) &&
		_is_flag_character(src_ptr[1]))
	{
		/* set flag and set spec  */
		_set_spec_format(src_ptr[4], s_buff);
		cp_to_flag_buffer(&src_ptr[1], 3, flags);
		return (1);
	}
	/* not a spec, empty string  */
	_set_spec_format('\0', s_buff);
	return (0);
}
