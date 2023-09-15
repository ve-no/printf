#include "_printf.h"
#include <stdarg.h>

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
		}
		format++;
	}
	return (va_end(ptr), len);
}
