#include "ft_printf.h"

int		is_num(char c)
{
	if (c >= 48 && c < 58)
		return (1);
	return (0);
}

void	ft_check(const char *s, int *i)
{
	if (is_num(s[*i]))
	{
		flags.width = ft_atoi(s + (*i));
		*i += num(flags.width);
	}
	if (s[*i] == '.')
	{
		flags.p = 1;
		(*i)++;
	}
	if (is_num(s[*i]))
	{
		flags.prec = ft_atoi(s + (*i));
		*i += num(flags.prec);
	}
	if (s[*i] == 'd')
		print_int();
	else if (s[*i] == 's')
		print_str();
	else if (s[*i] == 'x')
		print_hex();
}

int		ft_printf(const char *s, ...)
{
	int		i;

	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		init_flags();
		if (s[i] == '%')
		{
			i++;
			ft_check(s, &i);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (g_count);
}

int		main(void)
{
	int i = printf("%4.3d\n", 1);
	int j = ft_printf("%4.3d\n", 1);

	printf("i = %d\tj = %d\n", i, j);
	return (0);
}
