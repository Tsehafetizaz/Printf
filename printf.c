#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	for (int i = 0; format[i]; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'c' ||
					format[i + 1] == 's' || format[i + 1] == '%'))
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
				for (char *str = va_arg(args, char *); *str; str++)
					count += _putchar(*str);
				break;
				case '%':
				count += _putchar('%');
				break;
			}
			i++;
		}
		else
		{
			count += _putchar(format[i]);
		}
	}
	va_end(args);
	return (count);
}
