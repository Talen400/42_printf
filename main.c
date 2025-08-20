#include "printf.h"

void       foo(char *fmt, ...)   /* '...' is C syntax for a variadic function */
{
           va_list ap;
           int d;
           char c;
           char *s;

           va_start(ap, fmt);
           while (*fmt)
               switch (*fmt++) {
               case 's':              /* string */
                   s = va_arg(ap, char *);
                   printf("string %s\n", s);
                   break;
               case 'd':              /* int */
                   d = va_arg(ap, int);
                   printf("int %d\n", d);
                   break;
               case 'c':              /* char */
                   /* need a cast here since va_arg only
                      takes fully promoted types */
                   c = (char) va_arg(ap, int);
                   printf("char %c\n", c);
                   break;
               }
           va_end(ap);
}

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
