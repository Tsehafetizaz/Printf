#include "main.h"

/**
 * _printf - Prints with format.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	const char *str
	int num = 0;
	
	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (*format == 'c')
				count += handle_char(args);
			else if (*format == 's')
				count += handle_string(args);
			else if (*format == 'd' || *format == 'i')
				count += handle_number(args);
			else
				count += handle_unknown(*format);
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * handle_char - Handles %c format specifier.
 * @args: The va_list of arguments.
 * Return: The number of characters printed.
 */
int handle_char(va_list args)
{
	c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * handle_string - Handles %s format specifier.
 * @args: The va_list of arguments.
 * Return: The number of characters printed.
 */
int handle_string(va_list args)
{
	str = va_arg(args, char *);
	return (print_string(str));
}

/**
 * handle_number - Handles %d and %i format specifiers.
 * @args: The va_list of arguments.
 * Return: The number of characters printed.
 */
int handle_number(va_list args)
{
	num = va_arg(args, int);
	return (print_number(num));
}

/**
 * handle_unknown - Handles unknown format specifier.
 * @format: The unknown format specifier.
 * Return: The number of characters printed.
 */
int handle_unknown(char format)
{
	_putchar('%');
	_putchar(format);
	return (2);
}
