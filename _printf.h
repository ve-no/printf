#pragma once

# include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);
void ft_put_str(char *str, int *len);
void ft_printchar(char c, int *len);
void _print_number(int nbr, int base, int *len);
