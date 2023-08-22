#include "main.h"

/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal format.
 * @num: The unsigned integer to print.
 * @uppercase: Indicates whether to use uppercase letters (X) or lowercase (x).
 * Return: The number of characters printed.
 */
int print_hexadecimal(unsigned int num, int uppercase)
{
    char buffer[32];
    const char *digits = (uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";
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
            buffer[i] = digits[num % 16];
            num /= 16;
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
