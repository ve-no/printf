#include "main.h"

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
				 _print_number(va_arg(ptr, int), 10, &len);
			else if (*format == 'u')
				_print_number(va_arg(ptr, unsigned int), 10, &len);
			else if (*format == 'o')
				_print_number(va_arg(ptr, unsigned int), 8, &len);
			else if (*format == 'x')
				_print_number(va_arg(ptr, unsigned int), 16, &len);
			else if (*format == 'X')
				_print_number(va_arg(ptr, unsigned int), 16, &len);
			else if (*format == 'p') {
				len += write(1, "0x", 2);
				_print_number(va_arg(ptr, unsigned long int), 16, &len);
			}
			else if (*format == '%')
				len += write(1, "%", 1);
			else {
				len += write(1, "%", 1);
				len += write(1, format, 1);
			}
		}
		format++;
	}
	return (va_end(ptr), len);
}
