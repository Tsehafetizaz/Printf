#include "main.h"
#include <string.h>

/**
* _printf - A basic implementation of the printf function.
* Supports format specifiers:
* %c: character
* %s: string
* %%: literal percentage character
* @format: The format string.
* ... : The values to format and print.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;
if (!format) return (-1); 
va_start(args, format);
while (format[i])
{
if (format[i] == '%' && strchr("cs%", format[i+1]))
{
if (format[i + 1] == 'c') count += write(1, &(char)
{va_arg(args, int)}, 1);
if (format[i + 1] == 's')
{
str = va_arg(args, char *);
count += write(1, str ? str : "(null)", str ? strlen(str) : 6);
}
if (format[i + 1] == '%') count += write(1, "%", 1);
i++;
} else count += write(1, &format[i], 1);
i++;
}
va_end(args);
return (count);
}
