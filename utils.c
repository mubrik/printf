#include "main.h"

/**
 * capitalize_alpha - capitalize an alphabet char
 * @src_ptr: the ptr to char character
 * Return: void
 */
void capitalize_alpha(char *src_ptr)
{
	if (!src_ptr)
		return;

	if (*src_ptr >= 'a' && *src_ptr <= 'z')
		*src_ptr = *src_ptr - 32;
}

/**
 * is_number - checks if char is a number
 * @c: character
 * Return: 1 if true, 0 else
 */
int is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
