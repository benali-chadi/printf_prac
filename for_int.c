#include "ft_printf.h"

void    ft_putnbr(int n, int preci)
{
	unsigned int    ui;
	int             i;

	// ui = -n;
	// if (n >= 0 && n < 10)
	//     ft_putchar(n + 48);
	// else if (n < 0 && n > -10)
	// {
	//     ft_putchar('-');
	//     ft_putchar(ui + 48);
	// }
	// else if (n > 9 || n < -9)
	// {
	//     ft_putnbr(n / 10, preci);
	//     if (n < -9)
	//         ft_putnbr(ui % 10, preci);
	//     else
	//         ft_putnbr(n % 10, preci);
	// }
	if (n < 0)
	{
		ft_putchar('-');
		i = -1;
		while (++i < preci)
			ft_putchar('0');
		ui = -n;
		// n = -n;
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

	signe = 0;
	d = va_arg(ap, int);
	preci = (flags.prec > num(d)) ? flags.prec - num(d) : 0;
	spaces = (preci > 0) ? flags.width - flags.prec : flags.width - num(d);
	i = -1;
	while (++i < spaces)
		ft_putchar(' ');
	ft_putnbr(d, preci);
}