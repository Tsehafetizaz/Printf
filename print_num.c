#include "main.h"
/**
 * print_number - print a number
 * @num: num to be printed
 * Return: number
 */

int print_number(int num)
{
	int num_d = 0;
	int temp = num;
	int printed_chars = 0;
	int i = 0;
	char num_str[12];

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

	while (temp > 0)
	{
		temp /= 10;
		num_d++;
	}

	num_str[num_d] = '\0';

	for (i = num_d - 1; i >= 0; i--)
	{
		num_str[i] = num % 10 + '0';
		num /= 10;
	}

	printed_chars = print_string(num_str);

	return (printed_chars);
}
