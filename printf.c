#include "main.h"
#include <stdarg.h>
/**
 * _printf - print anything with formated output
 * @format: format given
 * @...: any arg
 * Return: 0 or NULL
 */

int _printf(const char *format, ...)
{
	va_list args;
	int num = 0;
	char *str;
	char *numm;
	int count = 0;

	char output_buffer[1024];
        char *output = output_buffer;
	va_start(args, format);

	while (*format)
	{
		if(*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char chr = va_arg(args, int);
				*output = chr;
				output++;
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char*);
				while(*str)
				{
					*output = *str;
					output++;
					count++;
					str++;
				}
			}
			else if (*format == '%')
			{
				*output = '%';
				output++;
				count++;
			}
			else if(*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);
				numm = print_number(num);
				while(*numm)
                                {
                                        *output = *numm;
                                        output++;
					count++;
                                        numm++;
                                }
			}
			else if(*format == 'b')
			{
				num = va_arg(args, int);
				numm = print_binary(num);
				while(*numm)
				{
					*output = *numm;
					output++;
					count++;
					numm++;
				}
			}
			else
			{
				format--;
				*output = *format;
				output++;
				count++;
			}
		}
		else
		{
			*output = *format;
			output++;
			count++;
		}

		format ++;
	}

	*output = '\0';
	print_string(output_buffer);

	va_end(args);

	return (count);
}
