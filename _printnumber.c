#include "main.h"

/**
 * add_int_buff - recursive add number to buffer
 * @num: integer to add
 * @buffer: the ptr to a buffer
 * @buffer_i: index of buffer
 * Description: works recursively, wont print until last digit which becomes
 * Return: count of bytes added to buffer
 */
int add_int_buff(int num, char *buffer, char buffer_i)
{
	if (num > 9)
	{
		/* divide by 10 */
		return (1 + add_int_buff((num / 10), buffer, (buffer_i + 1)));
	}
	/* print reminder, which wil be the last number */
	add_to_buffer(((num % 10) + '0'), buffer, buffer_i);
	return (1);
}

/**
 * handle_int_format - adds numbers of type long int to the buffer
 * @arg_list: args list
 * @buffer: the ptr to a buffer
 * @buffer_i: index of buffer
 * @flags: flags to modify behaviour
 * Return: number of integers added
 */
int handle_int_format(va_list arg_list, char *buffer,
	char buffer_i, __attribute__((unused)) Format_flag_t *flags)
{
	int number, count = 0;

	/* get argument from list */
	number = va_arg(arg_list, int);
	/* neg number */
	if (number < 0)
	{
		buffer_i = add_to_buffer('-', buffer, buffer_i), count++;
		number *= -1; /* make absolute */
	}
	/* work recursively */
	count += add_int_buff(number, buffer, buffer_i);

	return (count);

}
