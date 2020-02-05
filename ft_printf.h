#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct  s_flags {
        int     width;
        int     prec;
        int     p;
}               t_flags;

int g_count;
int check;
va_list ap;
t_flags flags;

void    init_flags();
void    ft_putchar(char c);
int     ft_strlen(char *s);
int     num(int n);
int     ft_atoi(const char *s);
void    print_str();
void    print_hex();
void    print_int();

#endif