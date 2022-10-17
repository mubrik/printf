#include "main.h"

/**
 * get_format_handler - gets the function used to print a specific format
 * @spec: the format spec
 * Return: 1 if it is, 0 if not
 */
int (*get_format_handler(char *spec))(va_list, char *, char, Format_flag_t *)
{
	int index;
	type_to_func_t type_list[] = {
		{"c", handle_char_format}, {"d", handle_int_format},
		{"s", handle_str_format}, {"f", handle_float_format},
		{"i", handle_int_format}, {"%", handle_percent_format}
	};
	/* iterate */
	for (index = 0; index < (int) sizeof(type_list); index++)
	{
		/* if spec matches */
		if (*(type_list[index].op_type) == *spec)
		{
			return (type_list[index].op_func);
		}
	}

	return (NULL);
}

/**
 * add_to_buffer - adds a charatcter to index of a buffer
 * @str: the character
 * @buffer: the ptr to a buffer
 * @buffer_i: index of buffer
 * Return: the next available index int
 */
int add_to_buffer(char str, char *buffer, int buffer_i)
{
	if (buffer_i > PRINT_BUFF_SIZE)
	{
		/* flush/print out the buffer */
		print_buffer(buffer, PRINT_BUFF_SIZE);
		/* set index to start */
		buffer_i = 0;
	}
	/* add chr to buffer and incr index */
	buffer[buffer_i] = str, buffer_i++;
	return (buffer_i);
}

/**
 * print_buffer - writes bytes of a buffer to stdout
 * @buffer: the ptr to a buffer
 * @byte_count: number of byte to write
 * Return: the next available index int
 */
int print_buffer(char *buffer, int byte_count)
{
	return (write(1, buffer, byte_count));
}

/**
 * cp_to_flag_buffer - cp bytes specified to a flag buffer
 * @src_ptr: the character
 * @byte_c: num of byte to copy
 * @flags_buffer: the ptr to a buffer
 * Return: count of bytes added
 */
int cp_to_flag_buffer(const char *src_ptr, int byte_c, char *flags_buffer)
{
	int count = 0;
	/* dont exceed buffer */
	if (byte_c > (FLAG_BUFF_SIZE - 1))
		return (0);
	/* copy from src to buffer */
	for (; count < byte_c; count++)
	{
		flags_buffer[count] = src_ptr[count];
	}
	/* add null byte */
	flags_buffer[count + 1] = '\0';

	return (count);
}
