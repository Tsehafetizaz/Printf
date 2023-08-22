#include "main.h"
/**
 * _printf - prints with format
 * @format: no args
 * Return: count
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
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				count += _putchar(c);
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, char *);

				count += print_string(str);
			}
			else
			{
				_putchar(*format);
				count++;
			}
		}
		else if (format[i] == '%' &&
				(format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int num = va_arg(args, int);
			if (num < 0)
			{
				count += _putchar('-');
				num = -num;
			}
			count += print_number(num);
			i++;
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
