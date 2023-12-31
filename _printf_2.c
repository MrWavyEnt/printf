#include "main.h"
#include <stdarg.h>

/**
 * _printf_cov_spec - print cinversion specifiers d and i.
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed
 */

int _print_conv_spec(const char *format, ...)
{
	va_list args;
	int counter = 0;
	
	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0' || *format == ' ')
				return (-1);

			switch (*format )
			{
				case 's':
					counter += print_string(va_arg(args, char *));
					break;
				case '%':
					counter += _putchar('%');
					break;
				case 'c':
					counter += _putchar(va_arg(args, int));
					break;
				case 'd':
				case 'i':
					counter += _putchar(va_arg(args, int));
					break;
				default:
					counter += _putchar('%');
					counter += _putchar(*format);
					break;
			}
			format++;
		}
		else
		{
			counter += _putchar(*format);
			format++;
		}
	}
	va_end(args);
	return(counter);
}
