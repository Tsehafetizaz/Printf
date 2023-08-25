#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Our custom printf function.
* @format: Format string.
* ... : Additional arguments.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    unsigned int i = 0;
    if (!format) return (-1);
    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' ||
                                 format[i + 1] == '%')) {
            i++;
            switch (format[i]) {
                case 'c':
                    count += write(1, &(char){va_arg(args, int)}, 1);
                    break;
                case 's':
                    count += write(1, va_arg(args, char*), _strlen(va_arg(args, char*)));
                    break;
                case '%':
                    count += write(1, &format[i], 1);
                    break;
            }
        } else {
            count += write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return (count);
}
