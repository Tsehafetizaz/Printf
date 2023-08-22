#include "main.h"
/**
* print_char - Prints a character.
* @arg_list: The list of arguments.
* Return: Number of characters printed.
*/
static int print_char(va_list arg_list)
{
char c;
c = (char) va_arg(arg_list, int);
write(1, &c, 1);
return (1);
}
/**
* print_string - Prints a string.
* @arg_list: The list of arguments.
* Return: Number of characters printed.
*/
static int print_string(va_list arg_list)
{
char *s;
int i = 0;
s = va_arg(arg_list, char *);
while
(s[i])
{
write(1, &s[i], 1);
i++;
}
return
(i);
}
/**
* print_percent - Prints a percent sign.
* @arg_list: The list of arguments.
* Return: Number of characters printed.
*/
static int print_percent(va_list arg_list)
{
char c;
(void) arg_list; /* unused parameter */
c = '%';
write(1, &c, 1);
return (1);
}
/**
* _printf - Our custom printf function.
* @format: The format string.
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list arg_list;
va_start
(arg_list, format);
while
(*format)
{
if
(*format == '%' &&
(*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
{
format++; /* skip the '%' */
switch
(*format)
{
case 'c':
printed_chars += print_char(arg_list);
break;
case 's':
printed_chars += print_string(arg_list);
break;
case '%':
printed_chars += print_percent(arg_list);
break;
}
}
else
{
write(1, format, 1);
printed_chars++;
}
format++;
}
va_end
(arg_list);
return
(printed_chars);
}
