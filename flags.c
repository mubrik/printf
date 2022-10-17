#include "main.h"

/**
 * create_format_flag - creates a flag struct and return a ptr
 * Return: ptr to format flag
 */
Format_flag_t *make_format_flag_struct()
{
	Format_flag_t *format_flag;
	/* create in heap */
	format_flag = malloc(sizeof(Format_flag_t));
	if (!format_flag)
		return (NULL);
	/* set flasg/attribs */
	format_flag->minus = 0, format_flag->zero = 0;
	format_flag->plus = 0, format_flag->space = 0, format_flag->pound = 0;
	return (format_flag);
}

/**
 * is_flag_set - checks if a flag is set
 * Return: 1 if set, 0 if not
 * @flag: flag character or 'n' for number
 * @format_flag: the format flag struct ptr
 */
int is_flag_set(char flag, Format_flag_t *format_flag)
{
	if (!format_flag)
		return (0);

	switch (flag)
	{
	case '+':
		return (format_flag->plus);
		break;
	case '-':
		return (format_flag->minus);
		break;
	case ' ':
		return (format_flag->minus);
		break;
	case '#':
		return (format_flag->minus);
		break;
	case '0':
		return (format_flag->zero);
		break;

	default:
		return (1);
		break;
	}
}

/**
 * set_format_flag - sets a format flag
 * Return: 1 if set, 0 if not
 * @flag: flag character or 'n' for number
 * @format_flag: the format flag struct ptr
 */
int set_format_flag(char flag, Format_flag_t *format_flag)
{
	if (!format_flag)
		return (0);

	switch (flag)
	{
	case '+':
		format_flag->plus = 1;
		return (1);
		break;
	case '-':
		format_flag->minus = 1;
		return (1);
		break;
	case ' ':
		format_flag->space = 1;
		return (1);
		break;
	case '#':
		format_flag->pound = 1;
		return (1);
		break;
	case '0':
		format_flag->zero = 1;
		return (1);
		break;

	default:
		return (1);
		break;
	}
}

/**
 * reset_format_flag - resets all flags to 0
 * @format_flag: the format flag struct ptr
 * Return: ptr to format flag
 */
Format_flag_t *reset_format_flag(Format_flag_t *format_flag)
{
	if (!format_flag)
		return (NULL);
	/* set flasg/attribs */
	format_flag->minus = 0, format_flag->zero = 0;
	format_flag->plus = 0, format_flag->space = 0, format_flag->pound = 0;
	return (format_flag);
}
