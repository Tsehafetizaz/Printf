#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#define BUFF_SIZE 1024
int handle_percent_case(const char *format, int i,
char *buffer, int *buffer_index, va_list args);
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
int i, printed_chars = 0, buffer_index = 0;
va_list args;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(args, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
handle_character(format[i], buffer, &buffer_index);
else
{
print_buffer(buffer, &buffer_index);
i = handle_percent_case(format, i, buffer, &buffer_index, args);
}
}
print_buffer(buffer, &buffer_index);
va_end(args);
return (printed_chars);
}
/**
 * handle_character - Handles the insertion of a character into the buffer.
 * @c: The character to insert.
 * @buffer: The buffer.
 * @buffer_index: The current position in the buffer.
 */
void handle_character(char c, char *buffer, int *buffer_index)
{
buffer[(*buffer_index)++] = c;
if (*buffer_index == BUFF_SIZE)
print_buffer(buffer, buffer_index);
}
/**
 * handle_string - Handles the insertion of a string into the buffer.
 * @str: The string to insert.
 * @buffer: The buffer.
 * @buffer_index: The current position in the buffer.
 */
void handle_string(char *str, char *buffer, int *buffer_index)
{
while (*str)
{
buffer[(*buffer_index)++] = *str++;
if (*buffer_index == BUFF_SIZE)
print_buffer(buffer, buffer_index);
}
}
int handle_percent_case(const char *format, int i,
char *buffer, int *buffer_index, va_list args)
{
i++;
if (format[i] == 'c')
handle_character(va_arg(args, int), buffer, buffer_index);
else if (format[i] == 's')
handle_string(va_arg(args, char *), buffer, buffer_index);
else if (format[i] == '%')
handle_character('%', buffer, buffer_index);
else
{
handle_character('%', buffer, buffer_index);
handle_character(format[i], buffer, buffer_index);
}
return (i);
}
/**
 * print_buffer - Prints the buffer to stdout.
 * @buffer: The buffer containing characters to print.
 * @buff_ind: The current index in the buffer.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, buffer, *buff_ind);
*buff_ind = 0;
}
}
