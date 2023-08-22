#include "main.h"
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
