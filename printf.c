#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _putchar(char c)
{
return (write(1, &c, 1));
}

int print_char(va_list args)
{
return (_putchar(va_arg(args, int)));
}

int print_string(va_list args)
{
char *str = va_arg(args, char *);
return (write(1, str, strlen(str)));
}

int _printf(const char *format, ...)
{
unsigned int i = 0, count = 0;
va_list args;
if (!format)
{
return (-1);
}
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
if (format[i + 1] == 'c')
{
count += print_char(args);
}
else if (format[i + 1] == 's')
{
count += print_string(args);
}
else if (format[i + 1] == '%')
{
count += _putchar('%');
}
i++;
}
else
{
count += _putchar(format[i]);
}
i++;
}
va_end(args);
return (count);
}
