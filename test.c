#include "libft/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include <stddef.h>

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

    int pos = 42;
    int neg = -42;
    int num = 7;
    int cento_vinte_tres = 123;
    int grande = 1234567;
    int largura = 6;
    int precisao = 4;

    signed char sc = 120;
    short int si = 30000;
    long int li = 1234567890L;
    long long int lli = 987654321012345LL;
    intmax_t im = 9223372036854775807LL;
    ssize_t ssz = 1024;
    int arr[5];
    ptrdiff_t diff = &arr[4] - &arr[0];

    // flags '-'
    printf("|%-5d|\n", pos);

    // flags ' ' => space
    printf("|% d|\n", pos);
    printf("|% d|\n", neg);

    // flags '+'
    printf("|%+5d|\n", pos);
    printf("|%+5d|\n", neg);

    // flags '0'
    printf("|%05d|\n", num);
    printf("|%05d|\n", -7);

    // width static
    printf("|%5d|\n", pos);
    printf("|%5d|\n", neg);

    // width dynamic '*'
    printf("|%*d|\n", largura, num);

    // precision static '.'
    printf("|%.5d|\n", cento_vinte_tres);
    printf("|%.2d|\n", cento_vinte_tres);
    printf("|%10.5d|\n", cento_vinte_tres);
    printf("|%.0d|\n", 0);
    printf("|%5.0d|\n", 0);

    // precision dynamic '.*'
    printf("|%.*d|\n", precisao, cento_vinte_tres);

    // length 'hh'
    printf("%hhd\n", sc);

    // length 'h'
    printf("%hd\n", si);

    // length 'l'
    printf("%ld\n", li);

    // length 'll'
    printf("%lld\n", lli);

    // length 'j'
    printf("%jd\n", im);

    // length 'z'
    printf("%zd\n", ssz);

    // length 't'
    printf("%td\n", diff);

    // locale flags '''
    setlocale(LC_NUMERIC, "pt_BR.UTF-8");
    printf("%'d\n", grande);

    // locale flags 'I'
    setlocale(LC_CTYPE, "fa_IR.UTF-8");
    printf("%Id\n", cento_vinte_tres);

    return 0;
}
