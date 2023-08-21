#include "main.h"
#include <unistd.h> // For write function

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;

    for (int i = 0; format[i]; i++) {
        if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%')) {
            switch (format[i + 1]) {
                case 'c': {
                    char c = va_arg(args, int);
                    count += _putchar(c);
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str)
                        count += _putchar(*str), str++;
                    break;
                }
                case '%':
                    count += _putchar('%');
                    break;
            }
            i++;
        } else {
            count += _putchar(format[i]);
        }
    }

    va_end(args);
    return count;
}
