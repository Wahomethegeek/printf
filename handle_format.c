#include "main.h"

/**
 * handle_format - Format specifier in _printf handling
 * @format: Format specifier character.
 * @args: va_list arguments.
 * @sum: Pointer to the sum of characters printed.
 *
 * Return: Updated sum  of characters printed.
 */
int handle_format(char format, va_list args, int *sum)
{

	if (format == 'c')
	{
		char m  = (char)va_arg(args, int);

		if (m == '\0')
			*sum += _putchar('\0');
		else
			*sum += _putchar(m);
	}
	else if (format == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";
		*sum += _puts(str);
	}
	else if (format == '%')
		*sum += _putchar('%');
	else if (format == 'd' || format == 'i')
	{
		int num = va_arg(args, int);
		char buffer[BUFFER_SIZE];
		int length = snprintf(buffer, BUFFER_SIZE, "%d", num);

		sum += (_puts(&buffer[BUFFER_SIZE - length]) + length);
	}
	else
		*sum += (_putchar('%') + _putchar(format));

	return (*sum);
}
