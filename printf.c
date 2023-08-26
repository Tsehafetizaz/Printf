#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if(*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char chr = va_arg(args, int);
				_putchar(chr);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				print_string(str);
			}
			else if (*format == '%')
			{
				_putchar(*format);
			}
			else if(*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				print_number(num);
			}
			else
			_putchar(*format);
		}
		else
		_putchar(*format);

		format ++;
	}

	va_end(args);

	return (0);
}
