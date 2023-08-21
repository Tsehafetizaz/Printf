#include "main.h"
#include <unistd.h>
/**
 * _putchar - prints character
 * @c: char
 * Return: write
 */

int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _printf - prints with format
 * @format: no args
 * Return: count
 */

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
else if (format[i] == '%' &&
		(format[i + 1] == 'd' || format[i + 1] == 'i'))
{
int num = va_arg(args, int);
if (num < 0)
{
count += _putchar('-');
num = -num;
}
count += print_number(num);
i++;
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
 * print_number - print a number
 * @num: num to be printed
 * Return: number
 */

int print_number(int num)
{
int count = 0;
if (num == 0)
{
count += _putchar('0');
return (count);
}
if (num / 10)
{
count += print_number(num / 10);
}
count += _putchar('0' + num % 10);
return (count);
}
