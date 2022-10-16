#include "main.h"

/**
 * print_buf - prints buffer
 * @buffer: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buf(char *buffer, unsigned int nbuf)
{
	return (write(1, buffer, nbuf));
}
