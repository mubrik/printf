#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
int _printf(const char *format, ...);
/**
 * type_to_func - this holds a char ptr and func ptr
 * @op_type: operation type/name
 * @op_func: ptr to func of operation
 */
struct type_to_func
{
  char *op_type;
  void (*op_func)(char *src_ptr);
};

#endif /* MAIN_H */
