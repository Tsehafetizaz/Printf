/**
* @file print_char.c
* @brief Implementation for the character printing function.
*/

#include "my_printf.h"

/**
* @brief Prints a character.
* @param args Variadic argument list containing a character.
* @return Number of characters printed.
*/
int print_char(va_list args) {
char c = va_arg(args, int);
return write(1, &c, 1);
}
