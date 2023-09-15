#include "_printf.h"

/**
* _printf - custom variadic printf function handling all the different data types and printing them out
* using standard i/o.
* @format: required data type to handle the provided data in the function.
*
* Return: integer value coresponding to the length of the variables.
*/
int _printf(const char *format, ...)
{
	int len;
	va_list ptr;

	len = 0;
	va_start(ptr, format);
	while (*format) {
		if (*format != '%')
			len += write(1, format, 1);
		else if ((*format == '%') && *(format + 1)) {
			format++;
			if (*format == 's')
				ft_put_str(va_arg(ptr, char *), &len);
			else if (*format == 'c')
				ft_printchar((char)va_arg(ptr, int), &len);
			else if (*format == 'd' || *format == 'i')
				 _print_number((long long)va_arg(ptr, int), 10, &len);
		}
		format++;
	}
	return (va_end(ptr), len);
}

/**
 * _print_number - Print an integer.
 * @nbr: The integer to print.
 * @base: format that you want hexa or dicimal...
 * @len: the length of the number that you will print
 */

void _print_number(long long nbr, int base, int *len) {
	if (nbr < 0) {
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		_print_number((nbr / base), base, len);
	*len += write(1, &"0123456789abcdef"[nbr % base], 1);
}
