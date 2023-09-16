#include "main.h"

/**
* ft_put_str - print a string
* @str: string to print
* @len: length of the string
*/
void ft_put_str(char *str, int *len) {
	if (!str) str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

/**
* ft_printchar - print a character
* @c: character to print.
* @len: length of the character.
*/
void ft_printchar(char c, int *len) {
	*len += write(1, &c, 1);
}

/**
 * _print_number - Print an integer.
 * @nbr: The long to print.
 * @base: format that you want hexa or dicimal...
 * @len: the length of the number that you will print
 */
void _print_number(long nbr, int base, int *len) {
	unsigned int nb;

	if (nbr < 0) {
		ft_printchar('-', len);
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= (unsigned long)base)
		_print_number(nb / base, base, len);
	if (nb % base < 10)
		ft_printchar(nb % base + '0', len);
	else
		ft_printchar(nb % base - 10 + 'a', len);
}
