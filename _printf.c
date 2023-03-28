#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - custom printf function
 * @format: string to print
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, char_printed = 0, printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list ap;
	char buffer[BUFFSIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '&')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFSIZE)
				print_buffer(buffer, &buff_ind);
			char_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap, buffer,
				      flags, width, precision, size);
			if (printed == -1)
				return (-1);
			char_printed += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(ap);

	return (char_printed);
}

/**
 * print_buffer - prints the content of an existing buffer
 * @buffer: an array of characters
 * @buff_ind: length and doubles as index at which to add the next char
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
