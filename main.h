#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFFSIZE 1024


int _printf(const char *format, ...);
int _putchar(char c);
void _puts(char *str);
