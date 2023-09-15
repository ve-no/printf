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
			{
				int num = va_arg(args, int);
				len += _print_number(num);
			}
		}
		format++;
	}
	return (va_end(ptr), len);
}

/**
 * _print_number - Print an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_number(int n)
{
	int len = 0;
	if (len < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
		len += _print)number(n / 10);
	len += write(1, &((char[]{n % 10 + '0'}), 1);
	return (len);
}
