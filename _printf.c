#include "main.h"

/**
  *_printf - write output to the standard output stream
  *@format: a character string
  *Return: the characters printed
  */

int _printf(const char *format, ...)
{
	int i = 0, num = 0;
	va_list args;

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					num += print_char(args);
					break;
				case 's':
					num += print_string(args);
					break;
				case '%':
					num =+ _putchar('%');
					break;
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (0);
}
