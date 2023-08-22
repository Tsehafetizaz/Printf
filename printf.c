#include "main.h"

/**
 * _printf - Prints with format.
 * @format: Format string.
 * @...: a variadic arguments.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	const char *str;
	int num;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				count += _putchar(c);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				count += print_string(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);
				count += print_number(num);
			}
			else
			{
				_putchar(*format);
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args) ;
	return (count);
}
