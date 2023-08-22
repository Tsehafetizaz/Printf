#include "main.h"
/**
 * print_octal - Prints an unsigned integer in octal format.
 * @num: The unsigned integer to print.
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num)
{
    char buffer[32];
    int count = 0;
    int i = 0;

    if (num == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        while (num != 0)
        {
            buffer[i] = (num % 8) + '0';
            num /= 8;
            i++;
        }

        while (i > 0)
        {
            i--;
            _putchar(buffer[i]);
            count++;
        }
    }

    return (count);
}
