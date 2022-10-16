#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int _printchar(va_list args, char *buffer, unsigned int buffer_index);
int _printstr(va_list args, char *buffer, unsigned int buffer_index);
int _printint(va_list args, char *buffer, unsigned int buffer_index);


/**
 * type_to_func - this holds a char ptr and func ptr
 * @op_type: operation type/name
 * @op_func: ptr to func of operation
 */
typedef struct type_to_func
{
	char *op_type;
	int (*op_func)(va_list, char *, unsigned  int);
} print_t;

int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int handle_buf(char *buffer, char c, unsigned int buffer_index);
int print_buf(char *buffer, unsigned int nbuf);

#endif /* MAIN_H */
