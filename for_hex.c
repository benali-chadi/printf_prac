#include "ft_printf.h"

void    ft_puthex(unsigned int n)
{
    char *num;
    
    num = "0123456789abcdef";
    if (n < 16)
        ft_putchar(num[n]);
    else
    {
        ft_puthex(n / 16);
        ft_puthex(n % 16);
    }
}

void    print_hex()
{
    unsigned int x;
    int spaces;
    int preci;
    int i;

    x = va_arg(ap, unsigned int);
    preci = (flags.prec > num(x)) ? flags.prec - num(x) : 0;
    spaces = (preci > 0) ? flags.width - preci : flags.width - num(x);
    i = -1;
    while (++i < spaces)
        ft_putchar(' ');
    i = -1;
    while (++i < preci)
        ft_putchar('0');
    ft_puthex(x);
}