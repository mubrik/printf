#ifndef MAIN_H
#define MAIN_H
#define PRINT_BUFF_SIZE 1024
#define FLAG_BUFF_SIZE 5
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);
int print_buffer(char *buffer, int byte_count);
int is_format_spec(const char *src_ptr, char *curr_spec, char *flags);
int add_to_buffer(char str, char *buffer, int buffer_i);
int add_int_buff(int num, char *buffer, char buffer_i);
int cp_to_flag_buffer(const char *src_ptr, int byte_c, char *flags_buffer);
int handle_char_format(va_list arg_list, char *buffer, char buffer_i, char *flags);
int handle_str_format(va_list arg_list, char *buffer, char buffer_i, char *flags);
int handle_int_format(va_list arg_list, char *buffer, char buffer_i, char *flags);
int handle_float_format(va_list arg_list, char *buffer, char buffer_i, char *flags);
int handle_percent_format(va_list arg_list, char *buffer, char buffer_i, char *flags);
int (*get_format_handler(char *spec))(va_list arg_list, char *, char , char *);
int print_buffer(char *buffer, int byte_count);
int _printf(const char *format, ...);
/**
 * struct type_to_func - this holds a char ptr and func ptr
 * @op_type: operation type/name
 * @op_func: ptr to func of operation
 */
typedef struct type_to_func
{
	char *op_type;
	int (*op_func)(va_list arg_list, char *buffer, char buffer_i, char *flags);
} type_to_func_t;

#endif /* MAIN_H */
