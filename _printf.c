#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_print - function that handles printing different data types
 * @format: Pointer to the format
 * @i: the iterator for the format iteration
 * @el: list pointer
 * Return: the size
 */
int handle_print(const char *format, int *i, va_list *el)
{
	int size = 0;
	char *str;

	switch (format[++(*i)])
	{
		case 'c':
			_putchar(va_arg(*el, int));
			size++;
			break;
		case 's':
			str = va_arg(*el, char *);
			str == NULL ? str = "(null)" : str;
			size += write(1, str, _strlen(str));
			break;
		case '%':
			_putchar('%'), size++;
			break;
		case 'i':
		case 'd':
			str = itoa(va_arg(*el, int));
			size += write(1, str, _strlen(str));
			break;
		case '\0':
			(*i)--;
			break;
		default:
			_putchar('%');
			size = size + _printf("%c", format[*i]) + 1;
			break;
	}
	return (size);
}
/**
 * _printf - Entry point
 *
 * @format: format str
 *
 * Return: The size
 */
int _printf(const char *format, ...)
{
	va_list el;
	int i, size = 0;

	va_start(el, format);
	for (i = 0; format && format[i]; i++)
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			size++;
		}
		else
			size += handle_print(format, &i, &el);
	va_end(el);
	if (size == 0)
		return (-1);
	return (size);
}
