#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/*
 * _printf - A custom implementation of the printf function.
 * @format: The formatting string.
 * ... : Variable arguments.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
unsigned int i = 0, count = 0;
va_list args;
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' &&
(format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
i++; /* Skip the % symbol */
if (format[i] == 'c')
{
char c = (char) va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (format[i] == 's')
{
char *str = va_arg(args, char*);
int len = 0;
while (str[len])
len++;
write(1, str, len);
count += len;
}
else if (format[i] == '%')
{
write(1, &format[i], 1);
count++;
}
}
else
{
write(1, &format[i], 1);
count++;
}
i++;
}
va_end(args);
return (count);
}
