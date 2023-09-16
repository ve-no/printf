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
 * @nbr: The integer to print.
 * @base: format that you want hexa or dicimal...
 * @len: the length of the number that you will print
 */
void _print_number(int nbr, int base, int *len) {
	if (nbr < 0) {
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		_print_number((nbr / base), base, len);
	*len += write(1, &"0123456789abcdef"[nbr % base], 1);
}
