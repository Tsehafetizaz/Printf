#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct print - Specifies the appropriate function to format and print data.
 * @print: The format to print.
 * @f: The print function to use.
 */
typedef struct print
{
char *print;
int (*f)(va_list);
} print_t;

/* FUNCTION PROTOTYPES */

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * ...: The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...);

/**
 * print_char - Prints a character.
 * @list: The list of arguments.
 * Return: The number of characters printed.
 */
int print_char(va_list list);

/**
 * print_string - Prints a string.
 * @list: The list of arguments.
 * Return: The number of characters printed.
 */
int print_string(va_list list);

/**
 * print_int - Prints an integer.
 * @list: The list of arguments.
 * Return: The number of digits printed.
 */
int print_int(va_list list);

/**
 * print_binary - Prints the binary representation of an integer.
 * @list: The list of arguments.
 * Return: The number of digits printed.
 */
int print_binary(va_list list);

/* ADDITIONAL FUNCTION PROTOTYPES AS NEEDED */

#endif /* MAIN_H */
