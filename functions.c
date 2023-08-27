#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

void print_string(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}

/**
 * print_number - Convert an integer to a string and return a pointer to it.
 * @num: The integer to convert.
 *
 * Return: Pointer to the resulting string.
 */
char *print_number(int num)
{
	static char numi[1024];
	int divisor = 1;
	char *result = numi;
	
	if (num < 0)
	{
		*result = '-';
		result++;
		num = -num;
	}
	
	while (num / divisor >= 10)
	{
		divisor *= 10;
	}
	
	while (divisor > 0) {
		int digit = num / divisor;
		*result = '0' + digit;
		result++;
		num %= divisor;
		divisor /= 10;
	}
	
	*result = '\0';
	return (numi);
}

char *print_binary(int num)
{
	static char numi[1024];
	char *result = numi;
	int i = 0;
	int binary[32];
	int j = 0;

	while (num > 0)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
	}

	if (i == '0')
	{
		*result = '0';
		result++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			*result = '0' + binary[j];
			result++;
		}
	}

	return (numi);
}
