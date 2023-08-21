/**
 * @file my_printf.h
 * @brief Header file for custom printf function and helper functions.
 */

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
* @brief A basic implementation of the printf function.
* @param format String format with potential format specifiers.
* @return Number of characters printed.
*/
int _printf(const char *format, ...);

/**
* @brief Prints a character.
* @param args Variadic argument list.
* @return Number of characters printed.
*/
int print_char(va_list args);

/**
* @brief Prints a string.
* @param args Variadic argument list.
* @return Number of characters printed.
*/
int print_string(va_list args);

/**
* @brief Prints a percent character.
* @return Number of characters printed.
*/
int print_percent(void);

#endif // MY_PRINTF_H

