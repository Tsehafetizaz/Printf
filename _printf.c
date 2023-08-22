#include "main.h"
#include <unistd.h>
/**
* struct format_func - Struct format
* @type: The format type (char, string, etc.)
* @f: The function associated
*/
typedef struct format_func
{
char type;
int (*f)(va_list);
} format_f;
int _printf(const char *format, ...)
{
unsigned int i = 0, count = 0;
va_list args;
format_f types[] = {
{'c', _print_char},
{'s', _print_string},
{'%', _print_percent},
{'\0', NULL}
};
if (!format)
return (-1);
va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' && (format[i + 1] == 'c' ||
format[i + 1] == 's' || format[i + 1] == '%'))
{
count += (types[format[i + 1] - 'c']).f(args);
i++;
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
