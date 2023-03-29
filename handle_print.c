#include "main.h"

/**
 * handle_print - prints an arguement based on the type of data it is
 * @format: formatted string containing arguemnt
 * @ap: list of arguments to be printed
 * @ind: index
 * @buffer: the array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: specifies precision
 * @size: specifies size
 * Return: either 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list ap, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_length = 0, char_printed = 0;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
	      {'i', print_int}, {'d', print_int}, {'b', print_binary},
	      {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
	      {'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
	      {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].func(list, buffer, flags, width,
						precision, size));
	}

	if (fmt_types[i].fmt != '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_length += write(1, &fmt[*ind], 1);

		return (unknown_length);
	}
	return (char_printed);
}
