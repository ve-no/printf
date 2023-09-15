#include "_printf.h"

void ft_put_str(char *str, int *len) {
	if (!str) str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void ft_printchar(char c, int *len) {
	*len += write(1, &c, 1);
}
