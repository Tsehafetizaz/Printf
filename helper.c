#include "main.h"
/**
 * buffer_add - Adds a character to the buffer.
 * @output: A pointer to the buffer structure.
 * @c: The character to add to the buffer.
 */
void buffer_add(buffer_t *output, char c)
{
if (output->index == BUFFER_SIZE)
{
write(1, output->buf, BUFFER_SIZE);
output->index = 0;
}
output->buf[output->index] = c;
output->index++;
}
/**
 * buffer_flush - Flushes the buffer.
 * @output: A pointer to the buffer structure.
 */
void buffer_flush(buffer_t *output)
{
write(1, output->buf, output->index);
}
/**
 * print_char - Prints a character.
 * @output: A pointer to the buffer structure.
 * @args: The list of arguments.
 */
void print_char(buffer_t *output, va_list args)
{
char c;
c = va_arg(args, int);
buffer_add(output, c);
}
/**
 * print_string - Prints a string.
 * @output: A pointer to the buffer structure.
 * @args: The list of arguments.
 * Return: The number of characters in the string.
 */
int print_string(buffer_t *output, va_list args)
{
char *str;
int i = 0;
str = va_arg(args, char*);
if (!str)
str = "(null)";
while (str[i])
{
buffer_add(output, str[i]);
i++;
}
return (i);
}
/**
 * print_percent - Prints a percent character.
 * @output: A pointer to the buffer structure.
 */
void print_percent(buffer_t *output)
{
buffer_add(output, '%');
}
