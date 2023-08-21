/**
* @file print_percent.c
* @brief Implementation for printing the percent character.
*/

#include "my_printf.h"

/**
* @brief Prints a percent character.
* @return Number of characters printed.
*/
int print_percent() {
return write(1, "%", 1);
}
