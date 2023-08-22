#include "main.h"

/**
 * _printf - printf function
 * @format: Format string
 * @...:arguments
 * Return: Number of characters printed or 0
 */
int _printf(const char *format, ...)
{
	int i, c, count = 0;
	va_list valist;
	char *s;
	void *pointer;
	unsigned int num;

	va_start(valist, format);
	if (!format)
	{
		return (-1);
	}
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else if (format[i + 1])
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(valist, int);
				putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(valist, char *);
				if (!s)
					s = "(null)";
				count += _printstring(s);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				num = va_arg(valist, int);
				count += print_number(num);
			}
			else if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else if (format[i] == 'b')
			{
				num = va_arg(valist, unsigned int);
				count += print_bi(num);
			}
			else if (format[i] == 'u')
			{
				num = va_arg(valist, unsigned int);
				count += print_unsig(num);
			}
			else if (format[i] == 'o')
			{
				num = va_arg(valist, unsigned int);
				count += print_octal(num);
			}
			else if (format[i] == 'x')
			{
				num = va_arg(valist, unsigned int);
				count += print_hexalow(num);
			}
			else if (format[i] == 'X')
			{
				num = va_arg(valist, unsigned int);
				count += print_hexaup(num);
			}
			else if (format[i] == 'S')
			{
				count += print_bigS(s);
			}
			else if (format[i] == 'p')
			{
				pointer = va_arg(valist, void *);
				count += putchar('0') + putchar('x');
				count += print_hl((uintptr_t)pointer);
			}
			else if (format[i] == 'r')
			{
				if (!s)
				{
					s = "(null)";
				}
				count += print_rev(s);
			}
			else
			{
				putchar('%');
				return (-1);
			}
		}
		else
		{
			putchar('%');
			return (-1);
		}
	}
	va_end(valist);
	return (count);
}
