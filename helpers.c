#include "main.h"

/*
* convert an integer to a string
* *int_to_str: Convert an integer to a string.
* @n: The integer to be converted.
* Return: The converted string.
*/

char *int_to_str(int n)
{
static char str[12];
int i = 0, temp, is_negative = 0;

if (n == 0)
{
str[i++] = '0';
str[i] = '\0';
return (str);
}

if (n < 0)
{
is_negative = 1;
n = -n;
}

while (n)
{
temp = n % 10;
str[i++] = temp + '0';
n = n / 10;
}

if (is_negative)
{
str[i++] = '-';
}
str[i] = '\0';
{
int start, end;
for (start = 0, end = i - 1; start < end; start++, end--)
{
char temp_char = str[start];
str[start] = str[end];
str[end] = temp_char;
}
}
return (str);
}

