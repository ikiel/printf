#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFFSIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - struct operation
 *
 * @format: the format
 * @func: The function associated with the format
 */
struct format
{
	char format;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format fmt_t - assigning struct format to fmt_t
 *
 * @format: the format
 * @func: function associated with format
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i, va_list ap, char buffer[],
		int flags, int width, int precision, int size);

#endif /* endif MAIN_H */
