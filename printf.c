#include "main.h"
/**
 * _printf - Our custom printf function.
 * @format: The string format to print.
 * ... : The values to format and print.
 * Return: The number of characters printed.
 */
{
int _printf(const char *format, ...)
{
unsigned int i = 0, count = 0;
va_list args;

va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
count += write(1, &va_arg(args, int), 1);
i++;
break;
case 's':
// handle string here
i++;
break;
case '%':
count += write(1, &format[i], 1);
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
