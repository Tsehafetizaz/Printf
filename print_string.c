/**
* @file print_string.c
* @brief Implementation for the string printing function.
*/

#include "my_printf.h"

/**
* @brief Prints a string.
* @param args Variadic argument list containing a string.
* @return Number of characters printed.
*/
int print_string(va_list args) {
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
return write(1, str, strlen(str));
}
