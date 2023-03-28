#include "main.h"
#include <stdio.h>

int main(void)
{
	char *string1;
	char f;

	string1 = "Awesome";
	f = 'I';

	_printf("%c am 100% %s", f, string1);
	printf("%c am 100% %s", f, string1);

	return (0);
}
