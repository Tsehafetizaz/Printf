#include "main.h"
/**
 * print_number - print a number
 * @num: num to be printed
 * Return: number
 */

int print_number(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	int num_digits = 0;
	int temp = num;

	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}

	char num_str[num_digits + 1];

	num_str[num_digits] = '\0';

	for (int i = num_digits - 1; i >= 0; i--)
	{
		num_str[i] = num % 10 + '0';
		num /= 10;
	}

	int printed_chars = print_string(num_str);

	return (printed_chars);
}
