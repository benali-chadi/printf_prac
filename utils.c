#include "ft_printf.h"

void init_flags()
{
    flags.width = 0;
    flags.prec = 0;
    flags.p = 0;
    check = 0;
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
    g_count++;
}

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     num(int n)
{
    int i;

    i = 0;
    if (n <= 0)
        i++;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

int     ft_atoi(const char *s)
{
    long num;

    num = 0;
    while (*s >= '0' && *s <= '9')
    {
        num = num * 10 + (*s - 48);
        s++;
    }
    return (num);
}