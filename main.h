#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - Prints a character.
 * @c: The character to be printed.
 * Return: On success 1, on error -1.
 */
int _putchar(char c);

/**
 * print_number - Prints an integer.
 * @num: The integer to be printed.
 * Return: The number of digits printed.
 */
int print_number(int num);

/**
 * str_len - Calculates the length of a string.
 * @str: The input string.
 * Return: The length of the string.
 */
int str_len(const char *str);

/**
 * print_string - Prints a string.
 * @str: The string to be printed.
 * Return: The number of characters printed.
 */
int print_string(const char *str);

/**
 * _printf - Prints with format.
 * @format: The format string.
 * @...: Variadic arguments.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...);

#endif /* MAIN_H */
