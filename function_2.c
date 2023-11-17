#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - printf function with limited functionality
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int conter = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
		format++;
		switch (*format)
		{
		case 's':
		{
		const char *str = va_arg(args, const char *);

		while (*str)
		{
		conter += write(1, str, 1);
		str++;
		}
		break;
		}
		case 'd':
		case 'i':
		{
		int num = va_arg(args, int);
		char buffer[12];
		int length = snprintf(buffer, sizeof(buffer), "%d", num);
		conter += write(1, buffer, length);
		break;
		}
		case '%':
		conter += write(1, "%", 1);
		break;
		conter += write(1, format, 1);
		break;
		}
		}
		else
		{
		conter += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (conter);
}
