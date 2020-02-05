#include "ft_printf.h"

void    print_str()
{
    char    *str;
    int     spaces;
    int     preci;
    int     i;

    str = va_arg(ap, char*);
    preci = (flags.p && flags.prec < ft_strlen(str)) ? flags.prec : ft_strlen(str);
    spaces = flags.width - preci;
    i = 0;
    while (spaces > 0)
    {
        ft_putchar(' ');
        spaces--;
    }
    while (i < preci)
    {
        ft_putchar(str[i]);
        i++;
    }
}