#include "main.h"

/**
  *_printf - write output to the standard output stream
  *@format: a character string
  *Return: the characters printed
  */

int _printf(const char *format, ...)
{
	int num = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					num += print_char(args);
					break;
				case 's':
					num += print_string(args);
					break;
				case '%':
					 _putchar('%');
					 num++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					num += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			num++;
		}
		format++;
	}
	va_end(args);
	return (num);
}

