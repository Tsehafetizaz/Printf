#include "my_printf.h"
/**
* @brief A basic implementation of the printf function.
* Supports format specifiers: %c for characters, %s for strings, and %% for the literal percent sign.
* @param format String format with potential format specifiers.
* @return Number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
if (!format)
{
return (-1);
}
va_start(args, format);
while (format[i])
{
if (format[i] == '%' && 
(format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
count += print_char(args);
i++;
break;
case 's':
count += print_string(args);
i++;
break;
case '%':
count += print_percent();
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
