#include "main.h"

/**
 * handle_buf - concatenates the buffer characters
 * @buffer: buffer pointer
 * @c: charcter to concatenate
 * @buffer_index: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int handle_buf(char *buffer, char c, unsigned int buffer_index)
{
	if (buffer_index == 1024)
	{
		print_buf(buffer, buffer_index);
		buffer_index = 0;
	}
	buffer[buffer_index] = c;
	buffer_index++;
	return (buffer_index);
}
