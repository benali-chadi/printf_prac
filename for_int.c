#include "ft_printf.h"

void    ft_putnbr(int n, int preci)
{
	unsigned int    ui;
	int             i;

	if (n < 0)
	{
		ft_putchar('-');
		i = -1;
		while (preci)
		{
			ft_putchar('0');
			preci--;
		}
		ui = -n;
	}
	else
		ui = n;
	while (preci)
	{
		ft_putchar('0');
		preci--;
	}
	if (ui < 10)
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

	d = va_arg(ap, int);
	signe = d < 0 ? 1 : 0;
	preci = (flags.prec > num(d)) ? flags.prec - num(d) : 0;
	spaces = (preci > 0) ? flags.width - (flags.prec + signe) : flags.width - (num(d) + signe);
	i = -1;
	while (++i < spaces)
		ft_putchar(' ');
	ft_putnbr(d, preci);
}