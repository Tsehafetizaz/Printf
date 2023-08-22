#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary format.
 * @num: The unsigned int to be printed.
 * Return: The number of digits printed.
 */
int print_binary(unsigned int num)
{
	int num_digits = 0;
	unsigned int temp = num;
	unsigned int mask = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (temp > 0)
	{
		temp /= 2;
		num_digits++;
	}

	mask = 1 << (num_digits - 1);

	while (mask > 0)
	{
		_putchar((num & mask) ? '1' : '0');
		mask >>= 1;
	}

	return (num_digits);
}
