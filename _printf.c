#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Our custom printf function.
* @format: Format string.
* ... : Additional arguments.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
	va_list args;

	int char_count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	parse_and_print(format, args, &char_count);

	va_end(args);

	return (char_count);
}
