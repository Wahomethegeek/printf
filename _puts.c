#include "main.h"

/**
 * _puts - This prints a string
 * @str: This is the string to printed
 * Return: sum
 */
int _puts(char *str)
{
	int sum = 0;

	for (; *str != '\0'; str++)
	{
		sum += _putchar(*str);
	}

	return (sum);
}
