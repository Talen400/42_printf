#include "libft/libft.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	// flags "#0- +" are of C99 standard

	// # - adding 0x
	printf("\ntest: %#x", 42);
	printf("\ntest: %#X", 42);
	printf("\ntest: %x", 42);
	printf("\ntest: %X", 42);

	// 0 -- padding left
	printf("\ntest: %03d", 42);
	printf("\ntest: %03d", 42);
	printf("\ntest: %010d", 42);
	printf("\ntest: %010i", 42);
	printf("\ntest: %010u", 42);
	printf("\ntest: %010x", 42);
	printf("\ntest: %010X", 42);
	
	// - -- padding left reverse
	printf("\ntest: %-10d", 42);

	// ' ' -- adding space into left of number
	printf("\ntest: % 2d", 42);
	printf("\ntest: % 10d", 42);

	// + -- show the sign of number
	printf("\ntest: %+d", -42);
	printf("\ntest: %+d", +42);


	// flag "'" is of POSIX
	// ' -- is a locale format
	
	setlocale(LC_NUMERIC, "");
	printf("\ntest: %'d", 4222221);
	printf("\ntest: %'.2f", +4222222.1);

	return (0);
}
