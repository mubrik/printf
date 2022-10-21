#include "main.h"

/**
 * islmod - checks len modify
 * @c: ptr to strin
 * @long_l: len modifier
 * @short_s: ptr to cou
 * Return: int
 */
int islmod(char c, int long_l, int short_s)
{
	if ((c == 'l' || c == 'h') && !(long_l) && !(short_s))
		return (1);
	return (0);
}

/**
 * init_spec_chk - checks len modify
 * @str: ptr to strin
 * Return: int
 */
int init_spec_chk(const char *str)
{
	if (str[0] != '%')
		return (0);
	if (str[1] == '\0')
		return (-1);
	return (1);
}
