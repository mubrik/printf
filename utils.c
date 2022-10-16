#include "main.h"

/**
 * is_format_spec - check if the ptr is a format specification, basic check
 * @src_ptr: src char ptr
 * @curr_spec: ptr to format specification
 * Return: 1 if it is, 0 if not
 */
int is_format_spec(const char *src_ptr, char *curr_spec)
{
	/* all spec "cdefgiosux%" */
	char *spec_arr = "cdsfi%";
	/* base check */
	if (src_ptr[0] != '%')
		return (0);

	/* iterate */
	while (*spec_arr != '\0')
	{
		/* checking the next value is a spec */
		if (*spec_arr == src_ptr[1])
		{
			/* set spec */
			*curr_spec = *spec_arr;
			return (1);
		}
		spec_arr++;
	}

	return (0);

}

/**
 * get_format_handler - gets the function used to print a specific format
 * @spec: the format spec
 * Return: 1 if it is, 0 if not
 */
int (*get_format_handler(char *spec))(va_list arg_list, char *, char, char *)
{
	int index;
	type_to_func_t type_list[] = {
		{"c", handle_char_format}, {"d", handle_float_format},
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
	if (buffer_i > BUFFER_SIZE)
	{
		/* flush/print out the buffer */
		print_buffer(buffer, BUFFER_SIZE);
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

