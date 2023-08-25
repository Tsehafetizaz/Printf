#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * parse_print - checks the characters and print
 * @format: the formatted string to be printed
 * @args: variable argument list
 * @char_count: counts the number of characters printed
 */
void parse_print(const char *format, va_list args, int *char_count)
{
	char ch, *str;
	int num; /* to hold an integer 'd' */

	while (*format != '\0') /* check if end of string is reached */
	{
		if (*format != '%') /* check if charcter is not an identifier */
		{
			print_char(*format, char_count);
		} else /* check for identifiers %c, %s, %% */
		{
			format++; /* move past % */
			if (*format == 'c') /* when format is %c */
			{
				ch = va_arg(args, int);
				print_char(ch, char_count);
			} else if (*format == 's') /* when format is %s */
			{
				str = va_arg(args, char *);
				print_string(str, char_count);
			} else if (*format == '%') /* when format is %% */
				if (str == NULL)
				{
					print_string("(null)", char_count);
				} else
				{
					print_string(str, char_count);
				}
			} else if (*format == '%') /* when format is %% */
			{
				print_percent(char_count);
			} else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);
				_print_num(num, char_count);
			}
		}
		format++;
	}
}
