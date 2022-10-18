#ifndef MAIN_H
#define MAIN_H
#define PRINT_BUFF_SIZE 1024
#define FLAG_BUFF_SIZE 5
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * struct Format_Flags - holds the flags for a specific format spec
 * @plus: 1 if flag is set, 0 otherwise
 * @minus: 1 if flag is set, 0 otherwise
 * @space: 1 if flag is set, 0 otherwise
 * @number: the number if flag is set, t0 otherwise
 * Description: Betty forced me to use a typedef here
 */
typedef struct Format_flag
{
	unsigned int plus;
	unsigned int minus;
	unsigned int space;
	unsigned int pound;
	unsigned int zero;
} Format_flag_t;

/**
 * struct type_to_func - this holds a char ptr and func ptr
 * @op_type: operation type/name
 * @op_func: ptr to func of operation
 * Description: Betty forced me to use a typedef here
 */
typedef struct type_to_func
{
	char *op_type;
	int (*op_func)(va_list arg_list, char *buffer, int buffer_i, Format_flag_t *flags);
} type_to_func_t;

int _putchar(char c);
int print_buffer(char *buffer, int byte_count);
int is_format_spec(const char *src_ptr, char *s_buff, Format_flag_t *flags);
int add_to_buffer(char str, char *buffer, int buffer_i);
int add_int_buff(unsigned int, char *buffer, int buffer_i);
/* int cp_to_flag_buffer(const char *src_ptr, int byte_c, Format_flag_t *flags_buffer); */
int handle_char_format(va_list arg_list, char *buffer, int buffer_i, Format_flag_t *flags);
int handle_str_format(va_list arg_list, char *buffer, int buffer_i, Format_flag_t *flags);
int handle_int_format(va_list arg_list, char *buffer, int buffer_i, Format_flag_t *flags);
int handle_float_format(va_list arg_list, char *buffer, int buffer_i, Format_flag_t *flags);
int handle_percent_format(va_list arg_list, char *buffer, int buffer_i, Format_flag_t *flags);
int handle_bin_format(va_list arg_list, char *buffer, int buffer_i, __attribute__((unused)) Format_flag_t *flags);
int (*get_format_handler(char *spec))(va_list arg_list, char *buff, int buffer_i , Format_flag_t *flags);
int print_buffer(char *buffer, int byte_count);
Format_flag_t *make_format_flag_struct();
int is_flag_set(char flag, Format_flag_t *format_flag);
int set_format_flag(char flag, Format_flag_t *format_flag);
int set_format_flag_num(int number, Format_flag_t *format_flag);
Format_flag_t *reset_format_flag(Format_flag_t *format_flag);
int _printf(const char *format, ...);

#endif /* MAIN_H */
