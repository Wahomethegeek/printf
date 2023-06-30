#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int print_binary(unsigned int num);
int print_escaped_string(char *str);
int print_reversed_string(char *str);
int print_rot13_string(char *str);

int _putchar(char c)
{
   return write(1, &c, 1);
}

int _puts(char *str)
{
    int sum = 0;
    while (*str)
    {
        sum += _putchar(*str);
        str++;
    }
    return sum;
}

int _printf(const char *format, ...)
{
    va_list args;
    int sum = 0;  /* characters printed */
    char buffer[BUFFER_SIZE];  /* Local buffer */
    int i;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            /* Regular character*/
            sum += _putchar(format[i]);
        }
        else
        {
            i++;  /* Skip the '%' */

            /* Checking conversion specifier */
            switch (format[i])
            {
                case 'c':
                    /* Print a character */
                    sum += _putchar(va_arg(args, int));
                    break;
                 case 's':
                    /* Print a string */
                    sum += _puts(va_arg(args, char *));
                    break;

                case '%':
                    /* Print a literal '%' */
                    sum += _putchar('%');
                    break;

                case 'd':
                case 'i':
                    /* Print a decimal integer */
                    sum += sprintf(buffer, "%d", va_arg(args, int));
                    sum += _puts(buffer);
                    break;

                case 'u':
                    /* Printing  unsigned decimal integer */
                    sum += sprintf(buffer, "%u", va_arg(args, unsigned int));
                    sum += _puts(buffer);
                    break;

                case 'o':
                    /* Printing octal integer */
                    sum += sprintf(buffer, "%o", va_arg(args, unsigned int));
                    sum += _puts(buffer);
                    break;

                case 'x':
                    /* Printing a hexadecimal integer (lowercase) */
                    sum += sprintf(buffer, "%x", va_arg(args, unsigned int));
                    sum += _puts(buffer);
                    break;

                case 'X':
                    /* Printing a hexadecimal integer (uppercase) */
                    sum += sprintf(buffer, "%X", va_arg(args, unsigned int));
                    sum += _puts(buffer);
                    break;

		case 'b':
                    /* Printing unsigned integer in binary format */
                    sum += print_binary(va_arg(args, unsigned int));
                    break;

                case 'S':
                    /* Printing string with non-printable characters escaped */
                    sum += print_escaped_string(va_arg(args, char *));
                    break;
                case 'p':
                    /* Printing pointer address */
                    sum += sprintf(buffer, "%p", va_arg(args, void *));
                    sum += _puts(buffer);
                    break;

                case 'r':
                    /* Printing a reversed string */
                    sum += print_reversed_string(va_arg(args, char *));
                    break;

                case 'R':
                    /* Printing a ROT13 encoded string */
                    sum += print_rot13_string(va_arg(args, char *));
                    break;

                default:
                    /* Invalid conversion specifier, ignore */
                    break;
            }
        }
    }

    va_end(args);
    return sum;
}

int print_binary(unsigned int num)
{
    int sum = 0;
    int i = 0;
    int j;
    char buffer[BUFFER_SIZE];

    if (num == 0)
    {
        sum += _putchar('0');
    }
    else
    {
        while (num > 0)
        {
            buffer[i++] = num % 2 + '0';
            num /= 2;
        }

        for (j = i - 1; j >= 0; j--)
        {
            sum += _putchar(buffer[j]);
        }
    }

    return sum;
}

int print_escaped_string(char *str)
{
    int sum = 0;
    while (*str)
    {
        if (*str < ' ' || *str >= 127)
        {
           /*non printable*/
	}
}
}
