#include "libft/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

int    main(void)
{
    // flags "#0- +" are of C99 standard

    // # -- adding 0x / 0X prefixes
    printf("\ntest: %#x", 42);
    printf("\ntest: %#X", 42);
    printf("\ntest: %x", 42);
    printf("\ntest: %X", 42);
    // # -- edge case: zero value with '#' must not print 0x or 0X prefix
    printf("\ntest: %#x", 0);
    printf("\ntest: %#X", 0);

    // 0 -- left padding with zeros
    printf("\ntest: %03d", 42);
    printf("\ntest: %03d", 42);
    printf("\ntest: %010d", 42);
    printf("\ntest: %010i", 42);
    printf("\ntest: %010u", 42);
    printf("\ntest: %010x", 42);
    printf("\ntest: %010X", 42);
    
    // - -- left justification (reverse padding)
    printf("\ntest: %-10d", 42);

    // ' ' -- adding space to the left of positive numbers
    printf("\ntest: % 2d", 42);
    printf("\ntest: % 10d", 42);

    // + -- always force the display of the number sign
    printf("\ntest: %+d", -42);
    printf("\ntest: %+d", +42);


    // flag "'" is of POSIX
    // ' -- uses locale-specific thousands grouping separator
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

    // static field width
    printf("|%5d|\n", pos);
    printf("|%5d|\n", neg);

    // dynamic field width '*'
    printf("|%*d|\n", largura, num);

    // static precision '.'
    printf("|%.5d|\n", cento_vinte_tres);
    printf("|%.2d|\n", cento_vinte_tres);
    printf("|%10.5d|\n", cento_vinte_tres);
    printf("|%.0d|\n", 0);
    printf("|%5.0d|\n", 0);

    // dynamic precision '.*'
    printf("|%.*d|\n", precisao, cento_vinte_tres);

    // length modifier 'hh'
    // hh -- edge cases: testing signed char limits (overflow/underflow)
    signed char sc = 120;
    printf("%hhd\n", sc);
    printf("%hhd\n", (signed char)SCHAR_MAX);
    printf("%hhd\n", (signed char)SCHAR_MIN);

    // length modifier 'h'
    // h -- edge cases: short int limits
    short int si = 30000;
    printf("%hd\n", si);
    printf("%hd\n", (short int)SHRT_MAX);
    printf("%hd\n", (short int)SHRT_MIN);

    // length modifier 'l'
    // l -- edge cases: long int limits
    long int li = 1234567890L;
    printf("%ld\n", li);
    printf("%ld\n", LONG_MAX);
    printf("%ld\n", LONG_MIN);

    // length modifier 'll'
    // ll -- edge cases: long long int limits
    long long int lli = 987654321012345LL;
    printf("%lld\n", lli);
    printf("%lld\n", LLONG_MAX);
    printf("%lld\n", LLONG_MIN);

    // length modifier 'j'
    // j -- edge cases: intmax_t limits
    intmax_t im = 9223372036854775807LL;
    printf("%jd\n", im);
    printf("%jd\n", INTMAX_MAX);
    printf("%jd\n", INTMAX_MIN);

    // length modifier 'z'
    // z -- edge cases: ssize_t limits
    ssize_t ssz = 1024;
    printf("%zd\n", ssz);
    printf("%zd\n", SSIZE_MAX);

    // length modifier 't'
    // t -- edge cases: ptrdiff_t limits
    int arr[5];
    ptrdiff_t diff = &arr[4] - &arr[0];
    printf("%td\n", diff);
    printf("%td\n", PTRDIFF_MAX);
    printf("%td\n", PTRDIFF_MIN);

    // locale flags '''
    setlocale(LC_NUMERIC, "pt_BR.UTF-8");
    printf("%'d\n", grande);

    // locale flags 'I'
    setlocale(LC_CTYPE, "fa_IR.UTF-8");
    printf("%Id\n", cento_vinte_tres);


    // --- COMPLETION: CRITICAL CONFLICTS & EDGE CASES FOR %d ---

    // conflicts: '+' vs ' ' => '+' must override ' '
    printf("|%+ d|\n", pos);
    printf("|% +d|\n", pos);

    // conflicts: '-' vs '0' => '-' must override '0'
    printf("|%-08d|\n", pos);
    printf("|%0-8d|\n", pos);

    // conflicts: '0' vs '.' (precision) => '.' must override '0' for integers
    printf("|%010.5d|\n", pos);
    printf("|%010.5d|\n", neg);

    // complex combination: sign, width, and precision combined
    printf("|%+10.5d|\n", pos);
    printf("|%+10.5d|\n", neg);
    printf("|% 10.5d|\n", pos);
    printf("|%-+10.5d|\n", pos);

    // edge case: INT_MIN and INT_MAX (The most famous printf crashers)
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    printf("%+d\n", INT_MIN);
    printf("|%20d|\n", INT_MIN);
    printf("|%.20d|\n", INT_MIN);

    // edge case: dynamic precision with negative value (treated as if precision was omitted)
    printf("|%.*d|\n", -5, pos);

    // edge case: dynamic width with negative value (treated as '-' flag followed by positive width)
    printf("|%*d|\n", -10, pos);

    return 0;
}
