#include "main.h"
/**
 * print_number - print a number
 * @num: num to be printed
 * Return: number
 */

int print_number(int num)
{
	int printed_chars = 0;
	int divisor = 1;
	int temp;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		printed_chars++;
	}

	temp = num;
	while (temp > 0)
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor > 1)
	{
		divisor /= 10;
		_putchar((num / divisor) + '0');
		num %= divisor;
		printed_chars++;
	}

	return (printed_chars);
}
