#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @num: The unsigned integer to be printed.
 * Return: The number of digits printed.
 */
int print_unsigned(unsigned int num)
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
            buffer[i] = (num % 10) + '0';
            num /= 10;
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
