#include "main.h"
/**
 * _putchar - This prints a character
 * @c: This is the character to be printed
 * Return: write, address of c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
