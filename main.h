#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
/* struct buffer - Structure to hold a character buffer and an index */
typedef struct buffer
{
char buf[BUFFER_SIZE];  /* Character buffer */
int index;              /* Current index in the buffer */
} buffer_t;

/* Custom printf function */
int _printf(const char *format, ...);

/* Add a character to the buffer */
void buffer_add(buffer_t *output, char c);

/* Flush the buffer, possibly sending its content to an output stream */
void buffer_flush(buffer_t *output);

/* Print a character using variable argument lists */
void print_char(buffer_t *output, va_list args);

/* Print a string using variable argument lists */
int print_string(buffer_t *output, va_list args);

/* Print a percent sign (%) */
void print_percent(buffer_t *output);

#endif
