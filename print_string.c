#include "main.h"
/**
 * print_str - prints a string
 * @str: string
 * Return: length
 */

int print_string(const char *str)
{
	write(1, str, str_len(str));
	return (str_len(str));
}

/**
 * str_len - get str len
 * @str: string to be calculated
 * Return: str length
 */

int str_len(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}
