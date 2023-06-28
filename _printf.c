#include "main.h"
/**
 * _printf - This prints strings to the stdout
 * @format: This prints a specific char
 * Return: Returns the printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int sum = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			sum += _putchar(formart[i]);
		}
		else
		{
			i++;
			if (formart[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			sum = handle_format(format[i], args, &sum);
		}

		i++;
	}

	va_end(args);

	return (sum);
}
