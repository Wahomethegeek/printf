#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_integers - Handling 'd' and 'i' format specifiers
 * @args: The va_list arguments.
 * @sum: Pointer to the sum of characters printed.
 *
 * Return: The updated sum of characters printed.
 */
int handle_integers(va_list args, int *sum)
{
	int len;
	char *buffer;
	va_list args_clone;

	va_copy(args_clone, args);
	len = vsnprintf(NULL, 0, "%d", args_clone);
	va_end(args_clone);

	buffer = malloc(len + 1);
	if (buffer == NULL)
		return (-1);

	vsprintf(buffer, "%d", args);

	*sum += _puts(buffer);
	free(buffer);

	return (*sum);
}

