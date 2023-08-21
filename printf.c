#include "main.h"
#include <string.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    va_list args;
    int i = 0, count = 0;
    char *str;
    
    if (!format)
        return (-1);

    va_start(args, format);
    
    while (format[i]) {
        if (format[i] == '%' &&
            (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%' || format[i + 1] == 'd' || format[i + 1] == 'i')) {
            switch (format[i + 1]) {
                case 'c': {
                    char c = va_arg(args, int);
                    count += write(1, &c, 1);
                    break;
                }
                case 's': {
                    str = va_arg(args, char *);
                    while (*str)
                        count += _putchar(*str), str++;
                    break;
                }
                case '%':
                    count += write(1, "%", 1);
                    break;
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    if (num < 0) {
                        count += _putchar('-');
                        num = -num;
                    }
                    count += print_number(num);
                    break;
                }
            }
            i++;
        } else {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return count;
}

int print_number(int num) {
    int count = 0;
    if (num == 0) {
        count += _putchar('0');
        return count;
    }
    if (num / 10) {
        count += print_number(num / 10);
    }
    count += _putchar('0' + num % 10);
    return count;
}
