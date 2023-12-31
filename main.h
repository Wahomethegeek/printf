#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_binary(unsigned int num);
int print_escaped_string(char *str);
int print_reversed_string(char *str);
int print_rot13_string(char *str);
int handle_format(char format, va_list args, int *sum);
int handle_integers(va_list args, int *sum);
#endif
