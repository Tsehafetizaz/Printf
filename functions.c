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
