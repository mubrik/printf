#include "main.h"
/**
 * get_print_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_t pr[] = {
		{"c", _printchar}, {"s", _printstr},
		{"i", _printint}, {"d", _printint},
		{"#i", _printint}, {"#d", _printint},
		{"%", print_prg}, {"l", print_prg},
		{"h", print_prg}, {" %", print_prg},
		{NULL, NULL},
	};

	int i;
	int j;
	int first_index;

	i = 0;
	j = 0;

	first_index = index;
	while (pr[i].op_type)
	{
		if (s[index] == pr[i].op_type[j])
		{
			if (pr[i].op_type[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pr[i].op_func);
}
