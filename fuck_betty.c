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

/**
  * _strlen - returns the length of a string.
	* @src_ptr: pointer of char
	* Return: int length
	*/
unsigned int _strlen(char *src_ptr)
{
	/* checking if the current value of pointer not null */
	if (*src_ptr != 0)
	{
		/* move the pointer foward and call the function again adding 1! */
		src_ptr++;
		return (1 + _strlen(src_ptr));
	}

	return (0);
}

/**
  * add_rep_buff - adds a char to buff repeatedly
	* @c: char
	* @buff: pointer of buffer
	* @buf_i: pointer of buf index
	* @n: num of bytes
	* Return: int length
	*/
int add_rep_buff(char c, char *buff, int *buf_i, unsigned int n)
{
	unsigned int i = 0, count = 0;

	for (; i < n; i++)
	{
		add_to_buffer(c, buff, buf_i), count++;
	}
	return (count);
}
