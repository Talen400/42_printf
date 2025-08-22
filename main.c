#include "ft_printf.h"

int main(void)
{
	int len;

	len = ft_printf("Testando len\n");
	ft_printf("len: %d\n", len);

	len = ft_printf("%c\n", '0');
	ft_printf("len: %d\n", len);

	len = ft_printf("%% \n");
	ft_printf("len: %d\n", len);

	len = ft_printf("meow: %ca stri%cng %cvoid * he\n", 'A', 'B', 'C');
	ft_printf("len: %d\n", len);

	len = ft_printf("meow: %sa string void * he\n", "STRING\n");
	ft_printf("len: %d\n", len);

	char *pointer;
	pointer = 0;

	printf("%p\n", pointer);
	len = ft_printf("%p\n", pointer);
	ft_printf("len: %d\n", len);

	printf("printf: %d\n", -123);
	len = ft_printf("ft_printf: %d\n", -123);
	ft_printf("len: %d\n", len);

	printf("printf: %u\n", -123);
	len = ft_printf("ft_printf: %u\n", -123);
	ft_printf("len: %d\n", len);

	printf("printf: %u\n", 0);
	len = ft_printf("ft_printf: %u\n", 0);
	ft_printf("len: %d\n", len);
	
	char *str = NULL;

	printf("printf: NULL %s NULL \n", str);
	ft_printf("ft_printf: NULL %s NULL \n", str);

	printf("%x\n", 12314123);
	printf("%x\n", 255);
	printf("%x\n", 16);
	printf("%x\n", 0);
}
