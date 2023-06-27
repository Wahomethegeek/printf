#include "main.h"

/**
  *print_char - prints a char
  *@args: va_list containing the character to print
  *Return: number of characters printed
  */

int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
  *print_string - prints a string
  *@args: va_list containing the string to output
  *Return: number of characters printed
  */

int print_string(va_list args)
{
	int length = 0;
	char *s;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "";
	_puts(s);

	while (s[length] != '\0')
		length++;
	return (length);
}
