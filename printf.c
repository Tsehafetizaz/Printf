#include "main.h"
#include <unistd.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;
if (!format)
return (-1);
va_start(args, format);
while (format[i])
{
if (format[i] == '%' && 
(format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
{
char c = va_arg(args, int);
count += _putchar(c);
}
i++;
break;
case 's':
str = va_arg(args, char *);
while (*str)
count += _putchar(*str), str++;
i++;
break;
case '%':
count += _putchar('%');
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
