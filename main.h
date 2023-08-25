#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
void parse_print(const char *format, va_list args, int *char_count);
void print_char(char c, int *char_count);
void print_string(const char *str, int *char_count);
void print_percent(int *char_count);
int print_number(int num);
void _print_num(int n, int *char_count);
int _putchar(char c);
void _puts(const char *str);
int _strlen(const char *s);

#endif /* MAIN_H */
