#include "main.h"

/**
 * _printstr - writes the string to stdout
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_index: index for buffer pointer
 * Return: On success 1.
 */
int _printstr(va_list args, char *buffer, unsigned int buffer_index)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_index = handle_buf(buffer, nill[i], buffer_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
		buffer_index = handle_buf(buffer, str[i], buffer_index);
	return (i);
}
