#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Entry point
 *
 * @format: format str
 *
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list el;
	int i, size = 0;
	char *str;

	va_start(el, format);
	for (i = 0; format && format[i]; i++)
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			size++;
		}
		else
		{
			switch (format[++i])
			{
				case 'c':
					_putchar(va_arg(el, int));
					size++;
					break;
				case 's':
					str = va_arg(el, char *);
					str == NULL ? str = "(null)" : str;
					size += write(1, str, _strlen(str));
					break;
				case '%':
					_putchar('%');
					size++;
					break;
				case '\0':
					continue;
				default:
					_putchar('%');
					size = size + _printf("%c", format[i]) + 1;
					break;
			}
		}
	if (size == 0)
		exit(99);
	return (size);
}
