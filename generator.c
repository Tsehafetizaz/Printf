#include "main.h"

/**
 * print_char - prints a character
 * @char_count: counts and increament the number of characters
 * @c: a character passed to the function
 * Return: nothing
 */
void print_char(char c, int *char_count)
{
	_putchar(c);
	(*char_count)++;
}

/**
 * print_string - prints out string
 * @str: a string passed to the function
 * @char_count: counts and increament the number of characters
 * Return: nothing
 */
void print_string(const char *str, int *char_count)
{
	_puts(str);
	(*char_count) += _strlen(str);
}

/**
 * print_percent - prints the percentage symbol
 * @char_count: counts and increament the number of characters
 * Return: nothing
 */
void print_percent(int *char_count)
{
	_putchar('%');
	(*char_count)++;

}

/**
 * print_number - print integers
 * @n: the number to print
 * @char_count: count the number of characters printed
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
