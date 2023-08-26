#include "main.h"

/**
* _strlen - Calculates the length of a string.
* @s: Input string.
* Return: Length of the string.
*/
int _strlen(char *s)
{
    int len = 0;
    while (s[len]) len++;
    return (len);

}
