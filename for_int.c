#include "ft_printf.h"

void    ft_putnbr(int n, int preci)
{
    unsigned int    ui;
    int             i;

    if (n < 0 && !check)
    {
        ft_putchar('-');
        i = -1;
        while (++i < preci)
            ft_putchar('0');
        ui = -n;
        check++;
    }
    else
        ui = n;
    if (!check)
    {
        i = -1;
        while (++i < preci)
            ft_putchar('0');
        check++;
    }
    if (ui >= 0 && ui < 10)
        ft_putchar(ui + '0');
    else if (ui > 9)
    {
        ft_putnbr(ui / 10, preci);
        ft_putnbr(ui % 10, preci);
    }
}

void    print_int()
{
    int d;
    int i;
    int spaces;
    int preci;
    int signe;

    signe = 0;
    d = va_arg(ap, int);
    if (d < 0)
    {
        d = -d;
        signe = 1;
    }
    preci = (flags.prec > num(d)) ? flags.prec - num(d) : 0;
    spaces = (preci > 0) ? flags.width - preci : flags.width - num(d);
    i = -1;
    while (++i < spaces)
        ft_putchar(' ');
    ft_putnbr(d, preci);
}