#include "main.h"
#include <unistd.h>

/**
 *_putchar - writes the character c to stdout
 *@c: a parameter to the function
 * Return: on success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - prints a string followed by a new line
 * @str: a parameter to the function
 */

void _puts(const char *str)
{
	for (; *str != '\0'; str++)
	{
		_putchar(*str);
	}
	/* _putchar('\n'); */
}


/**
 * _strlen - returns the lenght of a string
 * @s: a parameter to the function
 * Return: the length of string
 */
int _strlen(const char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _print_num - prints an integer
 * @n: integer to be printed
 * @char_count: count the number of characters printed
 */
void _print_num(int n, int *char_count)
{
	int digit, leading_zeros = 1, divisor = 1;

	if (n == 0)
	{
		_putchar('0');
		(*char_count)++;
		return;
	}

	if (n < 0)
	{
		_putchar('-');
		(*char_count)++;
		n = -n; /* convert to positive for printing digits */
	}

	/* Use a flag to handle leading zeros */

	while (n / divisor > 9)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		digit = n / divisor;
		n %= divisor;
		divisor /= 10;

		if (!leading_zeros || digit > 0)
		{
			_putchar(digit + '0');
			(*char_count)++;
			leading_zeros = 0;
		}
	}
}
