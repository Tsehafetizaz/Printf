#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @num: The unsigned integer to be printed.
 * Return: The number of digits printed.
 */
int print_unsigned(unsigned int num)
{
	int printed_chars = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	int num_digits = 0;
	unsigned int temp = num;

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

	printed_chars = print_string(num_str);
	return (printed_chars);
}
