#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _printstr(va_list arg_list, int *count);
int _printchar(va_list arg_list, int *count);
void _printint_rec(int num, int *count);
int _printnumber(va_list arg_list, int *count);
int _printfloat(va_list arg_list, int *count);
/**
 * type_to_func - this holds a char ptr and func ptr
 * @op_type: operation type/name
 * @op_func: ptr to func of operation
 */
struct type_to_func
{
	char *op_type;
	int (*op_func)(va_list arg_list, int *count);
};

#endif /* MAIN_H */
