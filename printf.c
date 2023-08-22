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
buffer_t output;
output.index = 0;
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' &&
(format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
print_char(&output, args);
count++;
i++;
break;
case 's':
count += print_string(&output, args);
i++;
break;
case '%':
print_percent(&output);
count++;
i++;
break;
}
}
else
{
buffer_add(&output, format[i]);
count++;
}
i++;
}
va_end(args);
buffer_flush(&output);
return (count);
}

