#include "main.h"
/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * ... : The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
unsigned int i = 0, count = 0;
va_list args;
if (!format)
return (-1);
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' &&
(format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
count += write(1, &(char){va_arg(args, int)}, 1);
i++;
break;
case 's':
count += _puts(va_arg(args, char *));
i++;
break;
case '%':
count += write(1, "%", 1);
i++;
break;
}
}
else
{
count += write(1, &format[i], 1);
}
i++;
}
va_end(args);
return (count);
}
/**
 * _puts - Prints a string.
 * @str: The string to print.
 * Return: The number of characters printed.
 */
int _puts(char *str)
{
int i = 0, count = 0;
if (!str)
str = "(null)";
while (str[i])
{
write(1, &str[i], 1);
count++;
i++;
}
return (count);
}

