#ifndef MAIN_H
#define MAIN_H

# include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>


int _printf(const char *format, ...);
void ft_put_str(char *str, int *len);
void ft_printchar(char c, int *len);
void _print_number(int nbr, int base, int *len);

#endif
