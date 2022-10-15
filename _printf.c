#include "main.h"

/**
 * is_format_spec: check if the ptr is a format specification
 * @src_ptr: src char ptr
 * Return: 1 if it is, 0 if not
 */
int is_format_spec(const char *src_ptr)
{
	/* all spec */
	char *spec = "cdefgiosux%";
	/* base check */
	if (*src_ptr != '%')
		return (0);

	/* iterate */
	while (*spec != '\0')
	{
		/* checking the next value */
		if (*spec == *(src_ptr + 1))
		{
			printf("This is a format spec: %c%c \n", *src_ptr, *(src_ptr + 1));
			return (1);
		}
		spec++;
	}

	return (0);

}

/**
 * _printf: does printf stuff
 * @format: stirng format of string
 */
int _printf(const char *format, ...)
{
	int count;
	char *format_ptr;
	/* base check */
	if (format == NULL)
		return (-1); /* invalid */
	format_ptr = (char *) format; /* copying ptr to elim const */
	count = 0;
	/* main while loop to iterate over str ptr */
	while (*format_ptr != '\0')
	{
		/* checking for format spec */
		if (is_format_spec(format_ptr))
			count++; /* incrementing to test works fine */
		_putchar(*format_ptr); /* directly printing for now! basic */
		format_ptr++; /* pushptr */
	}

	printf("Total format count: %d\n", count);

	return (0);
}