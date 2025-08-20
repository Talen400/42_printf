#include "printf.h"

int main(void)
{
	ft_printf("%% \n");
	ft_printf("meow: %ca stri%cng %cvoid * he\n", 'A', 'B', 'C');
	ft_printf("meow: %sa string void * he\n", "STRING\n");
	char *pointer;
	pointer = "asd";
	printf("%p\n", pointer);
	ft_printf("%p\n", pointer);
	printf("printf: %u\n", -123);
	ft_printf("ft_printf: %u\n", -123);
}
