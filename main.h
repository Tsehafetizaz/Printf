#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
void parse_print(const char *format, va_list args, int *char_count);
char print_char(va_list args);
char print_string(va_list args);
void print_percent(int *char_count);
int print_number(int num);
void _print_num(int n, int *char_count);
//char *print_integer(va_list args);
//char *print_binary(va_list args);
//char *_itoa(int num, char *str);
int _putchar(char c);
void _puts(const char *str);
int _strlen(const char *s);

#endif /* MAIN_H */
