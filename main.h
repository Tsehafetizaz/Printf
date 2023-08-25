#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
char *print_char(va_list args);
char *print_string(va_list args);
char *print_percent(void);
char *print_integer(va_list args);
char *print_binary(va_list args);
char *_itoa(int num, char *str);
int _putchar(char c);
int _strlen(const char *s);

#endif /* MAIN_H */
