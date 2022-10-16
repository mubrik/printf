#include "main.h"

/**
 * _printchar: prints a single character.
 * @args: input char
 * @buffer: buffer pointer
 * @buffer_index: index of buffer pointer
 * Return: 1 on success
 */
int _printchar(va_list args, char *buffer, unsigned int buffer_index)
{
	char c;
	/* get arg from list */
	c = va_arg(args, int);

	handle_buf(buffer, c, buffer_index);

	return (1);
}
