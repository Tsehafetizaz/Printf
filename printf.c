#include "main.h"

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, void *arg1, void *arg2) {
    int i = 0, count = 0;
    char *str;

    if (!format)
        return (-1);

    while (format[i]) {
        if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%' || format[i + 1] == 'd' || format[i + 1] == 'i')) {
            switch (format[i + 1]) {
                case 'c': {
                    char c = *((char *)arg1);
                    count += write(1, &c, 1);
                    break;
                }
                case 's': {
                    str = *((char **)arg1);
                    while (*str)
                        count += _putchar(*str), str++;
                    break;
                }
                case '%':
                    count += write(1, "%", 1);
                    break;
                case 'd':
                case 'i': {
                    int num = *((int *)arg1);
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
