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

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			count += process_format(format, args);
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
 * process_format - Processes format specifiers.
 * @format: The format specifier.
 * @args: The va_list of arguments.
 * Return: The number of characters processed.
 */
int process_format(const char *format, va_list args)
{
	int count = 0;
	char c;
	const char *str;
	int num;

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
	else if (*format == 'b')
	{
		num = va_arg(args, unsigned int);
		count += print_binary(num);
	}
	else
	{
		_putchar('%');
		_putchar(*format);
		count += 2;
	}

	return (count);
}
