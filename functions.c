#include <unistd.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

void print_string(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}

void print_number(int num)
{
	int divisor = 1;

	if (num < 0)
	{ 
		_putchar('-');
		num = -num;
	}
	
	while (num / divisor >= 10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		int digit = num / divisor;
		_putchar('0' + digit);
		num %= divisor;
		divisor /= 10;
	}

}
