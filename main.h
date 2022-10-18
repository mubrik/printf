#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/* buffer size of printf */
#define PRINT_BUFF_SIZE 1024

/**
 * struct Format_Flags - holds the array of flags
 * @plus: 1 if flag is set, 0 otherwise
 * @minus: 1 if flag is set, 0 otherwise
 * @space: 1 if flag is set, 0 otherwise
 * @number: the number if flag is set, t0 otherwise
 * Description: Betty forced me to use a typedef here, the array of flags
 */
typedef struct Format_flag
{
	unsigned int plus;
	unsigned int minus;
	unsigned int space;
	unsigned int pound;
	unsigned int zero;
} Format_flag_t;

/* This is a generic typedef for all the functions that handles a format spec */
typedef int Format_handler(va_list arg_list, char *buffer, int *buffer_i, Format_flag_t *flags);

/* functions that handle a spec format */
Format_handler handle_char_format;
Format_handler handle_str_format;
Format_handler handle_int_format;
Format_handler handle_uint_format;
Format_handler handle_float_format;
Format_handler handle_percent_format;
Format_handler handle_bin_format;
Format_handler handle_oct_format;
Format_handler handle_shex_format;
Format_handler handle_chex_format;
Format_handler *get_format_handler(char *spec); /* ptr to func ptr format_handler */

/**
 * struct format_to_func - this holds a char ptr and func ptr
 * @format_type: format type/name
 * @format_func: ptr to func of operation
 * Description: Betty forced me to use a typedef here
 */
typedef struct format_to_func
{
	char *format_type;
	Format_handler (*format_func);
} format_to_func_t;
/* major func, checs if string is format spec */
int is_format_spec(const char *src_ptr, char *s_buff, Format_flag_t *flags);
/* buffer functions */
int print_buffer(char *buffer, int byte_count);
int add_to_buffer(char str, char *buffer, int *buffer_i);
int add_int_buff(unsigned int, char *buffer, int *buffer_i);
int free_buff_mem(int num, ...);
int allocate_buff_mem(char **pr_buff, int **pr_buff_index,
	char **format_spec_buff, Format_flag_t **format_flags);
/* utility functions */
int is_number(char c);
void capitalize_alpha(char *src_ptr);
/* flag functions */
int is_flag_set(char flag, Format_flag_t *format_flag);
int is_flag_character(char c);
int set_format_flag(char flag, Format_flag_t *format_flag);
Format_flag_t *reset_format_flag(Format_flag_t *format_flag); /* return ptr to flag */
/* main */
int _printf(const char *format, ...);

#endif /* MAIN_H */
